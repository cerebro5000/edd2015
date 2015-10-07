#include <stdio.h>

int main(){
	float arrelglo1[3][3], arreglo2[3][3], mres[3][3], acu=0;
	int i,j,k,h;
	printf("programa que multiplica matrices de 3x3");
	printf("para la matriz 1 dame los sig datos");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("dame el dato de la fila %d de la columna %d\n",i+1,j+1);
			scanf("%d",&arreglo1[i][j]);
		}
	}
	printf("para la matriz 2 dame el sig dato ");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("dame el dato de la fila %d de la columna %d  \n ",i+1,j+1);
			scanf("%d", &arreglo[i][j]);
		}
	}
	printf("las matrices que se multiplicaran son: \n");
	for(i=0; i<3; i++){
		printf("[");
		for(j=0; j<3; j++){
			printf("%d,"arreglo1[i][j]);
		}
		printf("]\n");
	}
	for(i=0; i<3; i++){
		printf("[");\
		for(j=0; j<3; j++){
			printf("%d,"arreglo2[i][j]);
		}
		printf("]\n");
	}

	//comienzan las operaciones
	for(i=0; i<3; i++){
		for(j=0;j<3;j++){
			acu = acu + arreglo1[i][j]*arreglo2[j][i];
			mres[i][j]= acu;
		}
	}
	//mostrar resultado de matrices
	printf("el resultado es \n");
	for(i=0; i<3; i++){
		printf("[");
		for(j=0; j<=3; i++){
			printf("%d",mres[i][j]);
		}
		printf("]\n");
	}
}

