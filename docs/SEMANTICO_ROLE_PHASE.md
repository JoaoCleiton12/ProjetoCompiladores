# Análise Semântica — Padrões Role e Phase

**Padrões de projeto de ontologias (ODPs) 2 e 3 do enunciado**

Depois da análise sintática, o módulo `padroes_role_phase.cpp` verifica os padrões **Role** e
**Phase** sobre as classes e gensets já reconhecidos. O "tipo" de cada classe é o seu
estereótipo. A saída lista **(1) os padrões completos** e **(2) os padrões incompletos**, com o
que falta em cada um, e os erros com conversão permitida são corrigidos **por coerção**.

---

## 1. Padrões validados

### Role pattern

```tonto
package Role_Pattern

kind ClassName
role Role_Name1 specializes ClassName
role Role_Name2 specializes ClassName

complete genset Class_Role_Genset_Name {
    general ClassName
    specifics Role_Name1, Role_Name2
}
//"complete" is optional, but "disjoint" doesnt' apply to roles
```

### Phase pattern

```tonto
package Phase_Pattern

kind ClassName
phase Phase_Name1 specializes ClassName
phase Phase_Name2 specializes ClassName
phase Phase_NameN specializes ClassName

disjoint complete genset Class_Phase_Genset_Name {
    general ClassName
    specifics Phase_Name1, Phase_Name2, Phase_NameN
}
//"disjoint" is mandatory for phases, but "complete" is optional
```

Phases formam uma **partição** de um sortal: duas ou mais phases complementares num genset
`disjoint`. Roles especializam um sortal, do qual herdam a identidade; como a mesma instância
pode desempenhar vários papéis, `disjoint` não se aplica a roles (Ruy et al., 2017). A
dependência relacional da role (`@mediation`) é verificada no padrão Relator.

---

## 2. Sobrecarga: identificação dos padrões

O significado de um **genset** é decidido pelo tipo das suas classes específicas, como o
operador sobrecarregado do slide, cujo significado depende dos tipos dos operandos:

| Specifics do genset | Classe geral | Significado |
|---|---|---|
| todas `phase` | sortal | **Phase pattern** |
| todas `role` | sortal | **Role pattern** |
| todas `role` | `roleMixin` | RoleMixin pattern (módulo Mode/RoleMixin) |
| contém `subkind` | — | Subkind pattern (módulo Subkind/Relator) |
| `phase` e `role` misturadas | — | tipos incompatíveis → **erro** |

Cada padrão é avaliado por três funções sobrecarregadas (mesma ideia do módulo Subkind/Relator):

| Sobrecarga | Assinatura | Identifica |
|---|---|---|
| 1 — completa | `avaliar_phase_pattern(genset, fora)` | sortal + phases + genset |
| 2 — parcial | `avaliar_phase_pattern(sortal, phases)` | phases que especializam o sortal, sem genset |
| 3 — isolada | `avaliar_phase_pattern(phase)` | phase sem `specializes` e fora de genset |

O mesmo vale para `avaliar_role_pattern(...)`. Assim o padrão é reconhecido **mesmo quando
está incompleto**.

---

## 3. Coerção: tratamento de erros

Quando o tipo recebido não é o esperado, mas existe uma conversão permitida (como
`2 * 3.14` no slide), o analisador corrige, registra `[COERÇÃO]` no relatório e o padrão é
considerado completo:

| Situação | Correção aplicada |
|---|---|
| genset de phases sem `disjoint` | `disjoint` assumido |
| genset de roles com `disjoint` | `disjoint` removido |
| phase/role no genset sem `specializes <geral>` | especialização inserida a partir do genset |

---

## 4. Faltas (padrões incompletos)

| Padrão | Situação |
|---|---|
| Phase | genset `overlapping` (phases exigem `disjoint`) |
| Phase | genset com uma só phase (a partição exige 2 ou mais) |
| Phase | phase do sortal fora das specifics do genset |
| Phase | phases sem genset; phase única do sortal |
| Phase | phase isolada (sem `specializes` e fora de genset) — também **erro** no relatório |
| Phase | classe geral não-sortal (ex.: `category`) — também **erro** no relatório |
| Role | role do sortal fora das specifics do genset |
| Role | roles sem genset (o modelo do enunciado inclui o genset) |
| Role | role isolada (sem `specializes` e fora de genset) |
| Role | classe geral não-sortal ou não declarada |
| Role/Phase | genset que mistura phases e roles — também **erro** no relatório |

Sortais (slide "UFO - Endurant Universals"): `kind`, `collective`, `subkind`, `phase`, `role`.

O erro "role sem ancestral kind" já é registrado pela verificação global do módulo Relator, por
isso não é repetido aqui.

---

## 5. Saída

Seção **ANÁLISE SEMÂNTICA: PADRÕES ROLE E PHASE** de `output/saida.txt`, no mesmo formato das
seções Subkind/Relator e Mode/RoleMixin:

```
(1) PADRÕES COMPLETOS: 2
  [Role] Person (linha 3)
      identificado por: sobrecarga completa: genset 'Person_Roles' com 2 specifics do tipo role
      + sortal (geral): kind Person
      + genset: Person_Roles (linha 62)
      + role: Student specializes Person
      + role: Employee specializes Person
      * COERÇÃO: genset 'Person_Roles': 'disjoint' removido (linha 62)
      * COERÇÃO: 'Employee specializes Person' inserido (linha 64)
...
(2) PADRÕES INCOMPLETOS (identificados por sobrecarga): 11
  [Phase] Building (linha 5)
      identificado por: sobrecarga parcial: 2 phase(s) especializando 'Building' (sem genset)
      + sortal (geral): kind Building
      + phase: Under_Construction specializes Building
      + phase: Finished specializes Building
      - FALTA: Ausência de 'disjoint genset' particionando 'Building' em [Under_Construction, Finished] (...)
```

---

## 6. Testes

```bash
make
./sintatico input/teste_role_phase.txt               # padrões completos
./sintatico input/teste_role_phase_incompletos.txt   # incompletos e coerções
```

Os exemplos do professor (`Role_Pattern.tonto` e `Phase_Pattern.tonto`) são reconhecidos como
padrões completos. Os erros "Nome de classe contém números" que aparecem neles vêm da convenção
do analisador léxico (nomes terminados em número são instâncias).

---

## 7. Arquivos

| Arquivo | Papel |
|---|---|
| `padroes_role_phase.h/.cpp` | sobrecarga, coerção e impressão dos padrões Role e Phase |
| `main.cpp` | chama `analisar_padroes_role_phase()` e `imprimir_padroes_role_phase()` |
| `Makefile`, `CMakeLists.txt` | incluem `padroes_role_phase.cpp` |
| `input/teste_role_phase.txt` | padrões completos |
| `input/teste_role_phase_incompletos.txt` | padrões incompletos e coerções |

Referências: enunciado do projeto; slides *Análise Semântica* (verificação de tipos, coerção e
sobrecarga) e *Ontology Design Patterns*; Ruy, F. B. et al. (2017). *From reference ontologies
to ontology patterns and back*. Data & Knowledge Engineering, 109, 41–69.
