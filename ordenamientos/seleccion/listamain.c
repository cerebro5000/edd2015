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
void intercambio(struct nodo *inicio, struct nodo *aux){
	borrar_elemento(inicio,aux->val);
	aux->sig = inicio->sig;
	inicio->sig = aux;
}

void seleccion(struct nodo *lista){
	struct nodo *menor,*actual,*sig;
	actual = lista;
	menor = inicializar();
	sig = actual->sig;
	while(actual->sig != NULL){
		menor->val = actual->sig->val;
		while(sig->sig != NULL){
			if(sig->val < menor->val){
				menor->val = sig->val;
			}
			sig = sig->sig;
			
		}
		intercambio(actual,menor);
		actual = actual->sig;
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
