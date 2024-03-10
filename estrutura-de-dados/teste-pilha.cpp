#include <iostream>
#include <stack>//pilha

using namespace std;

const int MAX = 10;

stack<int> pilha;

void remover(){
    int top;

    if(!pilha.empty()){
        top = pilha.top();
        pilha.pop();
        cout << "Valor " << top << " removido com sucesso." << endl << endl;
    }else{
        cout << "Pilha vazia." << endl << endl;
    }
}

void adicionar(){
    int valor;
    if(pilha.size() < MAX){
        cout << "Insira o valor a ser adicionado: ";
        cin >> valor;

        pilha.push(valor);

        system("cls");

        cout << "Valor " << valor << " adicionado com sucesso."<< endl << endl;   
    }else{
        cout << "Pilha cheia." << endl << endl;
    }
    
}

void imprimir(){
    if(!pilha.empty()){
        cout << "Elemento/s da pilha: ";
        stack<int> copia = pilha;

        while (!copia.empty()) {
            cout << copia.top() << " ";
            copia.pop();
        }
        cout << endl;
    } else {
        cout << "Pilha vazia." << endl;
    }
    cout << endl;
}


void menu(){
    int op;

    do{
        cout << "1 - Adicionar valor" << endl << "2 - Remover valor" << endl << "3 - Imprimir" << endl << "4 - Sair" << endl;
        
        cout << "Escolha uma opcao: ";
        cin >> op;
        cout << endl;

        switch (op){
            case 1:
                system("cls");
                adicionar(); 
                break;

            case 2:
                system("cls");
                remover();
                break;

            case 3:
                system("cls");
                imprimir();
                break;

            case 4:
                system("cls");
                cout << "Finalizando Programa..." << endl;
                
                break;

            default: 
                system("cls");
                cout << "Opcao Invalida..." << endl << endl;
                break;
        }

    }while(op != 4);

}

main(){
    menu();
    return 0;
}