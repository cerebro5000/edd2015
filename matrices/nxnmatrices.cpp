#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

void validarOperacion(int *, int *);
void ingresarTamano(int *, int *);
void crearM(float**, int*, int*);
void ingresaDatos(float**, int, int);
void imprimeM(float**, int, int);
int main(){
	int tx1,ty1,tx2,ty2;
	float **m1,**m2,**mres;
	float arreglo1[3][3], arreglo2[3][3], acu=0;
	cout<<"programa que multiplica matrices de nxn"<<endl;
	//seingresan los tamanos de las matrices
	cout<<"dame los tamanos de la matriz 1"<<endl;
	ingresarTamano(&tx1,&ty1);
	cout<<"dame el tamano de la matriz 2 "<<endl;
	ingresarTamano(&tx2,&ty2);

	//validamos si la operacion se peude realizar
	validarOperacion(&tx1,&ty2);

	//creamos las matrices
	crearM(m1, &tx1, &ty1);
	crearM(m2, &tx2, &ty2);
	crearM(mres, &tx1, &ty2);

	//se igresa datos a las matrices
	cout<<"ingresa los datos de las matrices:"<<endl;
	cout<<"matriz 1"<<endl;
	ingresaDatos(m1,tx1,ty1);
	cout<<"matriz 2"<<endl;
	ingresaDatos(m2,tx2,ty2);

	//se imprimen las matrices


	//se ejecutan las operaciones
	for(int k=0; k<3; k++){
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				acu = acu + arreglo1[j][k] * arreglo2[i][j];
			}
			mres[i][k]=acu;
			acu =0;
		}
	}
	//se muestra el resultado
	cout<<"el resultado es"<<endl;
	for(int i=0; i<3; i++){
		cout<<"[";
		for(int j=0 ; j<3; j++){
			cout<<mres[j][i]<<",";
		}
		cout<<"]"<<endl;
	}
	return 0;
}
void validarOperacion(int *x, int *y){
	if(x==y)
		cout<<"todo esta bien las operaciones se peuden realizar"<<endl;
	else{
		cout<<"operacion invalida cerrando programa"<<endl;
		usleep(4000);
		exit(0);
	}
}
void ingresarTamano(int *x, int *y){
	cout<<"ingresa el numero de filas"<<endl;
	cin>>*x;
	cout<<"ingrersa el numero de columnas"<<endl;
	cin>>*y;
}
void crearM(float **m,int *x,int *y){
	m = new float*[*x];
	for(int i = 0; i < *y; i++){
		m[i]= new float[*y];
	}
}
void ingresaDatos(float**matriz,int x, int y){
	for(int j =0 ; j < y ; j++){
		for(int i =0 ; i < x ; i++){
			cout<<"dame el dato para la columna "<<x<<"fila "<<y<<endl;
			cin>>matriz[i][j];
		}
	}
}
void imprimeM(float **matriz,int x,int y){
	for(int i=0; i<y; i++){
		cout<<"[";
		for(int j=0; j<x; j++){
			cout<<matriz[j][i]<<", ";
		}
		cout<<"]"<<endl;
	}
}
