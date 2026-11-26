#ifndef PADROES_ROLE_PHASE_H
#define PADROES_ROLE_PHASE_H

/*
 * ANÁLISE SEMÂNTICA — Padrões de projeto de ontologias (ODPs)
 *   2. Role pattern
 *   3. Phase pattern
 *
 * Verificação estática feita depois da análise sintática, sobre as classes e
 * gensets já reconhecidos. O "tipo" de cada classe é o seu estereótipo.
 *
 *   - SOBRECARGA: o significado de um genset é decidido pelo tipo das suas
 *     classes específicas (todas phase -> Phase pattern; todas role -> Role
 *     pattern). Cada padrão é avaliado por funções sobrecarregadas (genset
 *     completo, especializações sem genset, classe isolada), o que identifica
 *     também as ocorrências incompletas.
 *   - COERÇÃO: quando existe uma conversão permitida, o analisador corrige e
 *     segue, registrando a correção no relatório (registrar_coercao):
 *       phase: 'disjoint' assumido no genset (obrigatório para phases);
 *       role : 'disjoint' removido do genset (não se aplica a roles);
 *       ambos: 'specializes <geral>' inserido a partir do genset.
 */

#include <ostream>

/* Executa a análise dos padrões Role e Phase.
   Deve ser chamada depois de yyparse(), quando todas as declarações já foram lidas. */
void analisar_padroes_role_phase();

/* Imprime: (1) padrões completos e (2) padrões incompletos identificados por sobrecarga. */
void imprimir_padroes_role_phase(std::ostream& out);

#endif
