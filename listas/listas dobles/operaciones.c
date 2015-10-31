#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(struct nodo *cabecera){
	cabecera->sig = NULL;
	cabecera->ant = NULL;
}
void insertar_al_principio(struct nodo *cabecera, int valor_nuevo){
	struct nodo *nuevo;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo) * 1);

	nuevo-> val = valor_nuevo;
	nuevo->sig = cabecera->sig;
	nuevo->ant = cabecera;
	cabecera->sig = nuevo;
}
void insertar_al_final(struct nodo *cabecera, int valor_nuevo){
	struct nodo *nuevo;
	struct nodo *actual;

	actual = cabecera;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo) *1);
	nuevo->val = valor_nuevo;
	while(actual->sig != NULL){
		actual =actual->sig;
	}
	nuevo->sig = actual->sig;
	nuevo->ant = actual;
	actual->sig= nuevo;
}
void insertar_despues_de(struct nodo *cabecera, int valor_nuevo, int valor_antes){
	struct nodo *nuevo;
	struct nodo *actual;
	nuevo = (struct nodo*) malloc(sizeof(struct nodo)*1);
	nuevo->val = valor_nuevo;
	actual = cabecera;
	while(actual->sig != NULL){
		actual = actual->sig;
		if(actual->val == valor_antes){
			nuevo->sig = actual->sig;
			nuevo->ant = actual;
			actual->sig = nuevo;
			break;
		}
	}
}
void imprimir_lista(struct nodo * cabecera){
	struct nodo *actual;
	actual = cabecera;
	while(actual->sig != NULL){
		actual = actual->sig;
		printf("%d, ",actual->val);
	}
	printf("\n");
}

void borrar_lista(struct nodo *cabecera){
	struct nodo *actual;
	struct nodo *borrar;

	if (cabecera->sig != NULL) {
		actual = cabecera->sig;
		borrar = cabecera->sig;
		while ( actual->sig != NULL) {
			actual = actual->sig;
			free(borrar);
			borrar = actual;
		}
		free(borrar);
		cabecera->sig = NULL;
	}
}

void borrar_elemento(struct nodo *cabecera, int valor){
	struct nodo *actual;
	struct nodo *borrar;
	borrar = cabecera;
	actual = cabecera;
	while(actual->sig != NULL){
		borrar = borrar->sig;
		if(borrar->val == valor){
			actual->sig = borrar->sig;
			actual->ant->ant = actual;
			free(borrar);
		}
		actual = actual->sig;
	}
}
