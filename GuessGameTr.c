
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define true 1 			// define verdadeiro para laços do while
#define false (!true) 	// define falso para quebrar os laços while

int main(){

	time_t now;
	time(&now);
	printf("Vinicius e Antonio \nLAPRO I\n%s\n", ctime(&now)); // escreve o tempo e o nome dos alunos
	char answer; 		// caracteres usado como entrada do usuário para perguntar se eles querem jogar novamente
	int UI; 			// int usados ​​para a entrada do usuário 1 0 -1
		
	while(true){ 		// jogo principal while

		const char *const green = "\033[0;40;32m";
  		const char *const yellow = "\033[0;40;33m";
 		const char *const red = "\033[0;40;31m";
		const char *const blue = "\033[0;40;34m";
 		const char *const normal = "\033[0m";

		printf("%sBem vindo! Por favor escolha um numero de 1 a 100.%s\n", green, normal); // saudação do jogo
		printf("%s------> Você pode usar 1 para dizer que o valor está muito alto%s\n", yellow, normal);
		printf("%s------> -1 para dizer que o valor esta muito baixo%s\n", yellow, normal);
		printf("%s------>  0 para dizer que acertei seu numero%s\n", yellow, normal);
		printf("%sMinha primeira suposição é de 50. Como estou indo?%s\n", red, normal); 	//primeira suposição

		int counter = 0; 	// inicializar o contador
		int CG = 50; 		// start current guess at 50
		int HG = 100; 		// começar a marca de um palpite alto perto de 100
		int LG = 0; 		// começar de baixo ponto de adivinhar 0

		while(true){ 		// while para a lógica do jogo
			scanf("%d", &UI); 		//lê o valor de entrada do usuário
			counter++; 				// acrescenta um contador para cada palpite
			
			if (UI == 1){ 			// se o valor de entrada inserida pelo usuario for igual a 1, significa alto
			HG = CG; 				// define o valor elevado de suposição igual à estimativa atual
			int temp = CG - LG; 	// encontra diferença entre a estimativa atual e do atual baixo palpite
			CG = CG - (temp/2); 	// gera o próximo palpite atual dividindo diferença por dois e subtraindo-o palpite atual
			printf("Hmmm, meu palpite foi muito alto. Meu próximo palpite é %d. Passei perto?\n", CG);
			} 						// imprime o próximo palpite 

			if (UI == -1){ 			// se a entrada do usuário é -1, significa que o valor é muito baixo
			LG = CG; 				// define a corrente de baixo palpite igual ao palpite atual
			int temp = HG - CG; 	// encontra diferença entre alto palpite e palpite atual
			CG = CG + (temp/2); 	// gera o próximo palpite atual dividindo a diferença (temp) por dois e o adiciona ao palpite atual original.
			printf("Hmmm, meu palpite é muito baixo. Meu próximo palpite é %d. O que faço agora ?\n", CG);
			} 						// imprime o próximo palpite
			if (UI == 0){
				printf("Encontrei seu numero, consegui descobrir em %d tentativas! Seu numero é %d\n", counter, CG); // escreve o numeros de tentativas e o numero advinhado.
				break; 				// parada da lógica do jogo.
			}
		}
		printf("Você deseja jogar de novo (s/n)? "); // pergunta se o usuário deseja jogar de novo
		scanf(" %c", &answer); 		// lê a entrada do usuário
		if (answer == 'n'){ 		// o usuário não deseja jogar de novo
		break; 						// break the main gaming loop
		}

	}

	

}
