#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "operaciones.h"

void menu(){
	printf("dime que opcion queres realizar de la pila \n");
	printf("1.- insertar(push)\n
		2.- borrar(pop)\n
		3.- mostrar(tope)\n
		4.- salir");
}
int main(){
	struct nodo *cabecera;
	int op,valor;
	cabecera = (struct nodo *) malloc(sizeof(struct nodo));
	inicializar(cabecera);
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("dame un numero: ");
				scanf("%d",&valor);
				push(cabecera,valor);
				break;
			case 2:
				pop(cabecera);
				break;
			case 3:
				tope(cabecera);
				break;
			case 4:
				break;
			default:
				printf("con ese boton no sales del programa\n
					a!! a!! a!! no presionaste la tecla magica\n
					a!! a!! a!!");
				break
		}
	}while(op != 4);
	borrar_lista(cabecera);
	
}
