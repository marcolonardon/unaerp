typedef struct Arvore;

Arvore* CriarArvore(int arr[], int size);

void PrintPreOrder(Arvore* arvore);
void PrintInOrder(Arvore* arvore);
void PrintPosOrder(Arvore* arvore);
void LiberaMemoria(Arvore* arvore);
