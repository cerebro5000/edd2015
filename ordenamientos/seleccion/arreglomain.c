#include <stdio.h>
#include <stdlib.h>

int * inicializar(int *tam){
	int *a;
	printf("de cuantos espacios quieres el arreglo\n");
	scanf("%d",tam);
	a = (int *) malloc(sizeof(int) * (*tam));
	return a;
}
void imprimir(int * a, int tam){
	int i;
	for(i = 0 ; i < tam ; i++){
		printf("%d, ",a[i]);
	}
	printf("\n");
}
void ingresa(int *a, int tam){
	int i, num;
	for(i = 0 ; i < tam ; i++){
		printf("dame un numero:");
		scanf("%d",&num);
		a[i] = num;
	}
}
void seleccion(int *a,int tam){
	int i,j,menor,aux;
	for(i = 0 ; i < tam ; i++){
		menor = i;
		for(j = i ; j < tam ; j++){
			if(a[j] < a[i] )
			menor = j;
		}
		aux = a[i];
		a[i] = a[menor];
		a[menor] = aux;
	}
}
int main(){
	int *a, tam;
	a = inicializar(&tam);
	ingresa(a, tam);
	imprimir(a, tam);
	seleccion(a,tam);
	imprimir(a,tam);
	return 0;
}
