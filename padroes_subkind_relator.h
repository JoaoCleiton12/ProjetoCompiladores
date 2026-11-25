#ifndef PADROES_SUBKIND_RELATOR_H
#define PADROES_SUBKIND_RELATOR_H

/*
 * ANÁLISE SEMÂNTICA — Padrões de projeto de ontologias (ODPs)
 *   1. Subkind pattern
 *   4. Relator pattern
 *
 * Verificação estática pós-análise sintática utilizando:
 *   - SOBRECARGA (Overloading): múltiplas assinaturas de avaliação identificam
 *     tanto ocorrências completas quanto ocorrências parciais/incompletas;
 *   - COERÇÃO (Coercion): ajustes semânticos permitidos (ex.: assumir 'disjoint'
 *     em genset de subkinds, inferir 'specializes' a partir do genset, ajustar
 *     cardinalidade mínima de mediação ou coagir sortal rígido para role) são
 *     aplicados e registrados no relatório oficial via registrar_coercao().
 */

#include <ostream>

void analisar_padroes_subkind_relator();
void imprimir_padroes_subkind_relator(std::ostream& out);

#endif