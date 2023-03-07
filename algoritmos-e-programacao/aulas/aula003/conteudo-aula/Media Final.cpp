/* Calcular a média final e imprimir se o aluno foi 
   aprovado ou reprovado e o valor da média */
  
  # include <stdio.h>
  # include <stdlib.h>
  
   float pp, ef, media ;
 	   
  main()
  {
  	// ler nota de prova parcial
  	printf("Informe a nota de Prova Parcial: ") ;
  	scanf("%f", &pp) ;
  	
  	// ler nota de exame final
  	printf("Informe a nota de Exame Final: ") ;
  	scanf("%f", &ef) ;
  	
  	// calcular a média final
  	media = (pp*4 + ef*6) / 10 ;   // pp*0.4 + ef* 0.6
  	
  	//verificar e imprimir aprovação ou reprovação
 	if(media < 5.0)
		printf("O aluno foi reprovado com media %.1f\n\n", media);
	else
		printf("O aluno foi aprovado com media %.1f\n\n", media);

  	// terminar
   	system("pause");
  	
   }
