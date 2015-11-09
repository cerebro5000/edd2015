#include "nodo.h"
#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct nodo cola;

int menu();
void operaciones(cola cabecera, int dato, int op);
int main(){
	struct nodo * cabecera;
	int dato,op;
	cabecera = (struct nodo *) malloc (sizeof(struct nodo));
	inicializar(cabecera);
	printf("programa que realiza una cola con listas dinamicas\n");
	do{
		op = menu();
		operaciones(cabecera,dato,op);
		
	}while(op != 4);
	borrar_lista(cabecera);
	return 0;
}
int menu(){
	printf("selecciona que accion queres realizar \n
		1.- inserta dato\n
		2.- elimina un dato\n
		3.- imprimir cola\n
		4.- salir");
		scanf("%d",&op);
}
void operaciones(cola cabecera, int dato, int op){
	switch(op){
		case 1:
			intertar_al_final(cabecera);
			break;
		case 2:
			eliminar_al_principio();
			break;
		case 3:
			imprimir_lista(cabecera);
			break;
		case 4:
			break;
		default:
			printf("valor invalido escoge otra vez");
			break;
	}
}
