#include <iostream>
#include <vector>

using namespace std;

//funcao de busca sequencial
int buscaSequencial(vector<int>& arr, int x){
	//percorre todo o vetor até encotrar o elemento desejado
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == x){
			return i;
		}
	}
	
	//caso não encontre o elemento
	return -1;
}

int buscaBinaria(vector<int>& arr, int x){
	int esquerda = 0;
	int direita = arr.size() - 1;
	
	while(esquerda <= direita){
		int meio = esquerda + (direita - esquerda) / 2;
		
		if (arr[meio] == x) {
            return meio;
        }
        // Se o elemento é maior, ignora a metade esquerda
        if (arr[meio] < x) {
            esquerda = meio + 1;
        }
        // Se o elemento é menor, ignora a metade direita
        else {
            direita = meio - 1;
        }
	}

}

void imprimirPosicao(vector<int> vetor, int x){
	int posicao = buscaSequencial(vetor, x);
	(posicao == -1) ? cout << "\n\nSEQUENCIAL: Elemento " << x << " nao encontrado\n\n" : cout << "\n\nSEQUENCIAL: O elemento "<< x <<" esta no indice " <<buscaSequencial(vetor, x) << " do vetor";
	
	posicao = buscaBinaria(vetor, x);
	(posicao == -1) ? cout << "\n\nBINARIA: Elemento " << x << " nao encontrado\n\n" : cout << "\n\nBINARIA: O elemento "<< x <<" esta no indice " <<buscaBinaria(vetor, x) << " do vetor";
	
	/*if(posicao == -1){
		cout << "\n\nElemento " << x << " nao encontrado\n\n";
	}else{
		cout << "O elemento "<< x <<" esta na posicao " <<buscaSequencial(vetor, x) << " do vetor";
	}*/
	
}


int main(){
	int x = 3;
	vector<int>vetor = {1, 2, 3, 44, 66, 77, 88, 98, 31, 25, 92};
	
	imprimirPosicao(vetor, x);
	
	
	
	
}