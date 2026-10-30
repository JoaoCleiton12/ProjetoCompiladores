#ifndef ENUM_GENSET_H
#define ENUM_GENSET_H

/*
 * Tópicos 4 e 5 do analisador sintático TONTO:
 *   4. Declaração de classes enumeradas (enum)
 *   5. Generalizações (generalization sets / genset)
 *
 * As regras de produção ficam em parser.y; este módulo guarda os construtos
 * reconhecidos, faz as verificações semânticas locais (duplicidades, ciclos,
 * restrições conflitantes etc.) e imprime a tabela de síntese.
 */

#include <ostream>
#include <string>
#include <vector>

/* Modificadores (restrições) de um genset — usados como máscara de bits. */
const int MOD_DISJOINT    = 1;
const int MOD_OVERLAPPING = 2;
const int MOD_COMPLETE    = 4;
const int MOD_INCOMPLETE  = 8;

struct Referencia {
    std::string nome;
    int linha;
    int coluna;
};

struct DeclEnum {
    std::string nome;
    std::string pacote;
    int linha;
    int coluna;
    std::vector<Referencia> especializa;   // enum X specializes Y
    std::vector<Referencia> literais;
    int linha_fim;
    bool com_erro;
};

struct DeclGenset {
    std::string nome;
    std::string pacote;
    int linha;
    int coluna;
    int modificadores;          // máscara MOD_*
    bool forma_curta;           // true: "where ... specializes ...", false: "{ general ... specifics ... }"
    bool tem_geral;
    Referencia geral;
    bool tem_categorizador;
    Referencia categorizador;
    std::vector<Referencia> especificas;
    int linha_fim;
    bool com_erro;
};

/* Pacote corrente (chamado pela regra de declaração de pacote). */
void definir_pacote_atual(const std::string& nome);

/* Nome do construto em análise, usado para contextualizar erros sintáticos. */
std::string contexto_enum_genset();
bool em_enum();
bool em_genset();

/* ---- Enum ---- */
void enum_iniciar(const std::string& nome, int linha, int coluna);
void enum_adicionar_especializacao(const std::string& nome, int linha, int coluna);
void enum_adicionar_literal(const std::string& nome, int linha, int coluna);
void enum_finalizar(bool com_erro_sintatico, int linha_fim);

/* ---- Genset ---- */
void genset_iniciar(const std::string& nome, int modificadores, int linha, int coluna);
void genset_definir_forma(bool forma_curta);
void genset_definir_geral(const std::string& nome, int linha, int coluna);
void genset_definir_categorizador(const std::string& nome, int linha, int coluna);
void genset_adicionar_especifica(const std::string& nome, int linha, int coluna);
void genset_finalizar(bool com_erro_sintatico, int linha_fim);

/* Descarta/fecha um enum ou genset interrompido por erro sintático. */
void enum_genset_recuperar_erro();

/* Verificações que dependem do arquivo inteiro (chamar após yyparse). */
void verificar_referencias_enum_genset();

/* Tabela de síntese dos tópicos 4 e 5. */
void imprimir_sintese_enum_genset(std::ostream& out);

const std::vector<DeclEnum>& enums_declarados();
const std::vector<DeclGenset>& gensets_declarados();

/* Utilitários de sugestão. */
std::string capitalizar(const std::string& s);
std::string descapitalizar(const std::string& s);
std::string remover_digitos(const std::string& s);
std::string sanitizar_identificador(const std::string& s);   // troca caracteres inválidos por '_'
std::string descrever_modificadores(int mods);
/* Motivo pelo qual um lexema não segue as convenções de nome (ex.: "contém hífen '-'"). */
std::string motivo_lexema_invalido(const std::string& s);

#endif
