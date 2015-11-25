#include "nodo.h"
#include "pila.h"
#include "listas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ingresar_datos(char *val){
	printf("dame todos los valores  que quieres agregar");
	scanf("%s",val);
}
void insertar_en_lista(struct nodo * cola, char *val, int tam){
	int i;
	for(i = 0 ; i < tam ; i++){
		insertar_al_final(cola,val[i]);
	}
}

void post_fijo(struct nodo * pila, struct nodo * cola, struct nodo *post){
	int prio=0,i;
	struct nodo *actual;
	actual = cola;
	while(actual->sig != NULL){
		actual= actual->sig;
		if(actual->val == '+' || actual->val == '-'){
			if(prio == 1 && (tope(pila) == '+'|| tope(pila) == '-')){
				insertar_al_final(post,tope(pila));
				pop(pila);
				push(pila,actual->val);
			}
			else
				push(pila,actual->val);
			if(prio == 2 && (tope(pila) == '*' || tope(pila) == '/')){
				insertar_al_final(post,tope(pila));
				pop(pila);
				insertar_al_final(post,tope(pila));
				pop(pila);
			}
			prio = 1;
		}
		if(actual->val == '*' || actual->val == '/'){
			if(prio == 2 && (tope(pila) == '*' || tope(pila) == '/')){
				insertar_al_final(post,tope(pila));
				pop(pila);
				push(pila,actual->val);
			}
			else
				push(pila,actual->val);
			prio = 2;
		}
		if(actual->val != '+' && actual->val != '-' && actual->val != '*' && actual->val != '/'){
			insertar_al_final(post,actual->val);
		}
	}
	printf("%d\n\n",prio);
	for(i = 0 ; i < prio; i++){
		insertar_al_final(post,tope(pila));
		pop(pila);
	}
}
int main(){
	int tam;
	char *valores;
	struct nodo *pila, *lista, *post;
	printf("dime cuantos valores ingresaras\n");
	scanf("%d",&tam);
	tam = tam + (tam -1);
	valores = malloc(sizeof(char) * tam );
	pila = inicializar();
	lista = inicializar();
	post = inicializar();
	ingresar_datos(valores);
	insertar_en_lista(lista,valores,tam);
	post_fijo(pila,lista,post);
	printf("infijo: ");
	imprimir_lista(lista);
	printf("postfijo: ");
	imprimir_lista(post);
	free(pila);
	free(lista);
	free(post);
	free(valores);
}
