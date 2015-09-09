#include <stdio.h>
#include "funciones.h"

enum operaciones{
	SUMA = 1,
	RESTA = 2,
	MULTIPLICACION = 3,
	DIVISION = 4
};

void imprime_menu(){
	printf("1.- suma \n");
	printf("2.- resta \n");
	printf("3.- multiplicacion\n");
	printf("4.- division\n");
	printf("5.- salir\n");
	
}

void introducir_datos(float *num1, float *num2){
	float num;
	printf("introduce el primer numero\n");
	scanf("%f",&num);
	*num1 = num;
	printf("introduce el segundo numero\n");
	scanf("%f",&num);
	*num2 = num;
}

void imprimir_resultado(float res){
	printf("el resultado es: %5.2f\n", res);
}
int main(){
	int opcion;
	float numero1, numero2, resultado;
	printf("programa calculadora\n");
	do{
		imprime_menu();
		scanf("%d" , &opcion);
		switch(opcion){
			case SUMA:
				introducir_datos(&numero1, &numero2);
				resultado = suma(numero1 , numero2);
				imprimir_resultado(resultado);
			break;
			case RESTA:
				introducir_datos(&numero1, &numero2);
				resultado = resta(numero1, numero2);
				imprimir_resultado(resultado);
			break;
			case MULTIPLICACION:
			break;
			case DIVISION:
			break;
			default:
			break;
		}	
	}while(opcion != 5);
	return 0;
}
