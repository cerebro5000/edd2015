#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "operaciones.h"

void ordenar(struct nodo *cabecera){
        struct nodo *actual, *sigi, *antes;
        int i=0;
        if(cabecera->sig != NULL){
                while(!i){
                        i =1;
                        antes = cabecera;
                        actual = antes->sig;
                        sigi = actual->sig;
                        while(actual->sig != NULL){
                                if(actual->val > sigi->val){
                                        antes->sig = sigi;
                                        actual->sig = sigi->sig;
                                        sigi->sig = actual;
                                        i=0;
                                }
                                antes = antes->sig;
                                actual = antes->sig;
                                sigi = actual->sig;
                        }
                }
        }
}

int main(){
	struct nodo *lista;
	int val;
	lista = inicializar();
	printf("ordenamiento burbuja en listas");
	while(1){
		printf("ingresa un dato \n ingresa -1 si no queires mas datos");
		scanf("%d",&val);
		if(val == -1)
			break;
		insertar_al_final(lista,val);
	}
	printf("antes de ordenar: ");
	imprimir_lista(lista);
	ordenar(lista);
	printf("despues de ordenado: ");
	imprimir_lista(lista);
	return 0;
}
