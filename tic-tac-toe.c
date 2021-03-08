#include <stdio.h>
#include <stdlib.h>

int matriz[3][3]; // declarando a variável global da matriz

//declarando os protótipos

int imprimir_matriz(); // imprime a matriz na tela
int init_matriz(); // inicia a matriz
int check_winner(); // checa se há um vencedor
int check_draw(); // checa se houve um empate
void getch_player_action(); // captura a ação do jogador
void getch_computer_action(); // faz a jogada do computador


int main()
{

	int repeat;
	char winner;

	winner = 'E'; // inicialmente, o joguinho começa empatado

	do
	{
		init_matriz(); // chamando a função que inicia a matriz

		do
		{
			repeat = 0;


			imprimir_matriz(); // chamando a função que imprime o tabuleiro (matriz) na tela

			getch_player_action(); // chamando a função que captura a ação do jogador

			// checa se a jogada feita pelo player resultou em vitória
			if(check_winner() == 1)
			{

				winner = 'P'; // P = Player

				break;
			}

			getch_computer_action(); // chamando a função que faz a jogada do computador


			//  checa se a jogada feita pelo computador resultou em vitória
			if(check_winner() == 1)
			{

				winner = 'C'; // C = Computador

				break;
			}

			// checa se houve um empate
			if(check_draw() == 1)
			{
				winner = 'E'; // E = Empate
				break;
			}

			system("cls"); // Limpa a tela
		}
		while(1); // laço de repetição tecnicamente infinito

		system("cls"); // limpa a tela
		imprimir_matriz(); //  chamando a função que imprime o tabuleiro (matriz) na tela


		//Verifica quem venceu
		if(winner == 'C')
		{
			printf("\n\n	Ops! Voce perdeu...\n");
		}
		else if (winner == 'P')
		{
			printf("\n\n	Parabens! Voce venceu!\n");
		}
		else if(winner == 'E')
		{
			printf("\n\n	Empate!");
		}

		printf("\n\nDeseja jogar de novo? Aperte 1 para sim\n");
		scanf("%d", &repeat);
		fflush(stdin); // limpando buffer de memória
		system("cls");

	}
	while(repeat == 1);

	return 0;
}

int imprimir_matriz()
{

	int i;
	char j = 'A';

	printf("           1   2   3 \n");

	for(i = 0; i < 3; i++)
	{
		printf("        %c  %c | %c | %c ", j, matriz[i][0], matriz[i][1],
			   matriz[i][2] );
		j++;
		if(i != 2)
		{
			printf("\n          ---|---|---\n");
		}
	}

	return 0;
}

void getch_player_action()
{
	char letra;
	int x, y;

	printf ("\n\nDigite uma coordenada, exemplo: A1");
	printf("\nLetra: ");
	scanf ("%c", &letra);
	fflush(stdin); // limpando buffer de memória
	printf("Numero: ");
	scanf ("%d", &y);
	fflush(stdin); // limpando buffer de memória

	switch(letra)
	{
	case 'a':
		x = 1;
		break;
	case 'b':
		x = 2;
		break;
	case 'c':
		x = 3;
		break;
	}

	// decrementa as variáveis para que elas resultem na posição correta indicada pelo jogador, visando que um array inicia do zero.
	x--;
	y--;

	// verifica se a coordenada escolhida pelo jogador está livre
	if(matriz[x][y] != ' ')
	{
		printf("\nPosicao invalida, tente novamente.\n");
		getch_player_action();
	}
	else
	{
		matriz[x][y] = 'X';
	}

}

int init_matriz()
{

	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			matriz[i][j] = ' ';
	}

	return 0;
}

void getch_computer_action()
{

	// função marca no primeiro espaço em branco que encontrar
	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
			if(matriz[i][j] == ' ')
			{
				matriz[i][j] = 'O';
				return;
			}

	}
}

int check_winner()
{

	int i;

	// checa linha
	for(i = 0; i < 3; i++)
	{
		if(matriz[i][0] != ' ' && matriz[i][1] != ' ' && matriz[i][2] != ' ')
		{
			if(matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2])
			{

				return 1;
			}
		}
	}

	// checa coluna
	for(i = 0; i < 3; i++)
	{
		if(matriz[0][i] != ' ' && matriz[1][i] != ' ' && matriz[2][i] != ' ' )
		{
			if(matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i])
			{
				return 1;
			}
		}
	}

	// checa diagonal esquerda

	if(matriz[0][0] != ' ' && matriz[1][1] != ' ' && matriz[2][2] != ' ' )
	{
		if(matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2])
		{
			return 1;
		}
	}

	// checa diagonal direita

	if(matriz[0][2] != ' ' && matriz[1][1] != ' ' && matriz[2][0] != ' ' )
	{
		if(matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])
		{

			return 1;
		}
	}

	return 0;

}

int check_draw()
{

	int i, j;

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(matriz[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}



