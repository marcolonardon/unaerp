#include <iostream>

// Definindo a estrutura do nó
struct No {
    int valor;
    No* proximo;
};

// Classe Pilha
class PilhaEstruturada {
private:
    No* topo;

public:
    PilhaEstruturada() : topo(nullptr) {}

    // Função para inserir elemento na PilhaEstruturada
    void push(int val) {
        No* novo_no = new No{val, topo};
        topo = novo_no;
    }

    // Função para remover elemento da PilhaEstruturada
    int pop() {
        if (topo == nullptr) {
            std::cerr << "PilhaEstruturada vazia!" << std::endl;
            return -1; // PilhaEstruturada vazia
        }
        No* no_a_remover = topo;
        topo = topo->proximo;
        int valor = no_a_remover->valor;
        delete no_a_remover;
        return valor;
    }

    // Função para verificar se a PilhaEstruturada está vazia
    bool isEmpty() {
        return topo == nullptr;
    }

    // Destrutor para desalocar memória
    ~PilhaEstruturada() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    PilhaEstruturada PilhaEstruturada;

    // Adicionando elementos à PilhaEstruturada
    PilhaEstruturada.push(5);
    PilhaEstruturada.push(10);
    PilhaEstruturada.push(20);
    PilhaEstruturada.push(30);
    PilhaEstruturada.push(40);

    // Removendo elementos da PilhaEstruturada
    std::cout << PilhaEstruturada.pop() << std::endl; // Deve imprimir 40
    std::cout << PilhaEstruturada.pop() << std::endl; // Deve imprimir 30

    return 0;
}
