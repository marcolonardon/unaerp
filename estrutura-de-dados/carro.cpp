//Fila
#include <iostream>

using namespace std;

const int MAX = 100;

struct Carro {
    string nome;
    string modelo;
    string placa;
    Carro* proximo;
};

class FilaEncadeada {
public:
    int tamanho;

    FilaEncadeada() : frente(nullptr), tras(nullptr), tamanho(0) {}

    ~FilaEncadeada();

    void adicionar(string nome, string modelo, string placa);

    void listar();

    void remover();

    bool estaVazia();

private:
    Carro* frente;
    Carro* tras;
};

void mostrarMenu() {
    cout << "1. Inserir Carro na fila" << endl;
    cout << "2. Deletar Carro da fila" << endl;
    cout << "3. Listar Carros na fila" << endl;
    cout << "4. Sair" << endl;
}

void menu(){
    FilaEncadeada fila;
    int opcao;
    string nome, modelo, placa;

    do {
        mostrarMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if(fila.tamanho < MAX ){
                    cout << "\nDigite o nome: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Digite a placa: ";
                    cin >> placa;
                    cin.ignore();
                    cout << "Digite o Modelo: ";
                    getline(cin, modelo);
                    fila.adicionar(nome, modelo, placa);
                    fila.tamanho++;
                    cout<<"\n\nVeiculos cadastrados: " << fila.tamanho <<" de " << MAX << endl << endl;   
                }else{
                    cout<<"\nLimite de cadastros atingido.\n\n";
                }
                
                break;
            case 2:
                fila.remover();
                fila.tamanho--;
                break;
            case 3:
                fila.listar();
                break;
            case 4:
                cout << "\nSaindo..." << endl;
                break;
            default:
                cout << "\nOpcao invalida!\n" << endl;
        }
    } while (opcao != 4);
}

int main() {

    menu();

    return 0;
}

void FilaEncadeada::adicionar(string nome, string modelo, string placa) {

    Carro* novoCarro = new Carro{nome, modelo, placa, nullptr};
    if (tras != nullptr) {
        tras->proximo = novoCarro;
    }
    tras = novoCarro;
    if (frente == nullptr) {
        frente = novoCarro;
    }

}


void FilaEncadeada::listar() {
    Carro* atual = frente;
    if(frente != nullptr){
        while (atual != nullptr) {
            cout << "\n\nNome: " << atual->nome << "\nModelo: " << atual->modelo << "\nplaca: " << atual->placa << endl << endl;
            atual = atual->proximo;
        }  
    }else{
        cout << "\nFila Vazia!\n\n";
    }
    
}

void FilaEncadeada::remover() {
    if (frente != nullptr) {
        Carro* temp = frente;
        frente = frente->proximo;
        if (frente == nullptr) {
            tras = nullptr;
        }
        delete temp;
    } else {
        cout << "Fila vazia!" << endl;
    }
}

bool FilaEncadeada::estaVazia() {
    return frente == nullptr;
}

FilaEncadeada::~FilaEncadeada() {
    while (!estaVazia()) {
        remover();
    }
}