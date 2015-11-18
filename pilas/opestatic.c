#include <stdio.h>
#include <stdlib.h>
#include "opestatic.h"

void inicializar(int a[], int tam){
	int i;
	for(i=0 ; i < tam; i++){
		a[i] = 0 ;
	}
}
void push(int a[], int tam, int dato,int pos){
	if(pos < tam)
		a[pos] = dato;
	else
		printf("pila llena\n");
}
void tope(int a[],int i){

	printf("el ultimo dato de la pila es \n %d \n",a[i-1]);
}

void pop(int a[] ,int *pos){
	if(*pos > 0){
		a[*pos]=0;
		pos--;
	}
	else
		printf("pila vacia");
}
