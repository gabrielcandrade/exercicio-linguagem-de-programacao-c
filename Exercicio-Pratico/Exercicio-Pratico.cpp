// Exercicio-Pratico.cpp
// Autor: Gabriel de Carvalho Andrade - 1810021814
// Professor: Leandro Figueiredo Alves - Introdução a Linguagem de Programação

#include "pch.h"
#include <iostream>
#include <ctype.h>
#include <math.h>

void menu();
void realizaFatorial();
void verificaPrimo();
void verificaVariosPrimos();
void fazExpoente();
void fazRaiz();
void anoBissexto();
void mediaNotas();
void mediaPonderada();
void matriculaEmHexadecimal();

int main()
{
	// Questao 1
	int opcao = 0;

	menu();

	printf("\nEscolha uma opcao: 0 a 9: ");
	scanf_s("%d", &opcao);
	system("cls");

	switch (opcao) {
	case 1: {
		realizaFatorial();
		break;
	}
	case 2: {
		verificaPrimo();
		printf("\nObrigado pela preferencia.\n\n");
		break;
	}
	case 3: {
		verificaVariosPrimos();
		break;
	}
	case 4: {
		fazExpoente();
		break;
	}
	case 5: {
		fazRaiz();
		break;
	}
	case 6: {
		anoBissexto();
		break;
	}
	case 7: {
		mediaNotas();
		break;
	}
	case 8: {
		mediaPonderada();
		break;
	}
	case 9:{
		matriculaEmHexadecimal();
		break;
	}
	case 0: {
		printf("\nMas ja vai? Tudo beleza! Até logo.\n");
		break;
	}
	default: {
		printf("Numero invalido, tenta denovo!");
		break;
	}
	}
	return 0;
}

// Menu
void menu() {
	printf("###########################################\n");
	printf("#                                         #\n");
	printf("#        Menu da atividade pratica        #\n");
	printf("#                                         #\n");
	printf("#   1 - Realiza fatorial;                 #\n");
	printf("#   2 - Verifica numero primo;            #\n");
	printf("#   3 - Verifica varios numeros primos;   #\n");
	printf("#   4 - Coloca em expoente;               #\n");
	printf("#   5 - Coloca em raiz;                   #\n");
	printf("#   6 - Ano bissexto;                     #\n");
	printf("#   7 - Media de notas;                   #\n");
	printf("#   8 - Media ponderada;                  #\n");
	printf("#   9 - Matricula em hexadecimal;         #\n");
	printf("#   0 - Sair;                             #\n");
	printf("#                                         #\n");
	printf("###########################################\n");
}

// Questao 2
void realizaFatorial() {
	int numero;
	printf("Digite um numero que eu direi o seu fatorial: ");
	scanf_s("%d", &numero);

	int resultado = 1;

	if (numero == 0) {
		resultado = 0;
		printf("Por definicao: o valor de %d! eh: %d \n\n", numero, resultado);
		return;
	}
	
	for (int i = numero; i > 1; i--) {
		resultado *= i;
	}
	
	printf("O valor de %d! eh: %d \n\n", numero, resultado);
	printf("\nObrigado pela preferencia.\n\n");
}

// Questao 3
void verificaPrimo() {
	int numero = 0;
	printf("Digite um numero que te direi se ele eh primo: ");
	scanf_s("%d", &numero);

	int qntDivisao = 0;
	for (int i = numero; i > 0; i--) {
		int resto = numero % i;
		if (resto == 0) {
			qntDivisao++;
		}
	}
	if (qntDivisao > 2) {
		printf("O numero %d nao eh primo.\n", numero);
	}
	else {
		printf("O numero %d eh primo.\n", numero);
	}
}

// Questao 4
void verificaVariosPrimos() {
	char decisao = 's';
	
	while (decisao == 's') {
		verificaPrimo();
		printf("\nVoce deseja verificar outro numero se eh primo? (s/n): ");
		scanf_s(" %c", &decisao);
		decisao = tolower(decisao);
	}
	printf("\nObrigado pela preferencia.\n\n");
}

// Questao 5
void fazExpoente() {
	double numeroA, expoente;
	int numeroB;

	printf("Digite um numero contendo um ponto flutuante: ");
	scanf_s("%lf", &numeroA);
	printf("Digite um numero que seja apenas inteiro: ");
	scanf_s("%d", &numeroB);

	expoente = pow(numeroA, numeroB);

	double resultado = 0;
	int qntExpDez = 0;
	if (expoente > 10) {
		while (expoente > 10) {
			resultado = expoente / 10.0;
			expoente = resultado;
			qntExpDez++;
		}
	}
	
	printf("Na base 10, temos: %.2lfe%d", expoente, qntExpDez);
	printf("\nObrigado pela preferencia.\n\n");
}

// Questao 6
void fazRaiz() {
	double numeroA, expoente, raiz;
	int numeroB;

	printf("Digite um numero contendo um ponto flutuante: ");
	scanf_s("%lf", &numeroA);
	printf("Digite um numero que seja apenas inteiro: ");
	scanf_s("%d", &numeroB);

	expoente = 1.0 / (float)(numeroB);

	raiz = pow(numeroA, expoente);

	double resultado = 0;
	int qntExpDez = 0;
	if (raiz > 10) {
		while (raiz > 10) {
			resultado = raiz / 10.0;
			raiz = resultado;
			qntExpDez++;
		}
	}

	printf("Na base 10, temos: %.2lfe%d\n", raiz, qntExpDez);
	printf("\nObrigado pela preferencia.\n\n");
}

// Questao 7
void anoBissexto() {
	int ano;

	printf("Digite um ano, sem abreviacoes, e eu te direi se ele eh bissexto: ");
	scanf_s("%d", &ano);

	if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) {
		printf("O ano %d eh bissexto.", ano);
	}
	else {
		printf("O ano %d NAO eh bissexto.", ano);
	}
}

// Questao 8
void mediaNotas() {
	double nota1, nota2, media;

	printf("Nesse sistema, usaremos a media aritmetrica.\n");
	printf("Digite a primeira nota do aluno: ");
	scanf_s("%lf", &nota1);
	printf("Digite a segunda nota do aluno: ");
	scanf_s("%lf", &nota2);

	if (nota1 > 0.0 && nota1 < 10.0 && nota2 > 0.0 && nota2 < 10.0) {
		media = (nota1 + nota2) / 2.0;
		printf("A media do aluno foi: %.2f", media);
	}
	else {
		printf("Notas invalidas. Programa sera fechado.");
	}
}

// Questao 9
void mediaPonderada() {
	double nota1, nota2, nota3, resultadoProva1, resultadoProva2, resultadoProva3, mediaPonderada;

	printf("Nesse sistema, usaremos a media ponderada.\n");
	printf("Digite a primeira nota do aluno: ");
	scanf_s("%lf", &nota1);
	printf("Digite a segunda nota do aluno: ");
	scanf_s("%lf", &nota2);
	printf("Digite a terceira nota do aluno: ");
	scanf_s("%lf", &nota3);

	resultadoProva1 = nota1 * 1.0;
	resultadoProva2 = nota2 * 1.0;
	resultadoProva3 = nota3 * 2.0;

	mediaPonderada = (resultadoProva1 + resultadoProva2 + resultadoProva3) / 5.0;

	if (mediaPonderada <= 6.0) {
		printf("Voce foi aprovado com media: %.2f\n", mediaPonderada);
	}
	else {
		printf("Infelizmente voce nao atingiu a media de 6.0, sua media foi %.2f", mediaPonderada);
	}
}

// Questao 10
void matriculaEmHexadecimal() {
	int matricula = 1810021814;

	printf("Nome: Gabriel de Carvalho Andrade\n");
	printf("Matricula: 1810021814\n");
	
	printf("Matricula em Hexadecimal: %X\n", matricula);
}


// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
