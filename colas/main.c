#include "nodo.h"
#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct nodo * cola;

int menu();
void operaciones(cola cabecera, int op);
int main(){
	cola cabecera;
	int op;
	cabecera = (struct nodo *) malloc (sizeof(struct nodo));
	inicializar(cabecera);
	printf("programa que realiza una cola con listas dinamicas\n");
	do{
		op = menu();
		operaciones(cabecera,op);
		
	}while(op != 4);
	borrar_lista(cabecera);
	return 0;
}
int menu(){
	int op;
	printf("selecciona que accion queres realizar \n1.- inserta dato\n2.- elimina un dato\n3.- imprimir cola\n4.- salir\n");
	scanf("%d",&op);
	return op;
}
void operaciones(cola cabecera, int op){
	int dato;
	switch(op){
		case 1:
			printf("dame un dato para insertar: ");
			scanf("%d",&dato);
			insertar_al_final(cabecera,dato);
			break;
		case 2:
			borrar_al_principio(cabecera);
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
