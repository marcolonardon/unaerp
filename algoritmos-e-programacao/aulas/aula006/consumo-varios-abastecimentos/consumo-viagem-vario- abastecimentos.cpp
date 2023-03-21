/* Elabore um algoritmo para calcular o consumo (Km/l) em cada trecho de uma 
   viagem com quatro trechos onde o tanque � abastecido antes da viagem 
   e no final de cada trecho. Calcular tamb�m o consumo total na viagem.*/
   
   #include <stdio.h>
   #include <stdlib.h>
   
   float distancia=0.0, litros=0.0, dTotal=0.0, lTotal=0.0, consumo=0.0;
   int i, continuar=1, flag=0;
   main(){
   	
   	for(i=1; continuar == 1; i++){
   		flag++;
   		printf("Distancia percorida no trecho %i: ", i);
   		scanf("%f", &distancia);
   		printf("Litros abastecidos no trecho %i: ", i);
   		scanf("%f", &litros);
   		
   		if(litros <= 0 || distancia <= 0){
   			printf("Valores negativos sao invalidos.\n\n");
   			return 0;
		   }
   		
   		dTotal += distancia;
   		lTotal += litros;
   		consumo = distancia/litros;
   		
   		printf("Distancia no trecho %i: %.2fKM.\nLitros no trecho %i: %.2fL.\n", i, dTotal, i, lTotal);
   		printf("Consumo no trecho %i: %.2fKML\n", i, consumo);
   		
   		
   		printf("\n\nDigite 1 para continuar adicionando trechos e 0 para parar. " );
   		scanf("%i", &continuar);
   		printf("\n\n");
	   }
   	
   	if(flag>0)
   		printf("\n\nDistancia total: %.2f\nTotal de litros: %.2f\nConsumo medio: %.2fKML\n\n", dTotal, lTotal, dTotal/lTotal);
   	
   	system("pause");
   }
	
	
	

