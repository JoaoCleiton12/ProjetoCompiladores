#include "pacotes_relacoes.h"
#include "tabela_simbolos.h"
#include "relatorio_erros.h"

using namespace std;

static string pacote_atual = "(sem pacote)";
static vector<DeclPacote> lista_pacotes;
static vector<DeclRelacao> lista_relacoes;

void definir_pacote_atual(const string& nome) {
    pacote_atual = nome.empty() ? "(sem pacote)" : nome;
}

string obter_pacote_atual() {
    return pacote_atual;
}

void registrar_pacote(const string& nome, int linha, int coluna) {
    if (nome.empty()) return;
    definir_pacote_atual(nome);
    inserir_simbolo(nome, "Pacote", linha, coluna);
    lista_pacotes.push_back({nome, linha, coluna});
}

void registrar_relacao_externa(const string& estereotipo,
                               const string& origem,
                               const string& nome,
                               const string& destino,
                               int linha, int coluna) {
    if (nome.empty()) return;
    inserir_simbolo(nome, "Relação Externa", linha, coluna);
    lista_relacoes.push_back({
        nome, estereotipo, pacote_atual, origem, destino, false, linha, coluna
    });
}

void registrar_relacao_interna(const string& estereotipo,
                               const string& destino,
                               int linha, int coluna) {
    string identificador = "Interna_" + estereotipo + "_para_" + destino + "_L" + to_string(linha);
    inserir_simbolo(identificador, "Relação Interna", linha, coluna);
    lista_relacoes.push_back({
        identificador, estereotipo, pacote_atual, "", destino, true, linha, coluna
    });
}

void verificar_referencias_pacotes_relacoes() {
    // Gancho preparado para as validações semânticas (existência de classes, regras OntoUML, etc.)
}

void imprimir_sintese_pacotes_relacoes(ostream& out) {
    size_t total_externas = 0;
    size_t total_internas = 0;
    for (const auto& r : lista_relacoes) {
        if (r.interna) total_internas++;
        else total_externas++;
    }

    out << "\n=====================================================\n";
    out << "     SÍNTESE: PACOTES E RELAÇÕES — Tópicos 1 e 6     \n";
    out << "=====================================================\n";
    out << "Pacotes declarados: " << lista_pacotes.size() << "\n";
    for (const auto& p : lista_pacotes) {
        out << "  package " << p.nome << " (linha " << p.linha << ")\n";
    }

    out << "Relações externas: " << total_externas << "\n";
    for (const auto& r : lista_relacoes) {
        if (!r.interna) {
            out << "  @" << r.estereotipo << " relation " << r.nome
                << " (" << r.origem << " -> " << r.destino << ")"
                << " | pacote: " << r.pacote << " | linha " << r.linha << "\n";
        }
    }

    out << "Relações internas: " << total_internas << "\n";
    for (const auto& r : lista_relacoes) {
        if (r.interna) {
            out << "  @" << r.estereotipo << " -> " << r.destino
                << " (" << r.nome << ")"
                << " | pacote: " << r.pacote << " | linha " << r.linha << "\n";
        }
    }
    out << "=====================================================\n";
}

const vector<DeclPacote>& pacotes_declarados() { return lista_pacotes; }
const vector<DeclRelacao>& relacoes_declaradas() { return lista_relacoes; }