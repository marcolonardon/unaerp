//Fila
#include <iostream>

struct Carro {
    std::string nome;
    std::string modelo;
    int placa;
    Carro* proximo;
};

class FilaEncadeada {
public:
    FilaEncadeada() : frente(nullptr), tras(nullptr) {}

    ~FilaEncadeada() {
        while (!estaVazia()) {
            remover();
        }
    }

    void adicionar(std::string nome, std::string modelo, int placa) {
        Carro* novoCarro = new Carro{nome, modelo, placa, nullptr};
        if (tras != nullptr) {
            tras->proximo = novoCarro;
        }
        tras = novoCarro;
        if (frente == nullptr) {
            frente = novoCarro;
        }
    }

    void listar() {
        Carro* atual = frente;
        while (atual != nullptr) {
            std::cout << "Nome: " << atual->nome << "\nModelo: " << atual->modelo << "\nplaca: " << atual->placa << std::endl;
            atual = atual->proximo;
        }
    }

    void remover() {
        if (frente != nullptr) {
            Carro* temp = frente;
            frente = frente->proximo;
            if (frente == nullptr) {
                tras = nullptr;
            }
            delete temp;
        } else {
            std::cout << "Fila vazia!" << std::endl;
        }
    }

    bool estaVazia() {
        return frente == nullptr;
    }

private:
    Carro* frente;
    Carro* tras;
};

void mostrarMenu() {
    std::cout << "1. Inserir Carro na fila" << std::endl;
    std::cout << "2. Deletar Carro da fila" << std::endl;
    std::cout << "3. Listar Carros na fila" << std::endl;
    std::cout << "4. Sair" << std::endl;
}


int main() {
    FilaEncadeada fila;
    int opcao;
    std::string nome;
    std::string modelo;
    int placa;

    do {
        mostrarMenu();
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                std::cout << "Digite o nome: ";
                std::cin >> nome;
                std::cout << "Digite a placa: ";
                std::cin >> placa;
                std::cout << "Digite o Modelo: ";
                std::cin >> modelo;
                fila.adicionar(nome, modelo, placa);
                break;
            case 2:
                fila.remover();
                break;
            case 3:
                fila.listar();
                break;
            case 4:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção invalida!" << std::endl;
        }
    } while (opcao != 4);

    return 0;
}
