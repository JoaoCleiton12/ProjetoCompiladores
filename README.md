# Analisador Léxico e Sintático OntoUML

Analisador desenvolvido em **Flex e Bison (C++)** para processamento, classificação léxica e validação sintática de linguagens de modelagem conceitual baseadas em **OntoUML** (linguagem Tonto).

O projeto realiza a identificação de tokens, a validação de convenções rígidas de nomenclatura (Classes, Relações, Instâncias e Atributos), a extração de construtos sintáticos, gera estatísticas quantitativas (Tabela de Síntese) e cria um relatório com rastreamento por linha e log detalhado de erros.

---

## Sumário

- [Análise Sintática — Pacotes e Relações](#️-análise-sintática--módulo-de-pacotes-e-relações-joão)
- [Análise Sintática — Enum e Genset](#-análise-sintática--tópicos-4-e-5-enum-e-genset)
- [Regras de Identificação (Léxico)](#-estrutura-das-regras-de-identificação-léxico)
- [Como Compilar e Executar](#️-como-compilar-e-executar)
- [Alterando o Arquivo de Entrada](#️-alterando-o-arquivo-de-entrada-de-teste)
- [Relatório de Saída](#-relatório-de-saída-outputsaidatxt)
- [Teste de Tratamento de Erros](#-teste-de-tratamento-de-erros-teste_errostxt)

---

## Análise Sintática — Módulo de Pacotes e Relações

Este módulo é responsável por identificar, validar e extrair as declarações estruturais de **Pacotes** e **Relações (Internas e Externas)** da linguagem Tonto, ignorando de forma segura os demais construtos da linguagem.

### Estratégias e Soluções Técnicas

#### 1. Identificação Sintática de Relações (Bison)

A extração das relações foi modelada por meio de produções gramaticais. Para manter as regras concisas, a multiplicidade foi abstraída no não-terminal `cardinalidade`, que aceita de forma flexível as diversas variações numéricas da linguagem:

```yacc
cardinalidade:
    SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL                                        // Ex: [1]
    | SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL                            // Ex: [*]
    | SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL    // Ex: [1..*]
    | SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL NUMERO SIMBOLO_ESPECIAL              // Ex: [0..5]
    | SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL SIMBOLO_ESPECIAL // Ex: [*..*]
    ;
```

**Relações Externas:** declaradas de forma global, possuem uma assinatura léxica rigorosa. A regra exige o casamento exato da sequência envolvendo o estereótipo, as classes, as cardinalidades e o conector. O nome da relação é extraído no meio da declaração (referenciado por `$7`):

```yacc
declaracao_relacao_externa:
    SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO RELATION CLASSE cardinalidade SIMBOLO_ESPECIAL RELACOES SIMBOLO_ESPECIAL cardinalidade CLASSE {
        inserir_simbolo($7, "Relação Externa", yylineno);
    }
    ;
```

**Relações Internas:** declaradas de forma aninhada nas propriedades de uma classe. Como a linguagem omite um nome explícito nesse contexto, o analisador sintetiza um identificador único em tempo de execução, concatenando o prefixo `"Interna_"`, o estereótipo reconhecido, o nome da classe alvo e a linha da declaração (ex: `Interna_mediation_para_Pizza_L119`):

```yacc
declaracao_relacao_interna:
    SIMBOLO_ESPECIAL ESTEREOTIPO_RELACAO cardinalidade SIMBOLO_ESPECIAL cardinalidade CLASSE {
        string identificador = string("Interna_") + $2 + "_para_" + $6 + "_L" + to_string(yylineno);
        inserir_simbolo(identificador, "Relação Interna", yylineno);
    }
    ;
```

#### 2. Tabela de Símbolos (Hash Table)

Atendendo aos requisitos de estrutura de dados, os elementos são armazenados em uma Tabela de Dispersão (`unordered_map`). A estratégia de anexar a linha ao identificador único das relações internas foi essencial para evitar a sobrescrita de chaves duplicadas na Hash Table, garantindo o armazenamento integral de todas as ocorrências do arquivo.

#### 3. Recuperação de Erros ("Aspirador de Pó")

Para lidar com o desenvolvimento modular em equipe, foi criada a técnica do **"Aspirador de Pó"** (`token_invalido`). Essa regra captura silenciosamente palavras reservadas e classes que pertencem aos escopos de outros membros. Em conjunto com a regra de falha (`error { yyerrok; }`), o Bison descarta blocos desconhecidos e continua a varredura das relações, sem disparar loops infinitos de erro sintático e sem poluir o terminal.

#### 4. Ordenação da Saída

Embora a Hash Table embaralhe os dados por natureza, o relatório final transfere os dados para um vetor dinâmico e os ordena (via `<algorithm>`) por Categoria e por número da Linha. Isso gera um arquivo `output/saida.txt` agrupado e organizado, acompanhado da Tabela de Síntese contabilizada.

---

## Análise Sintática — Tópicos 4 e 5 (enum e genset)

Declarações de classes enumeradas e *generalization sets* são reconhecidas pelo parser Bison, com tabela de síntese e relatório de erros com sugestões. A documentação completa (gramática BNF, erros tratados e alterações nos arquivos compartilhados) está em [`docs/TOPICOS_4_5_ENUM_GENSET.md`](docs/TOPICOS_4_5_ENUM_GENSET.md).

```tonto
enum EyeColor { Blue, Green, Brown, Black }

disjoint complete genset PersonAgeGroup where Child, Adult specializes Person

genset PersonAgeGroup {
    general Person
    specifics Child, Adult
}
```

> **Requisitos:** Bison 3.6+ e Flex 2.6+.

---

## Estrutura das Regras de Identificação (Léxico)

O analisador utiliza expressões regulares personalizadas no Flex para categorizar e validar cada token da linguagem:

| Categoria | Regra |
|---|---|
| **Classes** | Iniciam obrigatoriamente com letra maiúscula (`PascalCase`), podendo conter sublinhados seguidos de novos blocos iniciados por maiúscula. |
| **Nomes de Relações** | Identificadores que iniciam com letra minúscula. Não há mais exigência dos prefixos `has`/`is`. |
| **Instâncias** | Aceitam letras e sublinhados, mas devem terminar obrigatoriamente com um ou mais números inteiros. |
| **Identificadores de Atributo** | Nomes iniciados por letra minúscula (`camelCase`), identificados contextualmente pela presença do delimitador de dois pontos (`:`) à sua direita. |
| **Tipos de Dados do Usuário** | Tipos customizados que devem obrigatoriamente terminar com o sufixo exato `DataType`. |
| **Estereótipos e Palavras Reservadas** | Palavras-chave da linguagem (ex: `kind`, `role`, `material`, `package`, `genset`, etc). |
| **Símbolos Especiais** | Delimitadores, operadores de cardinalidade e conectores OntoUML (`{`, `}`, `[`, `]`, `..`, `<>--`, `--<>`, `--`, `@`, etc). |

---

## Como Compilar e Executar

### Pré-requisitos

- **Flex** (`2.6.4` ou superior, com suporte a C++)
- **Bison** (`3.6` ou superior)
- **Compilador C++** (`g++` com suporte a C++11 ou superior)
- **Make** ou **CMake**

### 1. Clonar o Repositório

```bash
git clone https://github.com/JoaoCleiton12/ProjetoCompiladores.git
cd ProjetoCompiladores
```

### 2. Opções de Compilação e Execução

Escolha uma das opções abaixo para compilar e executar o projeto.

#### Opção A: Via CMake

Ideal para compilação isolada na pasta `build/` (ou pelo atalho `Ctrl + Shift + B` no VS Code).

- **Compilar:** `Ctrl + Shift + B`
- **Executar** (a partir da raiz do projeto):

```bash
./build/sintatico input/teste1.txt
```

#### Opção B: Via Makefile

A forma mais simples e direta. Compila os arquivos diretamente na raiz do projeto.

- **Compilar:**

```bash
make
```

- **Executar** (o arquivo de entrada pode ser passado como argumento):

```bash
./sintatico input/teste1.txt
```

- **Executar testes específicos de Enum/Genset:**

```bash
./sintatico input/teste_enum_genset.txt          # casos válidos
./sintatico input/teste_erros_enum_genset.txt    # um caso para cada erro tratado
```

- **Limpar arquivos compilados:**

```bash
make clean
```

---

## Alterando o Arquivo de Entrada de Teste

O programa utiliza `input/teste1.txt` como padrão, mas você pode passar qualquer arquivo via argumento no terminal (`./sintatico caminho/do/arquivo.txt`).

Caso queira alterar o arquivo padrão fixo no código:

1. **Adicione o arquivo de teste:** coloque o seu novo arquivo de texto (`.txt`) dentro do diretório `input/`.
2. **Altere o caminho no `main.cpp`:** atualize a variável `caminho_entrada`:

```cpp
string caminho_entrada = "input/meu_teste.txt";
```

3. **Recompile e execute:** salve as alterações e rode `make && ./sintatico`.

---

## Relatório de Saída (`output/saida.txt`)

O resultado do processamento é salvo automaticamente no arquivo `output/saida.txt`, estruturado em três seções principais:

1. **Tabela de Símbolos:** listagem detalhada de todos os construtos estruturais capturados, ordenados por Categoria e Linha.
2. **Tabela de Síntese:** resumo quantitativo com o total de ocorrências contabilizadas (Pacotes, Relações Internas, Relações Externas, Enums e Gensets).
3. **Tratamento de Erros:** registro contendo a linha, o erro sintático/léxico e a descrição ou sugestão de correção.

---

## Teste de Tratamento de Erros (`teste_erros.txt`)

Para validar a seção *Tratamento de Erros* do relatório, o repositório inclui o arquivo `input/teste_erros.txt`, que cobre:

- **Nome de Classe inválido:** classes iniciadas com letra minúscula (ex: `carroEletrico`, `veiculo`).
- **Tipo de Dado mal formado:** sufixo `datatype` sem a capitalização exigida (`DataType`).
- **Tokens inválidos genéricos:** símbolos não previstos pela gramática (ex: `#`, `&`, `~`).
- **Múltiplos erros na mesma linha:** a recuperação de erro trata cada ocorrência de forma independente.

Para rodar este teste, execute no terminal:

```bash
./sintatico input/teste_erros.txt
```
