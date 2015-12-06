#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "operaciones.h"


void agregar(struct nodo * lista){
	int num;
	printf("dame los valores a agregar\n presiona -1 si no quieres mas valores \n");
	while(1){
		printf("dame un numero: ");
		scanf("%d",&num);
		if(num == -1)
			break;
		insertar_al_final(lista,num);
	}
}
void intercambio(struct nodo * lista ,struct nodo *inicio, struct nodo *aux){
	struct nodo *actual;
	actual = lista;
	while(actual->sig != inicio){
		actual = actual->sig;
	}
	actual->sig = aux;
	aux->sig = inicio;
	borrar_elemento(inicio,aux->val);
}

void seleccion(struct nodo *lista){
	struct nodo *menor,*actual,*sig;
	actual = lista;
	menor = inicializar();
	while(actual->sig != NULL){
		actual = actual->sig;
		sig = actual;
		while(sig->sig != NULL){
			sig = sig->sig;
			if(sig->val < actual->val){
				menor->val = sig->val;
			}
			
		}
		intercambio(lista,actual,menor);
	}
}
int main(){
	struct nodo * lista;
	lista = inicializar();
	agregar(lista);
	imprimir_lista(lista);
	seleccion(lista);
	imprimir_lista(lista);
	return 0;
}
