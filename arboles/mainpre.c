#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "pila.h"
#include "listas.h"

void ingresar_datos(char *val){
	printf("dame todo los valores que quieres agregar: ");
	scanf("%s",val);
}
void insertar_en_lista(struct nodo * cola, char * val, int tam){
	int i;
	for(i=0; i < tam; i++){
		insertar_al_final(cola,val[i]);
	}
}
void prefijo(struct nodo *lista, struct nodo *ope, struct nodo *pre){
	struct nodo *actual;
	int prio = 0;
	actual = lista;
	while(actual->sig != NULL){
		actual = actual->sig;
		if(actual->val == '+'|| actual->val == '-'|| actual->val == '*'|| actual->val == '/'){
			push(ope,actual->val);
			prio++;
		}
	}
	actual = lista;
	while(prio > 0){
		actual = actual->sig;
		if(tope(ope) == '+' || tope(ope) == '-'){
			insertar_al_final(pre,tope(ope));
			pop(ope);
			prio --;
		}
		if(tope(ope) == '*' || tope(ope) == '/'){
			insertar_al_final(pre,tope(ope));
			pop(ope);
			prio--;
		}
		if(actual->val != '+' && actual->val != '-' && actual->val != '*' && actual->val != '/')
			insertar_al_final(pre,actual->val);
	}
	
	
}
int main(){
	struct nodo *ope, *cola, *pre;
	char *valores;
	int tam;
	printf("dime cuantos valores insgresaras \n");
	scanf("%d",&tam);
	tam = tam +(tam-1);
	valores = malloc(sizeof(char) * tam);
	ope = inicializar();
	cola = inicializar();
	pre = inicializar();
	ingresar_datos(valores);
	insertar_en_lista(cola,valores,tam);
	prefijo(cola,ope,pre);
	printf("infijo: ");
	imprimir_lista(cola);
	printf("prefijo: ");
	imprimir_lista(pre);
	free(ope);
	free(cola);
	free(pre);
	free(valores);
	return 0;
}
