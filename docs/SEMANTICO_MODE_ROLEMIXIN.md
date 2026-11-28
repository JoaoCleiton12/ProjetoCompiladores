# Analisador Semântico TONTO — Mode pattern e RoleMixin pattern

Esta parte do analisador semântico valida dois padrões de projeto de ontologias
(ODPs) do enunciado: **5. Mode pattern** e **6. RoleMixin pattern**.

A análise acontece **depois** da análise sintática: o parser monta a tabela de
símbolos (classes com seus estereótipos e especializações, gensets e relações
internas) e, com o arquivo inteiro lido, o analisador semântico faz verificações
estáticas sobre ela.

---

## 1. Conceitos usados (slide "Análise Semântica")

| Conceito do slide | Como aparece nos padrões |
|---|---|
| **Verificação estática / verificação de tipos**: o tipo esperado por uma construção deve casar com o tipo recebido | O "tipo" de uma classe é o seu **estereótipo** (`kind`, `role`, `mode`, `roleMixin`...). Ex.: as `specifics` de um genset de roleMixin esperam o tipo `role`; se recebem um `subkind`, o padrão fica incompleto. |
| **Sobrecarga**: o significado de um operador é decidido pelos tipos conhecidos dos operandos | A mesma construção significa padrões diferentes conforme os tipos envolvidos. Um `genset` com `general` do tipo `roleMixin` é o padrão RoleMixin. As relações `@characterization`/`@externalDependence` indicam o padrão Mode. É assim que o analisador **identifica os padrões incompletos**: pelo tipo dos operandos, mesmo quando falta alguma parte. |
| **Coerção**: a linguagem especifica as conversões permitidas, e o verificador insere a conversão (ex.: `2 * 3.14`, o inteiro vira ponto flutuante) | Quando o tipo ou valor recebido não é o esperado, mas existe uma **conversão permitida**, o analisador converte, segue a análise e registra a correção no relatório de erros como `[COERÇÃO]`. |

---

## 2. Mode pattern

Modelo do enunciado:

```tonto
kind ClassName1
kind ClassName2

mode Mode_Name1 {
    @characterization [1..*] -- [1] ClassName1
    @externalDependence [1..*] -- [1] ClassName2
}
```

- `@characterization`: liga o mode ao seu **portador**. Pelo slide de ODPs, o mode inere em exatamente **um** portador (`1`).
- `@externalDependence`: classe da qual o mode **depende externamente**, com cardinalidade mínima ≥ 1.

### Como o padrão é identificado
- toda classe declarada com o estereótipo `mode`;
- **por sobrecarga**, uma classe de outro tipo que contém `@characterization` ou `@externalDependence`. Essas relações são do padrão Mode, então indicam uma tentativa incompleta dele. A exceção é `quality`, que também usa `@characterization`.

### Padrão incompleto quando
| Situação | Exemplo |
|---|---|
| a classe não é do tipo `mode` (ex.: `kind`; não há conversão de kind para mode) | `kind Commitment { @characterization ... }` |
| nenhuma `@characterization` | `mode Headache` |
| mais de uma `@characterization` (um mode inere em um único portador) | |
| nenhuma `@externalDependence` | `mode Skill { @characterization [1..*] -- [1] Person }` |
| a classe portadora ou a de dependência externa não foi declarada | `@characterization [1..*] -- [1] Animal` |

---

## 3. RoleMixin pattern

Modelo do enunciado:

```tonto
kind ClassName1
kind ClassName2

roleMixin RoleMixin_Name

role Role_Name1 specializes ClassName1, RoleMixin_Name
role Role_Name2 specializes ClassName2, RoleMixin_Name

disjoint complete genset RoleMixin_Genset_Name {
    general RoleMixin_Name
    specifics Role_Name1, Role_Name2
}
```

Pelo slide de ODPs (variante 2), o roleMixin é particionado `{disjoint, complete}` em **2 ou mais roles**, e cada role especializa um **sortal** (o tipo que "desempenha" o papel, ex.: um kind).

### Como o padrão é identificado
- **por sobrecarga**, todo `genset` cuja classe `general` é do tipo `roleMixin`;
- toda classe `roleMixin`, mesmo sem genset (aí o padrão é incompleto).

### Padrão incompleto quando
| Situação | Exemplo |
|---|---|
| o roleMixin não tem nenhum genset | `roleMixin Renter` sem genset |
| genset `overlapping` ou `incomplete` (o padrão exige `disjoint complete`) | `overlapping complete genset Supplier_Types` |
| menos de 2 classes específicas | `specifics Person_Supplier` |
| uma específica não foi declarada, ou não é do tipo `role` | `specifics ..., Truck` (Truck é `subkind`) |
| um role não especializa nenhum sortal (kind, collective, subkind, phase ou role) | `role Company_Owner specializes Owner` |
| um role especializa o roleMixin, mas está fora das `specifics` do genset | `role Extra_Owner specializes Organization, Owner` |

Os sortais seguem o fragmento da UFO do slide de ODPs: `kind`, `collective` e `subkind` (rígidos), e `phase` e `role` (anti-rígidos).

---

## 4. Coerções (tratamento de erros)

Cada coerção é uma conversão **permitida** que corrige o erro e deixa a análise continuar. Todas aparecem no relatório de erros como `[COERÇÃO]`, com o problema e a correção aplicada, e na ocorrência do padrão (`* COERÇÃO: ...`).

| Padrão | Recebido | Convertido para | Justificativa |
|---|---|---|---|
| todos | nome no formato de instância (`ClassName1`) onde se espera uma classe (alvo de relação, `specializes`, `general`/`specifics`) | referência à classe `ClassName1` | os modelos do enunciado usam esses nomes para classes |
| Mode | cardinalidade do portador em `@characterization` diferente de `[1]` (ex.: `[1..*]`) | `[1]` | o mode inere em exatamente um portador |
| Mode | cardinalidade mínima 0 em `@externalDependence` (ex.: `[0..*]`, `[*]`) | mínimo 1 (`[1..*]`) | a dependência externa exige mínimo ≥ 1 |
| RoleMixin | genset do roleMixin sem `disjoint` e/ou sem `complete` | restrições `disjoint complete` assumidas | o padrão exige `{disjoint, complete}` |
| RoleMixin | role nas `specifics` do genset sem `specializes <roleMixin>` | especialização inserida a partir do genset | no modelo, cada role especializa o roleMixin |

**O que não tem coerção** (tipos incompatíveis, como somar `string` com `bool`) deixa o padrão **incompleto**. Por exemplo: `kind` no lugar de `mode`, `subkind` no lugar de `role`, `overlapping` explícito no lugar de `disjoint`.

Um padrão que só fica completo depois de coerções aparece em **padrões completos**, com as coerções listadas. Por exemplo, o `RoleMixin_Pattern.tonto` do repositório do professor declara os roles sem `specializes RoleMixin_Name`, e é completado pela coerção.

---

## 5. Saída

A seção é gravada em `output/saida.txt`, antes do relatório de erros. Exemplo com trechos de dois testes (o `Mode_Pattern.tonto` do professor e o `input/teste_mode_rolemixin_incompletos.txt`):

```
=====================================================
  ANÁLISE SEMÂNTICA: PADRÕES MODE E ROLEMIXIN
=====================================================
(1) PADRÕES COMPLETOS: 1
  [Mode] Mode_Name1 (linha 6)
      identificado por: estereótipo 'mode' da classe 'Mode_Name1'
      + portador (@characterization): ClassName1 (kind)
      + dependência externa (@externalDependence): ClassName2 (kind)

(2) PADRÕES INCOMPLETOS (identificados por sobrecarga): 1
  [RoleMixin] Renter (linha 39)
      identificado por: estereótipo 'roleMixin' da classe 'Renter'
      + roleMixin: Renter
      + role que especializa o roleMixin: Personal_Renter
      - FALTA: Nenhum genset com 'general Renter' particionando o roleMixin em roles.
=====================================================
```

Cada ocorrência mostra **o que identificou o padrão** (construção e tipos envolvidos), as partes encontradas (`+`), o que falta (`- FALTA`) e as coerções aplicadas (`* COERÇÃO`). No terminal, o resumo mostra o total de erros, avisos e coerções.

---

## 6. Arquivos

| Arquivo | O que mudou |
|---|---|
| `padroes_mode_rolemixin.h/.cpp` | **novo**: identificação, verificação e impressão dos padrões Mode e RoleMixin |
| `relatorio_erros.h/.cpp` | nova categoria `[COERÇÃO]` (`registrar_coercao`, `total_coercoes`), disponível para todo o grupo |
| `parser.y` | `cardinalidade` passa a devolver o valor (`"1"`, `"1..*"`); `relacao_interna` registra cada relação para a análise; nova regra `classe_ref_coagida` (coerção de identificador) usada em `specializes` e no alvo das relações; `ref_classe` (genset) usa a mesma coerção; `%prec` em `SPECIALIZES` sozinho |
| `classes_datatypes.h/.cpp` | só o acessor `nome_classe_em_construcao()`, para saber a qual classe pertence cada relação interna |
| `main.cpp` | chama `analisar_padroes_mode_rolemixin()` e imprime a seção; o terminal mostra as coerções |
| `Makefile`, `CMakeLists.txt` | compilam `padroes_mode_rolemixin.cpp` (no CMake, também corrigido o `\n` literal na lista de arquivos) |
| `input/teste_mode_rolemixin.txt` | padrões completos |
| `input/teste_mode_rolemixin_incompletos.txt` | padrões incompletos e completos por coerção |

As mudanças em arquivos compartilhados estão marcadas com `[Semântico]`.

---

## 7. Observações para o grupo

- A regra de **declaração** de classe (`nome_classe_decl`) ainda trata `kind ClassName1` como erro ("contém números"). Se o grupo quiser, a mesma coerção de identificador pode ser aplicada ali, e os modelos do enunciado passam a rodar sem nenhum `[ERRO]`.
- O módulo `pacotes_relacoes` guarda as relações com estereótipo e alvo. A análise semântica precisa também das **cardinalidades** e da **classe dona** de cada relação interna, por isso a regra `relacao_interna` chama as duas funções: `registrar_relacao_interna` (do colega) e `padroes_registrar_relacao_interna` (desta parte). Os padrões Relator (`@mediation`) podem reaproveitar esses dados.
- `registrar_coercao(...)` está disponível para as coerções dos outros padrões (Subkind, Role, Phase, Relator).
