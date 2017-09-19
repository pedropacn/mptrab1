#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/lista_func.hpp"

int ehNum(char ch){
	if(ch >= 48 && ch <= 57)
		return 1;
	return 0;
}

int ehDelimitador(const char * str, t_lista * l){
	t_elemento * ele = l->inicio;
	while(ele != NULL){
		if(!strcmp(str, ele->delimitador))
			return 1;
		ele = ele->proximo;
	}
	return 0;
}

int tamanho_de_tipo(int posicao_inicial, const char * str){
	int tamanho = 0;
	if(ehNum(str[posicao_inicial])){
		while (ehNum(str[posicao_inicial + tamanho]))
			++tamanho;
	}else{
		while (!ehNum(str[posicao_inicial + tamanho]) && str[posicao_inicial + tamanho] != '\n'){
			++tamanho;
		}
	}
	return tamanho;
}

int limpa_string(char * str){
	for (int i = 0; i < strlen(str); ++i)
		str[i] = 'n';
	return 1;
}

int copia_trecho_de_string(int posicao_inicial, int intervalo, const char * string_entrada, char string_destino[10]){
	int i = 0;
	for (i = 0; i < intervalo; ++i){
		string_destino[i] = string_entrada[posicao_inicial + i];
	}
	string_destino[i] = '\0';
	return 1;
}

int adiciona_delimitador(t_lista * lista, const char * str){
	int posicao = 0, controle = 0;
	char temp[20];
	while(str[posicao] != '\n'){
		if(str[posicao] == '['){
			int i = 0;
			++posicao;
			while(str[posicao] != ']'){
				temp[i] = str[posicao];
				++i;
				++posicao;
			}
			temp[i] = '\0';
			insereInicio(temp, lista);
		}
		++posicao;
	}
	return posicao + 1;
}

int soma_string(const char * string_entrada){
	int soma = 0;
	int total_numeros = 0, total_delimitadores = 0, delimitadores = 0, numeros = 0;/*variaveis de controle*/
	int tamanho = strlen(string_entrada);
	char string_em_analise[10];
	if(string_entrada[tamanho - 1] != '\n')/*caso a tring não termine em \n*/
		return -1;
	if(!ehNum(string_entrada[0]) && string_entrada[0] != '/')/*caso a string comece com um caracter invalido*/
		return -1;
	int posicao_inicial_de_numeros = 0;
	t_lista * lista_de_delimitadores;
	lista_de_delimitadores = criarLista();
	insereInicio(",", lista_de_delimitadores);
	if(string_entrada[0] == '/' && string_entrada[1] == '/'){
		/* significa que delimitadores serão adicionados */
		posicao_inicial_de_numeros = adiciona_delimitador(lista_de_delimitadores, string_entrada);
	}
	for (int i = posicao_inicial_de_numeros; i < tamanho; ++i){
		if (string_entrada[i] != '\n'){
			limpa_string(string_em_analise);
			int tamanho_tipo = tamanho_de_tipo(i, string_entrada);
			copia_trecho_de_string (i, tamanho_tipo, string_entrada, string_em_analise);
			if(ehNum (string_em_analise[0])){
				if(strlen(string_em_analise)>= 4){/*caso de ser um numero maior que 999*/
					soma += (atoi(string_em_analise)/pow(10, tamanho_tipo - 1));
				}else
					soma += atoi(string_em_analise);
				++numeros;
				++total_numeros;
			}else if(ehDelimitador (string_em_analise, lista_de_delimitadores)){
				++delimitadores;
				++total_delimitadores;
			}else{/* caso não seja um delimitador valido */
				return -1;
			}
			i += tamanho_tipo - 1;
		}else{/* caso encontre uma quebra de linha*/
			delimitadores = 0;/* reseta a quantidade delimitadores e de numeros pois esta em uma nova linha*/ 
			numeros = 0;
		}
		if(delimitadores > 3 || numeros > 3){/*isso limita a quantidade de delimitadores e de numeros por linha*/
			return -1;
		}
	}
	if(total_numeros <= 1)
		return -1;
	if(total_delimitadores != total_numeros -1)/*caso do numero de delimitadores seja maior do que o necessario*/
		return -1;
	return soma;
}