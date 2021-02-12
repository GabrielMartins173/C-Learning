#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

	char role[20];
	unsigned comission;

} funcao;

typedef struct{

	char palavra[300];

} dict;

bool procuraPalavra(funcao *, char *, unsigned short);
unsigned short posicao;

void main ()
{

	unsigned short numPalavras, numberOfRoles;
	char texto[10000], *palavraTmp;
	unsigned long qtsSalarioTotal;
	dict dicionario[10000];
	unsigned short i, j;

	scanf("%hu %hu", &numPalavras, &numberOfRoles);

	funcao cargos[numPalavras];
	memset(cargos, 0, sizeof(cargos));

	for (i = 0; i < numPalavras; i++)
			scanf(" %s %u", cargos[i].role, &cargos[i].comission);

	while (numberOfRoles--)
	{

		qtsSalarioTotal = 0;
		while (true)
		{

			// Leitura do texto descritivo de funções;
			scanf(" %[^\n]", texto);

			// O caractere '.' marca o final de um caso de teste;
			// Podem haver várias strings em várias linhas diferentes de entrada;
			if (strcmp(texto, ".") == 0)
				break;

			i = 0;
			palavraTmp = strtok(texto, " ");
			strcpy(dicionario[i++].palavra, palavraTmp);

			// Separação da string em palavras individuais
			// Usando o caractere espaço como token;
			do
			{

				palavraTmp = strtok('\0', " ");

				if (palavraTmp)
					strcpy(dicionario[i++].palavra, palavraTmp);

			} while (palavraTmp);

			// Laço itera sobre as structs dicionario e cargos. Soma
			// Os valores para os quais existem descrição na string texto;
			for (j = 0; j < i; j++)
				if (procuraPalavra(cargos, dicionario[j].palavra, numPalavras))
					qtsSalarioTotal += cargos[posicao].comission;

		}

		// Impressão do resultado final;
		printf("%lu\n", qtsSalarioTotal);

	}

}

// Função procura no vetor determinada palavra passada como parâmetro;
bool procuraPalavra(funcao *cargos, char *palavra, unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		if (strcmp(cargos[i].role, palavra) == 0)
		{
			posicao = i;
			return true;
		}

	return false;

}