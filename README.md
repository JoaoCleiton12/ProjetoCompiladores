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
  * **Regra:** Identificadores de relação que devem obrigatoriamente iniciar com os prefixos minúsculos `has` ou `is` (`(has|is)(...)`).
  * **Exemplos válidos:** `has_Massa`, `is_Consultado_Por`, `hasAnotacao`, `is_Atendido_Por`.
* **Instâncias:**
  * **Regra:** Iniciam com qualquer letra (maiúscula ou minúscula), aceitam sublinhados como separadores internos e **devem terminar obrigatoriamente com um ou mais números inteiros** (`{letras}+(_{letras}+)*{digitos}+`).
  * **Exemplos válidos:** `Clinico_Geral01`, `Chocolate01`, `pizza03`, `A_Plus01`.
* **Identificadores de Atributo:**
  * **Regra:** Nomes de propriedades/variáveis iniciados por letra minúscula (`camelCase`), identificados contextualmente pela presença do delimitador de dois pontos (`:`) à sua direita (`{id_atributo}/[ \t]*":"`).
  * **Exemplos válidos:** `nome :`, `cpf :`, `tipoDeVacina :`, `data_nascimento :`.
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
  * **Regra:** Delimitadores, operadores de cardinalidade e conectores OntoUML (`{`, `}`, `(`, `)`, `[`, `]`, `..`, `<>--`, `--<>`, `*`, `@`, `:`, `--`, `,`).
---
 
## Como Compilar e Executar
 
### Pré-requisitos
* **Flex** (`2.6.4` ou superior com suporte a C++)
* **Compilador C++** (`g++` com suporte a C++11 ou superior)
* **CMake** ou **Make**
---
 
### Passo a Passo
 
1. **Clonar o Repositório**
```bash
   git clone [https://github.com/JoaoCleiton12/ProjetoCompiladores.git](https://github.com/JoaoCleiton12/ProjetoCompiladores.git)
   cd ProjetoCompiladores
```
 
2. **Criar a Estrutura de Diretórios e Arquivo de Entrada**
   Certifique-se de que as pastas `input/` e `output/` existem na raiz do projeto e que o código a ser analisado seja inserido em um **arquivo de texto do tipo `.txt`** (ex: `input/teste2.txt`).
3. **Adicionar o Arquivo de Teste**
   Insira o código-fonte da linguagem de modelagem em formato de texto no arquivo:
   `input/teste2.txt`
4. **Compilar o Projeto**
   Utilize o atalho do VS Code para disparar a build configurada via CMake:
   `Ctrl` + `Shift` + `B`
5. **Executar**
   Execute o binário gerado na pasta de compilação:
```bash
   ./build/classes
```
 
6. **Consultar o Relatório Gerado**
   O resultado do processamento estará disponível no arquivo:
   `output/saida.txt`
---
 
## Relatório de Saída (`output/saida.txt`)
 
O arquivo de saída gerado pelo C++ é estruturado em três seções principais:
 
1. **Visão Analítica:** Listagem detalhada dos tokens capturados por ordem de categoria, com seus respectivos lexemas e números de linha (ex: `Identificador de Atributo: nome [Linha: 5]`).
2. **Tabela de Síntese:** Resumo quantitativo que exibe o total de ocorrências contabilizadas para cada categoria de token.
3. **Tratamento de Erros:** Registro completo contendo a linha, o lexema inválido e a descrição legível de erros léxicos encontrados (como nomes de classe iniciados em minúscula ou sufixos de tipos de dados incorretos).
