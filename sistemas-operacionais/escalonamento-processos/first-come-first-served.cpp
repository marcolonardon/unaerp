#include <iostream>
using namespace std;

const int MAX = 5;

struct Processo {
    int id;
    int tempo_chegada;
    int tempo_execucao;
};

void FCFS(Processo processos[]) {
    int tempo_total = 0;

    cout << "Execucao usando o algoritmo First-Come, First-Served (FCFS):" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << "Executando processo " << processos[i].id << " por " << processos[i].tempo_execucao << " unidades de tempo." << endl;
        tempo_total += processos[i].tempo_execucao;
    }
    cout << "Tempo total de execucao: " << tempo_total << " unidades de tempo." << endl;
}

int main() {
    Processo processos[] = {{1, 0, 78}, {2, 0, 46}, {3, 0, 2}, {4, 0, 15}, {5, 0, 2}};

    FCFS(processos);

    system("pause");

    return 0;
}
