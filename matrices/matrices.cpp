#include <stdio.h>

int main(){
	float arreglo1[3][3], arreglo2[3][3], mres[3][3], acu=0;
	int i,j,k;
	printf("programa que multiplica matrices de 3x3");
	printf("para la matriz 1 dame los sig datos\n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("dame el dato de la fila %d de la columna %d\n",j+1,i+1);
			scanf("%f",&arreglo1[j][i]);
		}
	}
	printf("para la matriz 2 dame el sig dato \n");
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf("dame el dato de la fila %d de la columna %d  \n ",j+1,i+1);
			scanf("%f", &arreglo2[j][i]);
		}
	}
	printf("las matrices que se multiplicaran son: \n");
	printf("matriz 1\n");
	for(i=0; i<3; i++){
		printf("[");
		for(j=0; j<3; j++){
			printf("%.2f, ",arreglo1[j][i]);
		}
		printf("]\n");
	}
	printf("matriz 2\n");
	for(i=0; i<3; i++){
		printf("[");
		for(j=0; j<3; j++){
			printf("%.2f, ",arreglo2[j][i]);
		}
		printf("]\n");
	}
	//se ejecutan las operaciones
	for(k=0; k<3; k++){
		for(i=0; i<3; i++){
			for(j=0; j<3; j++){
				acu = acu + arreglo1[j][k] * arreglo2[i][j];
			}
			mres[i][k]=acu;
			acu =0;
		}
	}
	//se muestra el resultado
	printf("el resultado es \n");
	for(i=0; i<3; i++){
		printf("[");
		for(j=0 ; j<3; j++){
			printf("%.2f, ",mres[j][i]);
		}
		printf("]\n");
	}
	return 0;
}
