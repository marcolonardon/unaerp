/* ler 5 números inteiros e positivos e calcular e imprimir a média 
   dos pares e a média dos impares - 
   prever a possibilidade de não ter sido digitado nenhum
   número par ou nenhum número impar - emitir mensagem 
   e não calcular a média */
   
   # include <stdio.h>
   # include <stdlib.h>
   
   int i, n, npar=0, nimpar=0, resto;
   float somapar=0, somaimpar=0;
   float mediapar, mediaimpar;
   
   main()
   {
   		for(i=1; i<=5; i++)
   		{
   			printf("Informe o numero (%i): ", i); scanf("%i", &n);
   			resto = n % 2 ;
   			if(resto == 0)
   			{
  				npar++;
  				somapar+= n;
			}
   			else
   			{
   				nimpar++;
   				somaimpar+= n;
			}
		}

   		if(npar > 0)
   		{
   			mediapar = somapar / npar ;
			printf("A media dos %i numeros pares e %.2f\n\n", npar, mediapar);
		}
   		else
   			printf("Voce nao digitou nenhum numero par\n\n");
    	
		if(nimpar > 0)
   		{
   			mediaimpar = somaimpar / nimpar ;
			printf("A media dos %i numeros impares e %.2f\n\n", nimpar, mediaimpar);
		}
   		else
   			printf("Voce nao digitou nenhum numero impar\n\n");
   			
   		system("pause");	
   }
   
   
