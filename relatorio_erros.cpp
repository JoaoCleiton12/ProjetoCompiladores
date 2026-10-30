#include "relatorio_erros.h"

#include <algorithm>

using namespace std;

static vector<Ocorrencia> lista_ocorrencias;

static void registrar(Severidade s, int linha, int coluna, const string& construto,
                      const string& mensagem, const string& sugestao) {
    lista_ocorrencias.push_back({s, linha, coluna, construto, mensagem, sugestao});
}

void registrar_erro(int linha, int coluna, const string& construto,
                    const string& mensagem, const string& sugestao) {
    registrar(Severidade::ERRO, linha, coluna, construto, mensagem, sugestao);
}

void registrar_aviso(int linha, int coluna, const string& construto,
                     const string& mensagem, const string& sugestao) {
    registrar(Severidade::AVISO, linha, coluna, construto, mensagem, sugestao);
}

int total_erros() {
    return (int)count_if(lista_ocorrencias.begin(), lista_ocorrencias.end(),
                         [](const Ocorrencia& o) { return o.severidade == Severidade::ERRO; });
}

int total_avisos() {
    return (int)lista_ocorrencias.size() - total_erros();
}

const vector<Ocorrencia>& ocorrencias() { return lista_ocorrencias; }

void imprimir_relatorio_erros(ostream& out) {
    out << "\n=====================================================\n";
    out << "           RELATÓRIO DE ERROS DA ONTOLOGIA           \n";
    out << "=====================================================\n";

    if (lista_ocorrencias.empty()) {
        out << "Nenhum erro ou aviso encontrado.\n";
        out << "=====================================================\n";
        return;
    }

    vector<Ocorrencia> ordenada = lista_ocorrencias;
    stable_sort(ordenada.begin(), ordenada.end(),
                [](const Ocorrencia& a, const Ocorrencia& b) {
                    if (a.linha != b.linha) return a.linha < b.linha;
                    return a.coluna < b.coluna;
                });

    for (const Ocorrencia& o : ordenada) {
        out << (o.severidade == Severidade::ERRO ? "[ERRO]  " : "[AVISO] ")
            << "Linha " << o.linha;
        if (o.coluna > 0) out << ", Coluna " << o.coluna;
        out << " (" << o.construto << ")\n";
        out << "        Problema : " << o.mensagem << "\n";
        if (!o.sugestao.empty())
            out << "        Sugestão : " << o.sugestao << "\n";
    }
    out << "-----------------------------------------------------\n";
    out << "Total: " << total_erros() << " erro(s), " << total_avisos() << " aviso(s)\n";
    out << "=====================================================\n";
}
