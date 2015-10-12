#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//prototipos de funcion
void validarOperacion(int *x, int *y){
	if(*x == *y)
		printf("todo esta bien las operaciones se peuden realizar\n");
	else{
		printf("operacion invalida cerrando programa\n");
		usleep(9000);
		exit(0);
	}
}
void ingresarTamano(int *x, int *y){
	printf("ingresa el numero de columnas\n");
	scanf("%d",x);
	printf("ingrersa el numero de filas\n");
	scanf("%d",y);
}
float** crearM(int *y,int *x){
	float **m = (float**) malloc((*y) *sizeof(int*));
	for(int i = 0; i < *y; i++){
		m[i]= (float *) malloc((*x) *sizeof(int));
	}
	return m;
}
void ingresaDatos(float**matriz, int y, int x){
	float dato;
	for(int j =0 ; j < y ; j++){
		for(int i =0 ; i < x ; i++){
			printf("dame el dato para la columna %d fila %d \n",i+1,j+1);
			scanf("%f",&dato);
			matriz[j][i]=dato;
		}
	}
}
void imprimeM(float **matriz, int y, int x){
	for(int i=0; i<y; i++){
		printf("[");
		for(int j=0; j<x; j++){
			printf("%f, ",matriz[i][j]);
		}
		printf("] \n");
	}
}
void multiplicacion(float **m1, float**m2, float **res, int y, int x){
	float acu = 0;
	if(y<=x){
		for(int k=0; k < y; k++){
			for(int i=0; i < x; i++){
				for(int j=0; j < x; j++){
					acu = acu + m1[i][j] * m2[j][k];
				}
				res[i][k]=acu;
				acu=0;
			}
		}
	}
	else{
		for(int k=0; k < y; k++){
			for(int i=0; i < x; i++){
				for(int j=0; j < x; j++){
					acu = acu + m1[k][j] * m2[i][j];
				}
				res[k][i]=acu;
				acu=0;
			}
		}
	}
}
void liberarMem(float **m, int tam){
	for(int i=0; i<tam; i++)
		free(m[i]);
	free(m);
}
int main(){
	int c1,f1,c2,f2;
	float **m1,**m2,**mres;

	printf("programa que multiplica matrices de nxn \n");
	//se ingresan los tamanos de las matrices
	printf("dame el tamano de la matriz 1\n");
	ingresarTamano(&c1,&f1);
	printf("dame el tamano de la matriz 2 \n");
	ingresarTamano(&c2,&f2);

	//validamos si la operacion se peude realizar
	validarOperacion(&c1,&f2);

	//creamos las matrices
	m1 = crearM(&f1, &c1);
	m2 = crearM(&f2, &c2);

	mres = crearM(&f1, &c2);

	//se igresa datos a las matrices
	printf("ingresa los datos de las matrices:\n");
	printf("matriz 1\n");
	ingresaDatos(m1,f1,c1);
	printf("matriz 2\n");
	ingresaDatos(m2,f2,c2);

	//se imprimen las matrices
	printf("matriz 1\n");
	imprimeM(m1, f1, c1);
	printf("matriz 2\n");
	imprimeM(m2, f2, c2);

	//se ejecutan las operaciones
	multiplicacion(m1, m2, mres, f1, c2);
	//se muestra el resultado
	printf("el resultado es:\n");
	imprimeM(mres,f1,c2);

	//liberamos la memoria
	liberarMem(m1, f1);
	liberarMem(m2, f2);
	liberarMem(mres, f1);
	return 0;
}
