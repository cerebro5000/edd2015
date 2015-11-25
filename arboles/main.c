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
void insertar_en_lista(struct nodo * cola, char *val, int tam, struct nodo *pila){
	int i;
	char a;
	for(i = 0 ; i < tam ; i++){
		insertar_al_final(cola,val[i]);
	}
}

void post_fijo(struct nodo * pila, struct nodo * cola, struct nodo *post){
	int prio=0;
	struct nodo *actual;
	actual = cola;
	while(actual->sig != NULL){
		actual= actual->sig;
		if(actual->val == '+' || actual->val == '-'){
			if(prio == 1 && tope(pila) == '+'){
				insertar_al_final(post,tope(pila));
				pop(pila);
			}
			else
				push(pila,actual->val);
			prio = 1;
		}
		if(actual->val == '*' || actual->val == '/'){
			if(prio == 2 && tope(pila) == '*'){
				insertar_al_final(post,tope(pila));
				pop(pila);
				insertar_al_final(post,tope(pila));
				pop(pila);
			}
			else
				push(pila,actual->val);
			prio = 2;
		}
		if(actual->val != '+' && actual->val != '-' && actual->val != '*' && actual->val != '/'){
			insertar_al_final(post,actual->val);
		}
	}
}
int main(){
	int tam,n;
	char valores[n];
	struct nodo *pila, *lista, *post;
	printf("dime cuantos valores ingresaras\n");
	scanf("%d",&tam);
	n = tam + (tam-1);
	pila = inicializar();
	lista = inicializar();
	post = inicializar();
	ingresar_datos(valores);
	insertar_en_lista(lista,valores,n,pila);
	post_fijo(pila,lista,post);
	imprimir_lista(lista);
	free(pila);
	free(lista);
	free(post);
}
