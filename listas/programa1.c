#include <stdio.h>
#include "nodo.h"
#include "operaciones.h"
#include <stdlib.h>


int main (){
	struct nodo *cabecera;
	int valor;
	cabecera = (struct nodo*) malloc(sizeof(struct nodo));
	inicializar(cabecera);
	printf(" si mandas -1 veras la lista y saldras el programa\n");
	while(1){
		printf("dame un numero: ");
		scanf("%d",&valor);
		if(valor==-1)
			break;
		insertar_al_final(cabecera, valor);
	}
	imprimir_lista(cabecera);
	borrar_lista(cabecera);
	return 0;
}
