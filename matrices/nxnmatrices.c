#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

//prototipos de funcion
void validarOperacion(int *, int *);
void ingresarTamano(int *, int *);
float** crearM( int*, int*);
void ingresaDatos(float**, int, int);
void imprimeM(float**, int, int);
void multiplicacion(float **, float**, float **, int, int);
void liberarMem(float**, int);

int main(){
	int c1,f1,c2,f2;
	float **m1,**m2,**mres;

	cout<<"programa que multiplica matrices de nxn"<<endl;
	//se ingresan los tamanos de las matrices
	cout<<"dame el tamano de la matriz 1"<<endl;
	ingresarTamano(&c1,&f1);
	cout<<"dame el tamano de la matriz 2 "<<endl;
	ingresarTamano(&c2,&f2);

	//validamos si la operacion se peude realizar
	validarOperacion(&c1,&f2);

	//creamos las matrices
	m1 = crearM(&f1, &c1);
	m2 = crearM(&f2, &c2);

	mres = crearM(&f1, &c2);

	//se igresa datos a las matrices
	cout<<"ingresa los datos de las matrices:"<<endl;
	cout<<"matriz 1"<<endl;
	ingresaDatos(m1,f1,c1);
	cout<<"matriz 2"<<endl;
	ingresaDatos(m2,f2,c2);

	//se imprimen las matrices
	cout<<"matriz 1"<<endl;
	imprimeM(m1, f1, c1);
	cout<<"matriz 2"<<endl;
	imprimeM(m2, f2, c2);

	//se ejecutan las operaciones
	multiplicacion(m1, m2, mres, f1, c2);
	//se muestra el resultado
	cout<<"el resultado es:"<<endl;
	imprimeM(mres,f1,c2);

	//liberamos la memoria
	liberarMem(m1, f1);
	liberarMem(m2, f2);
	liberarMem(mres, f1);
	return 0;
}
void validarOperacion(int *x, int *y){
	if(*x == *y)
		cout<<"todo esta bien las operaciones se peuden realizar"<<endl;
	else{
		cout<<"operacion invalida cerrando programa"<<endl;
		usleep(9000);
		exit(0);
	}
}
void ingresarTamano(int *x, int *y){
	cout<<"ingresa el numero de columnas"<<endl;
	cin>>*x;
	cout<<"ingrersa el numero de filas"<<endl;
	cin>>*y;
}
float** crearM(int *y,int *x){
	float **m = new float*[*y];
	for(int i = 0; i < *y; i++){
		m[i]= new float[*x];
	}
	return m;
}
void ingresaDatos(float**matriz, int y, int x){
	for(int j =0 ; j < y ; j++){
		for(int i =0 ; i < x ; i++){
			cout<<"dame el dato para la columna "<<i+1<<"fila "<<j+1<<endl;
			cin>>matriz[j][i];
		}
	}
}
void imprimeM(float **matriz, int y, int x){
	for(int i=0; i<y; i++){
		cout<<"[";
		for(int j=0; j<x; j++){
			cout<<matriz[i][j]<<", ";
		}
		cout<<"]"<<endl;
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
		delete [] m[i];
	delete m;
}
