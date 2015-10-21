#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "operaciones.h"

int main(){
	struct nodo *cabecera;
	int valor;
	cabecera = (struct nodo*) malloc(sizeof(struct nodo));
	inicializar(cabecera);
	printf("presiona -1 si quieres dejar de meter datos");
	while(1){
		printf("inserta un numero: ");
		scanf("%d",&valor);
		if(valor == -1)
			break;
		insertar_al_final(cabecera,valor);
	}
	imprimir_lista(cabecera);
	printf("dame el dato que quiereas eliminar ");
	scanf("%d",&valor);
	borrar_elemento(cabecera,valor);
	printf("eliminado \n");
	imprimir_lista(cabecera);
	borrar_lista(cabecera);
	return 0;
}
