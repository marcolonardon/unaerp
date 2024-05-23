#include <iostream>
using namespace std;

int hashFunction(const string& nome){
	int hashValue = 0;
	for(char c : nome){
		if(c >= '0' && c <= 'z'){
			hashValue += c;
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