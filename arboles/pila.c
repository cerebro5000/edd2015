#include "pila.h"
#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>

struct nodo * inicializar(){
	struct nodo *cabecera;
	cabecera = (struct nodo*) malloc(sizeof(struct nodo));
	cabecera->sig = NULL;
	return cabecera;
}
void push(struct nodo *cabecera, char valor_nuevo){
	struct nodo *nuevo;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);
	nuevo-> val = valor_nuevo;
	nuevo->sig = cabecera->sig;
	cabecera->sig = nuevo;
}
void pop(struct nodo *cabecera){
	struct nodo *borrado;
	borrado = cabecera->sig;
	if(cabecera->sig != NULL){
		cabecera->sig = cabecera->sig->sig;
		free(borrado);
	}
	else{
		printf("pila vacia");
	}
}
char tope(struct nodo *cabecera){
	if(cabecera->sig != NULL)
		return cabecera->sig->val;
	return 0;
}
