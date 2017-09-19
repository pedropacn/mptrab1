#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento{
	char delimitador[20];
	struct elemento * proximo;
}t_elemento;

typedef struct lista{
	t_elemento * inicio;
	t_elemento * fim;
}t_lista;

t_lista * criarLista(){
    t_lista * l = (t_lista *)malloc(sizeof(t_lista));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

void insereInicio(char str[20], t_lista * l){
  t_elemento * novoprimeiro = (t_elemento *)malloc(sizeof(t_elemento));
  strcpy(novoprimeiro->delimitador, str);
  novoprimeiro->proximo = l->inicio;
  l->inicio = novoprimeiro;
  if(l->fim == NULL)
    l->fim = novoprimeiro;
}

int lista_tamanho(t_lista * l){
    t_elemento * atual = l->inicio;
    int cont = 0;
    while(atual != NULL){
       atual = atual->proximo;
       ++cont;
    }   
    return cont;
}

void imprimir(t_lista * l){
    t_elemento * atual = l->inicio;
    while(atual != NULL){
       puts(atual->delimitador);
       atual = atual->proximo;
    }   
}