#include <iostream>
#include <vector>
#define MAX 6
int main() {
    int valor = 41;
    int tamanhoVetor = 6;

    // Cria um vetor com o tamanho especificado
    std::vector<int> vetor(tamanhoVetor, -1);  // Inicializa o vetor com -1
    int valores[MAX] = {41,67,2553,12,333,111};
    
    for(int i = 0; i < MAX; i++){
    	    // Calcula a posição usando a fórmula "chave % tamanho do vetor"
	    int posicao = valores[i] % tamanhoVetor;
	    std::cout<<"Valor: "<<valores[i]<<"\nTamanho: "<<tamanhoVetor << "\nResto: "<< posicao;
	
	    // Armazena o valor na posição calculada
	    vetor[posicao] = valores[i];
	
	    // Imprime a posição e o valor armazenado
	    std::cout << "\nO numero " << valores[i] << " foi armazenado na posicao " << posicao << " do vetor.\n\n\n";
	}



    return 0;
}
