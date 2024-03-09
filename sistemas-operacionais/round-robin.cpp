//Round Robin
#include <iostream>
using namespace std;

const int MAX=5;

struct Processo {
    int id;
    int tempo_execucao;
};

void RoundRobin(Processo processos[], int quantum) {
    int tempo_total = 0;
    int count;

    cout << "Execucao usando o algoritmo Round Robin:" << endl;
    do {
        count = 0;
        for (int i = 0; i < MAX; i++) {
            if (processos[i].tempo_execucao > 0) {
                cout << "Executando processo " << processos[i].id << " por " << quantum << " unidades de tempo." << endl;
                tempo_total += quantum;
                processos[i].tempo_execucao -= quantum;
                if (processos[i].tempo_execucao < 0)
                    processos[i].tempo_execucao = 0;
            } else {
                count++;
            }
        }
    } while (count < MAX);
    cout << "Tempo total de execucao: " << tempo_total << " unidades de tempo." << endl;
}

int main() {
    Processo processos[] = {{1, 8}, {2, 4}, {3, 2}, {4, 5}, {5, 2}};
    int quantum = 2;

    RoundRobin(processos, quantum);

    return 0;
}
