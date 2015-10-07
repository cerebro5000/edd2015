#include <stdio.h>

int main(){
	float arreglo1[3][3], arreglo2[3][3], mres[3][3], acu=0;
	int i,j;
	printf("programa que multiplica matrices de 3x3");
	printf("para la matriz 1 dame los sig datos");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("dame el dato de la fila %d de la columna %d\n",j+1,i+1);
			scanf("%f",&arreglo1[j][i]);
		}
	}
	printf("para la matriz 2 dame el sig dato ");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("dame el dato de la fila %d de la columna %d  \n ",j+1,i+1);
			scanf("%f", &arreglo2[j][i]);
		}
	}
	printf("las matrices que se multiplicaran son: \n");
	printf("matriz 1");
	for(i=0; i<3; i++){
		printf("[");
		for(j=0; j<3; j++){
			printf("%.2f,",arreglo1[j]i]);
		}
		printf("]\n");
	}
	printf("matriz 2");
	for(i=0; i<3; i++){
		printf("[");
		for(j=0; j<3; j++){
			printf("%.2f,",arreglo2[i][j]);
		}
		printf("]\n");
	}

	//comienzan las operaciones
	for()
	for(j=0;j<3;j++){
		acu = acu + arreglo1[j][i] * arreglo2[i][j];
		mres[j][i] = acu;
	}
	acu =0;
	i=2;
	for(j=0; j<3; j++){
		acu = acu + arreglo1[j][i] * arreglo2[i][j];
		mres[j][i] = acu;
	}
	acu=0;
	i=3;
	for(j=0; j<3; j++){
		acu = acu + arreglo1[j][i] * arreglo2[i][j];
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
