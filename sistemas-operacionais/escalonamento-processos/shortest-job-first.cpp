#include <iostream>
#include <algorithm> 
using namespace std;

const int MAX = 5;

struct Processo {
    int id;
    int tempo_execucao;
};

bool compararPorTempoExecucao(const Processo &a, const Processo &b) {
    return a.tempo_execucao < b.tempo_execucao;
}

void SJF(Processo processos[]) {
    sort(processos, processos + MAX, compararPorTempoExecucao); 

    int tempo_total = 0;

    cout << "Execucao usando o algoritmo Shortest Job First (SJF):" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << "Executando processo " << processos[i].id << " por " << processos[i].tempo_execucao << " unidades de tempo." << endl;
        tempo_total += processos[i].tempo_execucao;
    }
    cout << "Tempo total de execucao: " << tempo_total << " unidades de tempo." << endl;
}

int main() {
    Processo processos[] = {{1, 78}, {2, 46}, {3, 2}, {4, 15}, {5, 2}};

    SJF(processos);

    system("pause");

    return 0;
}
