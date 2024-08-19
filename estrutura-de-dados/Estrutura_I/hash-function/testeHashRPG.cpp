#include <iostream>
using namespace std;

// precisa adicionar uma verificacao para nomes iguais
int hashFunction(const string& nome){
	int hashValue = 0;
	for(char c : nome){ // itera por cada char do nome
		if(c >= '0' && c <= 'z'){ // se for dentro desse parâmetro da ASCII (Todas as letras e números - e alguns chars especiais)
			hashValue += c; // faz a soma de cada valor da ascii para cada char
		}
	}
	
	return hashValue;
}

int main() {

string nome = "Test";

int valor = hashFunction(nome);

cout << "Valor do hash: " << valor;

return 0;
}