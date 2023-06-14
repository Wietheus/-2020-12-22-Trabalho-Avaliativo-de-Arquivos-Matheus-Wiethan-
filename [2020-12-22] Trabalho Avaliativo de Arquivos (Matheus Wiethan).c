/*
Utilizando manipulação de arquivos, implemente um salvamento para a atividade de movimentação no plano cartesiano feita anteriormente.
O programa deverá salvar as informações em um arquivo de texto.
Ao reabrir, o programa deverá carregar os últimos dados.
Abaixo, a tarefa original de movimentação no plano cartesiano:

Um jogo necessita que sejam desenvolvidos os mecanismos de movimentação e posicionamento em um plano 2D.
Com isso em mente, realize as seguintes tarefas:

1. Criar uma estrutura para itens coletáveis que contenha:
1.1. Um código inteiro que servirá como identificador;
1.2. Um nome;
1.3. Posição nos eixos X e Y;
1.4. Uma variável para identificar se o item foi coletado ou não.
2. Criar uma estrutura para personagens que contenha:
2.1. Um código inteiro que servirá como identificador;
2.2. Um nome;
2.3. Posição nos eixos X e Y;
2.4. Uma variável para identificar se o personagem está vivo ou não;
2.5. Uma variável contadora de itens coletados.
3. Fazer a leitura das informações de 4 itens e 1 personagem (o jogador escolherá tudo, incluindo a posição inicial do personagem).
4. Criar funções para os quatro sentidos de movimentação do personagem: baixo, cima, direita e esquerda.
5. Adicionar um mecanismo onde o personagem pode coletar algum item disponível, funcionando da seguinte forma:
5.1. Exibir os itens disponíveis para seleção;
5.2. Ao selecionar o item, o personagem se deslocará instantaneamente para a sua posição, coletando o mesmo.

Após preencher as informações solicitadas, o jogador pode movimentar-se livremente pelo plano.
Sempre deverão ser mostrados os dados atualizados após o deslocamento, até que selecione a opção de encerrar o jogo.
*/

#include <conio.h>
#include <stdio.h>
#include <string.h>
FILE *ArmInf;//Linha nova para declarar o arquivo que armazenará as informações.
struct Coo
{
	int X, Y;
};
typedef struct
{
	char Nom [50];
	int Cod, Est;
	struct Coo Pos;
} DadIte;
typedef struct
{
	char Nom [50];
	int Cod, Est, QuaIte;
	struct Coo Pos;
} DadPer;
char Opc; DadIte Ite [4]; DadPer Per; int i, j, k, OpcIte;
main ()
{
	int OpcMen;//Início das 18 linhas para o sistema de arquivos.
	ArmInf = fopen ("[2020-12-22] Trabalho Avaliativo de Arquivos (Matheus Wiethan) - Save.txt", "rb");//Linha nova para ler o arquivo com os dados em binários.
	printf ("Abstrato, o Coletor\n\nNovo jogo (1)\n"); if (ArmInf) printf ("Continuar jogo (2)\nApagar jogo salvo (3)\n");//Linha nova de menu inicial.
	do
	{
		printf ("\nOpcao selecionada: "); scanf ("%d", & OpcMen);
		if (OpcMen != 1 && OpcMen != 2 && OpcMen != 3) printf ("Escolha uma opcao valida!\n");
	}
	while (OpcMen != 1 && OpcMen != 2 && OpcMen != 3);
	if (OpcMen == 1) fclose (ArmInf);
	if (ArmInf && OpcMen == 2)
	{
		fread (&Ite, sizeof (DadIte), 4, ArmInf);//Linha nova para ler as informações dos itens no arquivo.
		fread (&Per, sizeof (DadPer), 1, ArmInf);//Linha nova para ler as informações do personagem no arquivo.
		fclose (ArmInf); system ("cls"); VisPla ();//Linha nova para fechar o arquivo aberto, limpar a tela e ir direto para o jogo salvo.
	}
	if (ArmInf && OpcMen == 3) fclose (ArmInf), remove ("[2020-12-22] Trabalho Avaliativo de Arquivos (Matheus Wiethan) - Save.txt"), system ("cls"), main ();//Linha nova para fechar e apagar o arquivo de salvamento, limpando a tela e reiniciando o menu inicial.
	system ("cls");//Término das 18 linhas para o sistema de arquivos.
	printf ("Tendo como referencia um plano cartesiano que vai de -10 a 10 em X e Y...\nFaca o que e solicitado abaixo.\n\n");
	printf ("Preencha as informacoes de 4 itens, posicionando-os no plano:\n\n");
	for (i = 0; i < 4; i ++)
	{
		Ite [i].Est = 1;
		printf ("- Item %d -\n\n", i + 1);
		printf ("Codigo: "); fflush (stdin); scanf ("%d", & Ite [i].Cod);
		printf ("Nome: "); fflush (stdin); gets (Ite [i].Nom);
		do
		{
			do
			{
				printf ("Posicao (X): "); fflush (stdin); scanf ("%d", & Ite [i].Pos.X);
				if (Ite [i].Pos.X < -10 || Ite [i].Pos.X > 10) printf ("Escolha numeros entre -10 e 10!\n");
			}
			while (Ite [i].Pos.X < -10 || Ite [i].Pos.X > 10);
			do
			{
				printf ("Posicao (Y): "); fflush (stdin); scanf ("%d", & Ite [i].Pos.Y);
				if (Ite [i].Pos.Y < -10 || Ite [i].Pos.Y > 10) printf ("Escolha numeros entre -10 e 10!\n");
			}
			while (Ite [i].Pos.Y < -10 || Ite [i].Pos.Y > 10);
			if (i > 0 && ((Ite [i].Pos.X == Ite [i - 1].Pos.X && Ite [i].Pos.Y == Ite [i - 1].Pos.Y) || (Ite [i].Pos.X == Ite [i - 2].Pos.X && Ite [i].Pos.Y == Ite [i - 2].Pos.Y) || (Ite [i].Pos.X == Ite [i - 3].Pos.X && Ite [i].Pos.Y == Ite [i - 3].Pos.Y))) printf ("Coordenada ja possui item!\n");
		}
		while (i > 0 && ((Ite [i].Pos.X == Ite [i - 1].Pos.X && Ite [i].Pos.Y == Ite [i - 1].Pos.Y) || (Ite [i].Pos.X == Ite [i - 2].Pos.X && Ite [i].Pos.Y == Ite [i - 2].Pos.Y) || (Ite [i].Pos.X == Ite [i - 3].Pos.X && Ite [i].Pos.Y == Ite [i - 3].Pos.Y)));
		printf ("Estado: Disponivel\n\n");
	}
	printf ("Agora, preencha as informacoes do personagem e posicione-o:\n\n- Personagem -\n\n");
	Per.Est = 1; Per.QuaIte = 0;
	printf ("Codigo: "); fflush (stdin); scanf ("%d", & Per.Cod);
	printf ("Nome: "); fflush (stdin); gets (Per.Nom);
	do
	{
		printf ("Posicao (X): "); fflush (stdin); scanf ("%d", & Per.Pos.X);
		if (Per.Pos.X < -10 || Per.Pos.X > 10) printf ("Escolha numeros entre -10 e 10!\n");
	}
	while (Per.Pos.X < -10 || Per.Pos.X > 10);
	do
	{
		printf ("Posicao (Y): "); fflush (stdin); scanf ("%d", & Per.Pos.Y);
		if (Per.Pos.Y < -10 || Per.Pos.Y > 10) printf ("Escolha numeros entre -10 e 10!\n");
	}
	while (Per.Pos.Y < -10 || Per.Pos.Y > 10);
	do
	{
		printf ("Personagem esta Vivo (1) ou Morto (0)? "); fflush (stdin); scanf ("%d", & Per.Est);
		if (Per.Est != 0 && Per.Est != 1) printf ("Escolha 1 ou 0!\n");
	}
	while (Per.Est != 0 && Per.Est != 1);
	if (Per.Est == 0)
	{
		printf ("\nNao e possivel jogar com o personagem morto!\nPressione qualquer tecla para continuar..."); fflush (stdin); getch (); system ("cls"); Opc = '0'; VisPla ();
	}
	if (Per.Est == 1)
	{
		printf ("\nAgora, iniciaremos o jogo!\nPressione qualquer tecla para continuar..."); fflush (stdin); getch (); system ("cls"); Opc = '9'; VisPla ();
	}
}
MovPer ()
{
	int ConIte = 0;
	printf ("\n\n- Movimentar personagem para baixo (S), cima (W), direita (D) ou esquerda (A).\n- Ir ate item disponivel e coleta-lo (5).\n- Salvar progresso e encerrar jogo (0).\n\nPressione o comando para realizar a acao...");//Alterado "- Encerrar jogo (0)." para "- Salvar progresso e encerrar jogo (0).".
	do
	{
		fflush (stdin); Opc = getch ();
		if (Opc != 's' && Opc != 'w' && Opc != 'd' && Opc != 'a' && Opc != '5' && Opc != '0') printf ("\nEscolha uma opcao valida!");
	}
	while (Opc != 's' && Opc != 'w' && Opc != 'd' && Opc != 'a' && Opc != '5' && Opc != '0');
	if (Opc == 's')
	{
		if (Per.Pos.Y > -10) Per.Pos.Y --;
		else if (Per.Pos.Y == -10) Per.Pos.Y = 10;
	}
	if (Opc == 'w')
	{
		if (Per.Pos.Y < 10) Per.Pos.Y ++;
		else if (Per.Pos.Y == 10) Per.Pos.Y = -10;
	}
	if (Opc == 'd')
	{
		if (Per.Pos.X < 10) Per.Pos.X ++;
		else if (Per.Pos.X == 10) Per.Pos.X = -10;
	}
	if (Opc == 'a')
	{
		if (Per.Pos.X > -10) Per.Pos.X --;
		else if (Per.Pos.X == -10) Per.Pos.X = 10;
	}
	if (Opc == '5')
	{
		for (i = 0; i < 4; i ++)
		{
			if (Ite [i].Est == 1) ConIte ++;
		}
		if (ConIte == 0)
		{
			printf ("\n\nNao ha mais itens disponiveis!\nEscolha outra opcao..."); fflush (stdin); getch ();
		}
		if (ConIte > 0)
		{
			printf ("\n\nEscolha entre os itens disponiveis:\n");
			for (i = 0; i < 4; i ++)
			{
				if (Ite [i].Est == 1) printf ("\n- Item %d (%d).", i + 1, i + 1);
			}
			printf ("\n\n");
			do
			{
				printf ("Opcao selecionada: "); fflush (stdin); scanf ("%d", & OpcIte);
				if (OpcIte != 1 && OpcIte != 2 && OpcIte != 3 && OpcIte != 4) printf ("Escolha uma opcao valida!\n");
				if (Ite [OpcIte - 1].Est != 1 && (OpcIte == 1 || OpcIte == 2 || OpcIte == 3 || OpcIte == 4)) printf ("Item ja coletado!\n");
			}
			while ((OpcIte != 1 && OpcIte != 2 && OpcIte != 3 && OpcIte != 4) || (Ite [OpcIte - 1].Est != 1 && (OpcIte == 1 || OpcIte == 2 || OpcIte == 3 || OpcIte == 4)));
			if (Ite [OpcIte - 1].Est == 1) Per.Pos.X = Ite [OpcIte - 1].Pos.X, Per.Pos.Y = Ite [OpcIte - 1].Pos.Y;
		}
	}
	system ("cls"); VisPla ();
}
VisPla ()
{
	int VerPon;
	do
	{
		printf ("Informacoes Atualizadas:\n\n");
		for (i = 0; i < 4; i ++)
		{
			if (Ite [i].Est == 1 && Ite [i].Pos.X == Per.Pos.X && Ite [i].Pos.Y == Per.Pos.Y && Per.Est == 1) Ite [i].Est = 0, Per.QuaIte ++;
			printf ("- Item %d -\n\n", i + 1);
			printf ("Codigo: %d\n", Ite [i].Cod);
			printf ("Nome: "); puts (Ite [i].Nom);
			if (Ite [i].Est == 0) printf ("Coletado na "); printf ("Coordenada (X,Y): %d,%d\n", Ite [i].Pos.X, Ite [i].Pos.Y);
			printf ("Estado: "); if (Ite [i].Est == 0) printf ("Coletado\n\n"); if (Ite [i].Est == 1) printf ("Disponivel\n\n");
		}
		printf ("- Personagem -\n\n");
		printf ("Codigo: %d\n", Per.Cod);
		printf ("Nome: "); puts (Per.Nom);
		printf ("Coordenada (X,Y): %d,%d\n", Per.Pos.X, Per.Pos.Y);
		printf ("Estado: "); if (Per.Est == 0) printf ("Morto\n"); if (Per.Est == 1) printf ("Vivo\n");
		printf ("Itens Coletados: %d\n\n", Per.QuaIte);
		printf ("O personagem sera representado por 'O' e os itens por 'X'...\n\n");
		for (i = 10; i > -11; i --)
		{
			for (j = -10; j < 11; j ++)
			{
				VerPon = 0;
				if (Per.Pos.Y == i && Per.Pos.X == j)
				{
					printf ("O"); VerPon = 2;
				}
				if (VerPon != 2)
				{
					for (k = 0; k < 4; k ++)
					{
						if (Ite [k].Est == 1 && Ite [k].Pos.Y == i && Ite [k].Pos.X == j)
						{
							printf ("X"); VerPon = 1;
						}
					}
				}
				if (VerPon != 2 && VerPon != 1)
				{
					if (i != 0 && j != 0) printf (".");
					if (i != 0 && j == 0) printf ("|");
					if (i == 0 && j != 0) printf ("-");
					if (i == 0 && j == 0) printf ("+");
				}
				if (i > -10 && j == 10) printf ("\n");
			}
		}
		if (Opc != '0') MovPer ();
	}
	while (Opc != '0');
	ArmInf = fopen ("[2020-12-22] Trabalho Avaliativo de Arquivos (Matheus Wiethan) - Save.txt", "wb");//Linha nova para criar/ editar o arquivo com os dados em binários.
	fwrite (&Ite, sizeof (DadIte), 4, ArmInf);//Linha nova para escrever as informações dos itens no arquivo.
	fwrite (&Per, sizeof (DadPer), 1, ArmInf);//Linha nova para escrever as informações do personagem no arquivo.
	fclose (ArmInf);//Linha nova para fechar o arquivo aberto.
	printf ("\n\nO jogo foi encerrado!\nPressione qualquer tecla para fechar..."); fflush (stdin); getch (); exit (0);
}

/*
A única forma de salvar o jogo atual é apertando a tecla zero.
Caso o programa em execução seja encerrado bruscamente, ele tecnicamente não saiu do "do {...} while".
Assim, o arquivo não é aberto para escrita das novas informações.
Por fim, podemos ver que com 22 linhas a mais, já é possível criar um sistema de salvamento e seleção de jogos de forma satisfatória.
*/
