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
void intercambio(struct nodo *lista,struct nodo **inicio, struct nodo **val){
	struct nodo *aco,*aux;
	aco = *inicio;
	aux = lista;
	while(aux->sig->val != (*inicio)->val){
		aux = aux->sig;
	}
	while(aco->sig->val != val->val){
		aco = aco->sig;
	}
	if(aco->val != val->val){
		aco->sig = val->sig;
		val->sig = aux->sig;
		aux->sig = val;
	}
	(*inicio) = val;
}
void seleccion(struct nodo *lista){
	struct nodo *actual,*sig, *menor;
	actual = lista;
	while(actual->sig != NULL){
		actual = actual->sig;
		if(actual->sig != NULL)
			sig = actual->sig;
		else
			sig = actual;
		menor = sig;
		while(sig->sig != NULL){
			printf("%d < %d", sig->val , actual->val);
			if(sig->val < actual->val)
				menor = sig;
			sig = sig->sig;
		}
		intercambio(lista,&actual,&menor);
	}
}
int main(){
	struct nodo * lista;
	lista = inicializar();
	agregar(lista);
	imprimir_lista(lista);
	seleccion(lista);
	imprimir_lista(lista);
	free(lista);
	return 0;
}
