# Analisador Léxico OntoUML

Analisador léxico desenvolvido em **Flex (C++)** para processamento, classificação e validação léxica de linguagens de modelagem conceitual baseadas em **OntoUML**.

O projeto realiza a identificação de tokens, validação de convenções rígidas de nomenclatura (Classes, Relações, Instâncias e Atributos), gera estatísticas quantitativas e cria um relatório com rastreamento por linha e log detalhado de erros léxicos.

---

## Estrutura das Regras de Identificação

O analisador utiliza expressões regulares personalizadas no Flex para categorizar e validar cada token da linguagem:

* **Classes:**
  * **Regra:** Devem iniciar obrigatoriamente com letra maiúscula (`PascalCase`), podendo conter sublinhados seguidos de novos blocos iniciados por maiúscula (`{segmento}(_{segmento})*`).
  * **Exemplos válidos:** `Pessoa`, `Unidade_Basica_De_Saude`, `Pizza`.
* **Nomes de Relações:**
  * **Regra:** Identificadores que devem iniciar obrigatoriamente com letra minúscula, podendo conter letras adicionais (de qualquer caixa) e blocos separados por sublinhado, desde que cada bloco também comece com letra (`{letra_minuscula}{letras}*(_{letras}+)*`). **Não há mais exigência dos prefixos `has`/`is`** — qualquer identificador nesse formato que não seja seguido de `:` (o que o classificaria como Atributo) é tratado como Relação.
  * **Exemplos válidos:** `has_Massa`, `is_Consultado_Por`, `hasAnotacao`, `is_Atendido_Por`, `pertenceA`, `trabalhaEm`.
* **Instâncias:**
  * **Regra:** Iniciam com qualquer letra (maiúscula ou minúscula), aceitam sublinhados como separadores internos e **devem terminar obrigatoriamente com um ou mais números inteiros** (`{letras}+(_{letras}+)*{digitos}+`).
  * **Exemplos válidos:** `Clinico_Geral01`, `Chocolate01`, `pizza03`, `A_Plus01`.
* **Identificadores de Atributo:**
  * **Regra:** Nomes de propriedades/variáveis iniciados por letra minúscula (`camelCase`), podendo conter letras e números em seguida, identificados contextualmente pela presença do delimitador de dois pontos (`:`) à sua direita (`{letra_minuscula}{alfanumerico}*/[ \t]*":"`).
  * **Exemplos válidos:** `nome :`, `cpf :`, `tipoDeVacina :`, `endereco2 :`.
* **Tipos de Dados Criados pelo Usuário:**
  * **Regra:** Tipos customizados declarados que devem obrigatoriamente terminar com o sufixo exato `DataType` (`{letras}*"DataType"`).
  * **Exemplos válidos:** `TipoDeVacinaDataType`, `EnderecoDataType`.
* **Estereótipos e Palavras Reservadas:**
  * **Estereótipos de Classe:** `kind`, `quantity`, `collective`, `subKind`, `role`, `phase`, `relator`, `category`, `mixin`, `roleMixin`, `event`, `process`, `situation`, etc.
  * **Estereótipos de Relação:** `material`, `mediation`, `componentOf`, `memberOf`, `characterization`, `derivation`, `composition`, `aggregation`, etc.
  * **Palavras Reservadas:** `package`, `relation`, `specializes`, `genset`, `disjoint`, `complete`, `general`, `specifics`, `datatype`, `enum`, `import`, `where`, `functional-complexes`.
  * **Tipos Nativos:** `string`, `number`, `boolean`, `date`, `time`, `datetime`.
  * **Meta-atributos:** `ordered`, `const`, `derived`, `subsets`, `redefines`.
* **Símbolos Especiais:**
  * **Regra:** Delimitadores, operadores de cardinalidade e conectores OntoUML (`{`, `}`, `(`, `)`, `[`, `]`, `..`, `<>--`, `--<>`, `<>`, `*`, `@`, `:`, `--`, `,`).

---

## 🛠️ Como Compilar e Executar

### Pré-requisitos
* **Flex** (`2.6.4` ou superior com suporte a C++)
* **Compilador C++** (`g++` com suporte a C++11 ou superior)
* **Make** ou **CMake**

---

### 1. Clonar o Repositório
```bash
git clone https://github.com/JoaoCleiton12/ProjetoCompiladores.git
cd ProjetoCompiladores
```

---

### 2. Opções de Compilação e Execução

Escolha uma das opções abaixo para compilar e executar o projeto conforme as ferramentas disponíveis no seu ambiente:

#### Opção A: Via `CMake` (Recomendado)

Ideal para compilação isolada na pasta `build/` (ou pelo atalho `Ctrl + Shift + B` no VS Code).


* **Compilar:**
```bash
Ctrl + Shift + B
```

* **Outra opção de Compilar:**
```bash
mkdir -p build && cd build
cmake ..
make
```

* **Executar (a partir da raiz do projeto):**
```bash
./build/classes
```

#### Opção B: Via `Makefile`

A forma mais simples e direta. Compila os arquivos diretamente na raiz do projeto.

* **Compilar:**
```bash
make
```

* **Executar:**
```bash
./classes
```

* **Limpar arquivos compilados:**
```bash
make clean
```

#### Opção C: Compilação Manual (Sem Make/CMake)

Caso a sua máquina não possua utilitários de build instalados:

1. **Gerar o arquivo C++ do lexer:**
```bash
flex -o lex.yy.cc classes.l
```

2. **Compilar o executável com o `g++`:**
```bash
g++ -std=c++11 -Wall lex.yy.cc main.cpp -o classes
```

3. **Executar:**
```bash
./classes
```

---

## ⚙️ Alterando o Arquivo de Entrada de Teste

O programa utiliza caminhos de arquivos configurados internamente. Para alterar qual arquivo de teste será processado pelo analisador, siga os passos:

1. **Adicione o arquivo de teste:**
   Coloque o seu novo arquivo de texto (`.txt`) dentro do diretório `input/` (ex: `input/meu_teste.txt`).

2. **Altere o caminho no `main.cpp`:**
   Abra o arquivo `main.cpp` e atualize a variável `caminho_entrada` com o nome do novo arquivo:
```cpp
string caminho_entrada = "input/meu_teste.txt";
```

3. **Recompile e execute:**
   Salve as alterações, recompile o projeto e execute novamente:
```bash
make
./classes
```

---

## 📄 Relatório de Saída (`output/saida.txt`)

O resultado do processamento é salvo automaticamente no arquivo `output/saida.txt`, estruturado em três seções principais:

1. **Visão Analítica:** Listagem detalhada de todos os tokens capturados por ordem de categoria, informando o lexema e a linha correspondente.
2. **Tabela de Síntese:** Resumo quantitativo que exibe o total de ocorrências contabilizadas para cada categoria de token.
3. **Tratamento de Erros:** Registro contendo a linha, o lexema inválido e a descrição/sugestão de correção para cada erro léxico encontrado.

---

## 🧪 Teste de Tratamento de Erros (`teste_erros.txt`)

Para validar a seção **Tratamento de Erros** do relatório, o repositório inclui o arquivo `input/teste_erros.txt`, que cobre:

* **Nome de Classe inválido:** Classes iniciadas com letra minúscula (ex: `carroEletrico`, `veiculo`).
* **Tipo de Dado mal formado:** Sufixo `datatype` sem a capitalização exigida (`DataType`), como em `EnderecoDatatype` ou `telefonedatatype`.
* **Tokens inválidos genéricos:** Símbolos não previstos pela gramática (ex: `#`, `&`, `~`).
* **Múltiplos erros na mesma linha:** Para garantir que a recuperação de erro trate cada ocorrência de forma independente.

Para rodar este teste, altere a variável `caminho_entrada` em `main.cpp` para `"input/teste_erros.txt"`, recompile e execute.

📌 **Créditos das Entradas:** Os arquivos `teste1.txt` e `teste2.txt` foram retirados do repositório [Compiladores-UFERSA](https://github.com/):
* `teste1.txt`: Pizzaria_MONO.tonto
* `teste2.txt`: Hospital.tonto
