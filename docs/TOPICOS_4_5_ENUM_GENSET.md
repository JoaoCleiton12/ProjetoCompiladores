# Analisador Sintático TONTO — Tópicos 4 e 5

**Classes enumeradas (`enum`) e Generalizações (`genset`)**

Esta parte do analisador sintático reconhece, valida e resume as declarações de
classes enumeradas e de conjuntos de generalização (*generalization sets*) da
linguagem TONTO, integrada ao analisador léxico (Flex) da 1ª unidade e ao parser
Bison do grupo.

---

## 1. Construções reconhecidas

### 4. Classes enumeradas

```tonto
enum EyeColor { Blue, Green, Brown, Black }          // exemplo do enunciado

enum Tipo_De_Vacina {                                 // literais no formato de instância
    Covid01,
    FebreAmarela02
}

enum PlanetaRochoso specializes Planeta { Terra3 }    // forma do Tonto (monografia, Apêndice A)
```

Os literais aceitam **as duas convenções** citadas no enunciado: nome de classe
(`Blue`) e nome de instância do analisador léxico, terminando em número (`Covid01`).

### 5. Generalization sets

```tonto
// forma curta
disjoint complete genset PersonAgeGroup where Child, Adult specializes Person

// forma em bloco
genset PersonAgeGroup {
    general Person
    specifics Child, Adult
}

// com categorizador (Tonto / ML2)
disjoint complete genset PhasesOfPerson {
    general Person
    categorizer PersonTypeByAge
    specifics Child, Teenager, Adult
}
```

Restrições (opcionais, nesta ordem): `[disjoint | overlapping] [complete | incomplete]`.

---

## 2. Gramática (BNF)

```bnf
<declaracao_enum>     ::= "enum" <nome_enum> [ "specializes" <ref_classe> { "," <ref_classe> } ]
                          "{" [ <lista_literais> ] "}"
<lista_literais>      ::= <literal> { "," <literal> }
<literal>             ::= CLASSE | INSTANCIA
<nome_enum>           ::= CLASSE

<declaracao_genset>   ::= <modificadores> "genset" <nome_genset> <resto_genset>
<modificadores>       ::= [ "disjoint" | "overlapping" ] [ "complete" | "incomplete" ]
<nome_genset>         ::= CLASSE
<resto_genset>        ::= "{" "general" <ref_classe>
                              [ "categorizer" <ref_classe> ]
                              "specifics" <lista_classes> "}"
                        | "where" <lista_classes> "specializes" <ref_classe>
<lista_classes>       ::= <ref_classe> { "," <ref_classe> }
<ref_classe>          ::= CLASSE
```

`CLASSE` e `INSTANCIA` são os tokens do analisador léxico (convenções do professor).
No `parser.y`, a gramática tem ainda **produções de erro**: alternativas que aceitam
formas erradas comuns (nome minúsculo, vírgula faltando ou sobrando, cláusulas fora
de ordem etc.) só para emitir uma mensagem específica com sugestão e continuar a análise.

O Bison faz análise **ascendente (LALR(1))**. As regras de enum/genset não acrescentam
nenhum conflito à gramática: as ambiguidades criadas pelo "aspirador" `token_invalido`
(que aceita quase qualquer token depois de uma declaração) são resolvidas explicitamente
com `%precedence REDUZ_INCOMPLETO`, sempre a favor de continuar o enum/genset. Os 5
conflitos *shift/reduce* restantes são das regras de pacote, relação e cardinalidade.

---

## 3. Verificações e mensagens de erro

| Construto | Situação | Tipo |
|---|---|---|
| enum | nome minúsculo, com números, com sufixo `DataType`, com caracteres inválidos, ou ausente | erro |
| enum | literal minúsculo, só número, com hífen/caractere inválido | erro |
| enum | vírgula faltando entre literais / sobrando antes de `}` / `;` usado como separador | erro |
| enum | literal repetido; palavra reservada usada como literal | erro |
| enum | `specializes` sem tipo; bloco não fechado com `}` | erro |
| enum | nome repetido (outro enum/genset/símbolo) | erro |
| enum | enum vazio ou com um único literal | aviso |
| genset | `disjoint` + `overlapping`, `complete` + `incomplete`, restrição repetida | erro |
| genset | ordem invertida (`complete disjoint genset`) | erro |
| genset | sem nome; nome repetido; nome com caracteres inválidos | erro |
| genset | `specifics` antes de `general`; falta `general` ou `specifics`; corpo vazio | erro |
| genset | forma curta sem `specializes` ou sem a classe geral | erro |
| genset | vírgula faltando/sobrando na lista; classe listada duas vezes | erro |
| genset | classe geral também listada como específica (auto-especialização) | erro |
| genset | categorizador igual à classe geral ou listado em `specifics` | erro |
| genset | referência a classe com nome inválido (minúscula, número, hífen, `_` no fim) | erro |
| genset | enum usado como classe geral/específica | erro |
| genset | classe referenciada não declarada / declarada depois do genset (*) | erro / aviso |
| genset | nome em minúsculas ou que imita restrições (`genset disjoint_complete`) | aviso |
| genset | apenas uma classe específica; genset duplicado (mesma geral e específicas) | aviso |

(*) Essa verificação liga sozinha quando a declaração de classes (tópico 2) registrar
as classes na tabela de símbolos com categoria iniciada por `"Classe"`, por exemplo
`inserir_simbolo(nome, "Classe (kind)", @2.first_line);`.

Os erros de sintaxe que não têm produção específica passam por `yyreport_syntax_error`,
que informa linha, coluna, o token encontrado, **a lista exata de tokens esperados**
(com LAC) e uma sugestão de acordo com o contexto (dentro de um enum, dentro de um
genset, restrições soltas, bloco não fechado…).

A recuperação de erros sincroniza em `}` ou no início da próxima declaração, de modo
que um erro num enum/genset não apaga as declarações seguintes.

---

## 4. Saída

Tudo é gravado em `output/saida.txt`, junto com a tabela de símbolos do grupo
(que agora também lista os símbolos `Enum` e `Genset`, e a tabela de síntese inclui
"Total de Enums" e "Total de Gensets"). Depois dela vêm:

1. **Síntese de enums**: total, total de literais e uma tabela com nome, pacote,
   linha, tipo especializado, quantidade e lista de literais e status (ok / N erro(s)).
2. **Síntese de gensets**: total (forma curta × bloco) e uma tabela com nome, pacote,
   linha, forma, restrições, classe geral, categorizador, classes específicas e status;
   contagem por restrição; a **taxonomia** derivada (classe-mãe → filhas);
   enums e gensets **por pacote**.
3. **Relatório de erros da ontologia**: cada problema com severidade, linha, coluna,
   construto, descrição e **sugestão de tratamento**, em ordem de linha.

No terminal, o programa mostra o total de erros e avisos do relatório.

---

## 5. Arquivos

| Arquivo | Papel |
|---|---|
| `parser.y` | regras dos tópicos 4 e 5 (seções marcadas) e `yyreport_syntax_error` |
| `enum_genset.h/.cpp` | estruturas, verificações semânticas e tabela de síntese |
| `relatorio_erros.h/.cpp` | relatório de erros com sugestões (o grupo todo pode usar) |
| `classes.l` | ajustes no léxico necessários para a integração (abaixo) |
| `input/teste_enum_genset.txt` | casos válidos (exemplos do enunciado e da monografia) |
| `input/teste_erros_enum_genset.txt` | um caso para cada erro tratado |

### Alterações em arquivos compartilhados (marcadas com `[Tópicos 4/5]`)

* **classes.l**
  * tokens próprios para `enum genset disjoint overlapping complete incomplete general
    specifics categorizer where specializes` e para `{ } ,` (antes eram todos
    `PALAVRA_RESERVADA` / `SIMBOLO_ESPECIAL`, e o parser não tinha como diferenciá-los);
  * `overlapping`, `incomplete` e `categorizer` não existiam no léxico;
  * regra de **nome de classe** ajustada à convenção do enunciado da 1ª unidade
    (maiúscula + letras, sublinhado como subcadeia própria): antes `Massa_Fina_e_Crocante`
    e `Tipos_de_Clientes`, que aparecem nos testes do professor, viravam token inválido;
  * comentários `//` e `/* */` são ignorados (os testes do professor têm comentários);
  * linha e coluna de cada token em `yylloc`;
  * `INVALIDO` passa o lexema para o parser, e caracteres soltos (ex.: `.`) viram `INVALIDO`
    em vez de serem impressos pelo Flex.
* **parser.y**
  * `%locations`, `parse.error custom`, `parse.lac full`, `lr.default-reduction consistent`;
  * `corpo_programa` virou lista não-vazia (mesma linguagem), para a recuperação de erro
    funcionar já no primeiro elemento do arquivo;
  * `token_invalido` também absorve `specializes`, `{`, `}`, `,`, `general`, `specifics`,
    `categorizer` e `where` (antes eles chegavam como `PALAVRA_RESERVADA`/`SIMBOLO_ESPECIAL`
    e já eram absorvidos); `enum`, `genset` e as restrições ficam de fora porque iniciam
    as declarações dos tópicos 4 e 5;
  * a regra `elemento: error` chama `enum_genset_recuperar_erro()`;
  * a regra de pacote chama `definir_pacote_atual($2)`;
  * `yyerror` passou a registrar no relatório.
* **main.cpp**: conta enums e gensets na tabela de síntese e grava a síntese detalhada e o
  relatório de erros em `output/saida.txt`; no terminal mostra o total de erros/avisos.
* **Makefile / CMakeLists.txt**: compilam os novos `.cpp`; o CMake agora também roda o Bison.

### Observações para o grupo (fora do escopo dos tópicos 4 e 5)

* `subkind` não está no léxico (só `subKind`), mas é a forma usada nos testes e na monografia.
* Relação interna sem a primeira cardinalidade (ex.: `-- involvesRental -- [1] RentalCar`,
  em `carRental.tonto`) não é aceita pela regra de relações e aparece no relatório de erros.
* As regras usam `yylineno`, que já aponta para o token seguinte; `@n.first_line` dá a linha exata.
* Com tokens próprios para `{ } ,`, as declarações de classe/datatype devem usar
  `ABRE_CHAVE`, `FECHA_CHAVE` e `VIRGULA`; `specializes` agora é `SPECIALIZES`.
