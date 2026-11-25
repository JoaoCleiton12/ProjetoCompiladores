#ifndef PADROES_MODE_ROLEMIXIN_H
#define PADROES_MODE_ROLEMIXIN_H

/*
 * ANÁLISE SEMÂNTICA — Padrões de projeto de ontologias (ODPs)
 *   5. Mode pattern
 *   6. RoleMixin pattern
 *
 * A análise é uma verificação estática feita depois da análise sintática,
 * sobre a tabela de símbolos (classes, gensets e relações já reconhecidos).
 *
 * O "tipo" de cada classe é o seu estereótipo (kind, role, mode, roleMixin...).
 * Assim como na verificação de tipos vista em sala:
 *   - cada construção do padrão espera operandos de um certo tipo
 *     (ex.: as specifics de um genset de roleMixin devem ser do tipo role);
 *   - SOBRECARGA: o significado de uma construção (genset, specializes,
 *     relação interna) é decidido pelos tipos conhecidos dos seus operandos;
 *     é assim que um padrão é identificado mesmo quando está incompleto;
 *   - COERÇÃO: quando o tipo recebido não é o esperado, mas existe uma
 *     conversão permitida, o analisador converte e segue, registrando a
 *     correção no relatório de erros.
 */

#include <ostream>
#include <string>

/* Chamada pelo parser (regra relacao_interna) para cada relação interna lida,
   por exemplo:  @characterization [1..*] -- [1] Person
   dona         = classe em cujo bloco a relação está ("" se fora de uma classe)
   estereotipo  = characterization, externalDependence, mediation...
   card_origem  = cardinalidade do lado da classe dona ("1..*")
   card_destino = cardinalidade do lado da classe alvo ("1")
   destino      = classe alvo ("Person")                                         */
void padroes_registrar_relacao_interna(const std::string& dona, const std::string& estereotipo,
                                       const std::string& card_origem,
                                       const std::string& card_destino,
                                       const std::string& destino, int linha, int coluna);

/* Executa a análise semântica dos padrões Mode e RoleMixin.
   Deve ser chamada depois de yyparse(), quando todas as declarações já foram lidas. */
void analisar_padroes_mode_rolemixin();

/* Imprime: (1) padrões completos e (2) padrões incompletos identificados por sobrecarga. */
void imprimir_padroes_mode_rolemixin(std::ostream& out);

#endif
