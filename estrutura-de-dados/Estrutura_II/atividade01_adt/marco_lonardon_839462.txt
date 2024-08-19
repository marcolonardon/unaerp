/*
Criar uma struct Conta com as propriedades:
int id;
char* nome;
float saldo;

Implementar os seguintes métodos:
Conta* criarConta(int id, char nome[], float saldo);
void depositar(Conta* conta, float valor); 
void sacar(Conta* conta, float valor);
void transferir(Conta* conta_de, Conta* conta_para, float valor);

Entregar .txt com codigo resultante
*/

#include <iostream>
#include <string>
#include <vector>  
#include <conio.h> 

using namespace std;

struct Account {
    int id;
    string name;
    float balance;
};

Account* createAccount(int id, const string& name, float balance){
    Account* newAccount = new Account;
    newAccount->id = id;
    newAccount->name = name;
    newAccount->balance = balance;
    return newAccount;
};

void deposit(Account* account, float amount){
    float previousBalance = account->balance;
    account->balance += amount;
    cout << "Deposito de R$" << amount << " realizado com sucesso!\n";
    cout << "Saldo anterior: R$" << previousBalance << endl;
    cout << "Saldo atual: R$" << account->balance << endl;
}

void withdraw(Account* account, float amount){
    float previousBalance = account->balance;
    if(account->balance - amount >= 0){
        account->balance -= amount;
        cout << "Saque de R$" << amount << " realizado com sucesso!\n";
        cout << "Saldo anterior: R$" << previousBalance << endl;
        cout << "Saldo atual: R$" << account->balance << endl;
    } else {
        cout << "Saldo insuficiente para operacao\n";
        cout << "Saldo atual: R$" << account->balance << endl;
    }
}

void transfer(Account* fromAccount, Account* toAccount, float amount){
    if(fromAccount->balance - amount >= 0){
        withdraw(fromAccount, amount);
        deposit(toAccount, amount);
    } else {
        cout << "Saldo insuficiente para operacao\n";
        cout << "Saldo atual: R$" << fromAccount->balance << endl;
    }
}

void menu(){
    vector<Account*> accounts;
    int op = 0;
    int nextId = 1;

    while(op != 5) { 
        cout << "1 - Criar uma conta\n";
        cout << "2 - Depositar\n";
        cout << "3 - Sacar\n";
        cout << "4 - Transferir\n";
        cout << "5 - Sair\n";
        cout << "Escolha uma opcao: ";

        op = _getch() - '0'; 

        system ("cls");

        switch(op) {
            case 1: {
                string name;
                float balance;

                cout << "Voce selecionou criar uma conta.\n";

                cout << "Digite o nome do titular: ";
                cin >> name;
                cout << "Digite o saldo inicial: ";
                cin >> balance;
                Account* newAccount = createAccount(nextId++, name, balance);
                accounts.push_back(newAccount);
                cout << "Conta criada com sucesso! ID: " << newAccount->id << "\n";
                break;
            }
            case 2: {
                int id;
                float amount;

                cout << "Voce selecionou depositar.\n";

                cout << "Digite o ID da conta: ";
                cin >> id;
                if(id > 0 && id <= accounts.size()){
                    cout << "Digite o valor a depositar: ";
                    cin >> amount;
                    deposit(accounts[id - 1], amount);
                } else {
                    cout << "Conta nao encontrada.\n";
                }
                break;
            }
            case 3: {
                int id;
                float amount;

                cout << "Voce selecionou sacar.\n";
                
                cout << "Digite o ID da conta: ";
                cin >> id;
                
                if(id > 0 && id <= accounts.size()){
                    cout << "Digite o valor a sacar: ";
                    cin >> amount;
                    withdraw(accounts[id - 1], amount);
                } else {
                    cout << "Conta nao encontrada.\n";
                }
                break;
            }
            case 4: {
                int fromId, toId;
                float amount;

                cout << "Voce selecionou transferir.\n";
                
                cout << "Digite o ID da conta de origem: ";
                cin >> fromId;
                cout << "Digite o ID da conta de destino: ";
                cin >> toId;
                if(fromId > 0 && fromId <= accounts.size() && toId > 0 && toId <= accounts.size()){
                    cout << "Digite o valor a transferir: ";
                    cin >> amount;
                    transfer(accounts[fromId - 1], accounts[toId - 1], amount);
                } else {
                    cout << "Uma ou ambas as contas nao foram encontradas.\n";
                }
                break;
            }
            case 5:
                cout << "\nFinalizando programa...\n";
                break;
            default:
                cout << "\nOpcao invalida.\n";
                break;
        } 
    }

    for(Account* account : accounts) {
        delete account;
    }
}

int main(){
    menu();
    return 0;
}
