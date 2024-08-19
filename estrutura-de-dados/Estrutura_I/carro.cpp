/*
769296 - Jessica Cristina Pretel Maganha
840347 - Kayky Luiz de Paula Araújo
839462 - Marco Antônio Lonardon Júnior
840474 - Matheus Lima Bonadio
839868 - Vítor Nascimento Moreira
*/
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
    /* No classroom diz nome, marca e modelo, 
    mas, na aula, o professor disse da placa*/

    do {
        mostrarMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                if(fila.tamanho < MAX ){
                    system("cls");
                    cout << "\nDigite o nome: ";
                    getline(cin, nome);
                    cout << "Digite a placa: ";
                    getline(cin, placa);
                    cout << "Digite o Modelo: ";
                    getline(cin, modelo);
                    fila.adicionar(nome, modelo, placa);
                    fila.tamanho++;
                    system("cls");
                    cout<<"\n\nVeiculos cadastrados: " << fila.tamanho <<" de " << MAX << endl << endl;   
                }else{
                    system("cls");
                    cout<<"\nLimite de cadastros atingido.\n\n";
                }
                
                break;
            case 2:
                system("cls");
                fila.remover();
                fila.tamanho--;
                cout << "\nCarro Deletado Com Sucesso.\n" << endl;
                break;
            case 3:
                system("cls");
                fila.listar();
                break;
            case 4:
                system("cls");
                cout << "\nSaindo..." << endl;
                break;
            default:
                system("cls");
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
    int position = 1;
    Carro* atual = frente;
    if(frente != nullptr){
        while (atual != nullptr) {
            cout << "***** Veiculo " << position << " *****\n";
            cout << "Nome: " << atual->nome << endl;
            cout << "Modelo: " << atual->modelo << endl;
            cout << "Placa: " << atual->placa << endl << endl;
            atual = atual->proximo;
            position++;
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