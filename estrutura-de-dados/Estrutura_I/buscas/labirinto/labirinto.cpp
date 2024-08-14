#include <iostream>	
#include <vector>

#define MAX 10 // define o tamanho máximo de 10x10

using namespace std;

int labirinto [MAX][MAX];
bool visitados[MAX][MAX];

bool valido(int x, int y, int n, int m){
	// verificando se a celula ou vertice esta dentro dos limites da matriz
	if(x < 0 || y < 0 || x >= n ||  y >= m){
		return false;
	}
	
	//verifica se a celula ou vertice foi visitado ou e uma parede
	if(visitados[x][y] || labirinto[x][y] == 1){
		return false;
	}
		
	return true;
}

// funcao de busca por profundidade
void dsf(int x, int y, int n, int m){
	//este vetor efetura o deslocamento no eixo x (cima, baixo, direita, esquerda)
	static int dx[] = {-1, 0, 1, 0}; 

	//este vetor efetura o deslocamento no eixo y (cima, baixo, direita, esquerda)	
	static int dy[] = {0, 1, 0, -1};
	
	// marca a celula atual como visitada
	visitados[x][y] = true;
	
	// imprime a celula atual
	cout <<  "(" << x << ", " << y << ")\n";
	
	for(int i = 0; i < 4; i++){
		if(valido(x + dx[i], y + dy[i], n, m)){
			dsf(x + dx[i], y + dy[i], n, m);
		}
	}
}

int main(){
	
	return 0;
}