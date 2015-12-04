#include <stdio.h>
#include <stdlib.h>

int * crea_arreglo(int *tam){
	int i,num,*a;
	printf("dime cuantos numeros quieres");
	scanf("%d",tam);
	a = (int *)malloc(sizeof(int)*(*tam));
	for(i=0; i < *tam; i++){
		printf("dame un numero: ");
		scanf("%d",&num);
		a[i]= num;
	}
	return a;
}
void imprimir(int *a, int tam){
	int i;
	for(i = 0 ; i < tam ; i++){
		printf("%d, ", a[i]);
	}
	printf("\n");
}
void burbuja(int *a,int tam){
	int i,j,aux;
	for(i = 1 ; i < tam; i++){
		for(j = 0 ; j < tam-1 ; j++){
			if(a[j] > a[j+1]){
				aux = a[j];
				a[j] = a[j+1];
				a[j+1] = aux;
			}
		}
	}
}
int main(){
	int *a, tam = 1;
	printf("metodo ordenamiento burbuja con arreglos\n");
	a = crea_arreglo(&tam);
	imprimir(a,tam);
	burbuja(a,tam);
	imprimir(a,tam);
	free(a);
	return 0;
}
