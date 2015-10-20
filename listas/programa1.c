#include <stdio.h>
#include "nodo.h"
#include "operaciones.h"


int main (){
	struct nodo *cabecera;
	int valor;
	printf(" si mandas -1 veras la lista y saldras el programa\n"); 
	scanf("%d", &valor);
	inicializar(cabecera);
	while (valor != -1){
		insertar_al_final(cabecera, valor);
	}
	imprimir_lista(cabecera);
	
	return 0;
}
