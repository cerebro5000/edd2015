#include<stdio.h>
#include<stdlib.h>

void *malloc(size_t size);

int main(){
	int *p, tam, i,numero;
	printf("dime de que tamano quieres el arreglo ");
	scanf("%d",&tam);
	p= (int *)malloc (tam * sizeof(int));
	for(i=0; i < tam; i++){
		printf("dame el numero del espacio %d \n",i+1);
		scanf("%d",&numero);
		p[i] = numero;
	}
	printf("el arreglo que has puesto es:\n");
	for(i=0; i < tam; i++){
		printf("%d \n",p[i]);
	}
	free(p);
}
