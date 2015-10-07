#include <stdio.h>

int main(){
	float arreglo1[3][3], arreglo2[3][3], mres[3][3], acu=0;
	int i,j;
	printf("programa que multiplica matrices de 3x3");
	printf("para la matriz 1 dame los sig datos");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("dame el dato de la fila %f de la columna %f\n",i+1,j+1);
			scanf("%f",&arreglo1[i][j]);
	}
	printf("para la matriz 2 dame el sig dato ");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("dame el dato de la fila %f de la columna %f  \n ",i+1,j+1);
			scanf("%f", &arreglo2[i][j]);
		}
	}
	printf("las matrices que se multiplicaran son: \n");
	for(i=0; i<3; i++){
		printf("[");
		for(j=0; j<3; j++){
			printf("%f,",arreglo1[i][j]);
		}
		printf("]\n");
	}
	for(i=0; i<3; i++){
		printf("[");\
		for(j=0; j<3; j++){
			printf("%f,",arreglo2[i][j]);
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
			printf("%f,",mres[i][j]);
		}
		printf("]\n");
	}
}
