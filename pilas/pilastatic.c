#include "opestatic.h"
#include <stdio.h>

int menu(){
	int op;
	printf("elije la opcion que le quieres hacer a la pila\n");
	printf("1.- insertar dato(push)\n2.- eliminar dato (pop) \n3.- mostrar (tope) \n0.- salir\n");
	scanf("%d",&op);
	return op ;
}
int main(){
	int tam,dato,i=0,op;
	int pila[tam];
	printf("dame el tama~o de la pila\n");
	scanf("%d",&tam);
	inicializar(pila,tam);
	do{
		op = menu();
		switch(op){
			case 1:
				printf("dame el dato: ");
				scanf("%d",&dato);
				push(pila,tam,dato,i);
				i++;
				break;
			case 2:
				pop(pila,&i);
				break;
			case 3 :
				tope(pila,i);
				break;
			case 0:
				break;
			default:
				printf("esta pendejo dame el dato correcto");
				break;
		}
	}while(op != 0);
	return 0;
}
