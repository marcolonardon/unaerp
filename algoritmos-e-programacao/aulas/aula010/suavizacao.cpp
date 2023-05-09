// operação de suavização ~~~~ esse ex pede para não alterar o primeiro e último valor

#include <stdio.h>
#include <stdlib.h>

float vetor[5], vetor_suavizado[5];

main()
{
	for (int i = 0; i < 5; i++)
	{
		printf("Informe o valor %i: ", i + 1);
		scanf("%f", &vetor[i]);
	}

	vetor_suavizado[0] = vetor[0];
	vetor_suavizado[4] = vetor[4];

	for (int i = 1; i < 4; i++)
	{
		vetor_suavizado[i] = (vetor[i - 1] + vetor[i] + vetor[i + 1]) / 3;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%.2f  ", vetor[i]);
		printf(" %.2f  ", vetor_suavizado[i]);
		printf("\n\n");
	}

	system("pause");
}