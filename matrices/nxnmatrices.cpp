#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

void multiplicacion(float *a, float *b, float **c);
void mostrarDatos(float **c, int *a, int *b);
void validarOmatriz(int a, int b);
void pedirTamanos(int *a, int *b);
int main(){
	int tamx1, tamy1, tamx2,tamy2;
	float arreglo1[tamx1][tamy1], arreglo2[tamx2][tamy2], mres[3][3], acu=0;
	cout<<"programa que multiplica matrices de nxn"<<endl;
	cout<<"agrega el tamano de la mtriz 1"<<endl;
	pedirTamanos(&tamx1,&tamy1);
	cout<<"agrega el tamano de la matriz 2"<<endl;
	pedirTamanos(&tamx2,&tamy2);
	validarOmatriz(tamx1, tamy2);
	cout<<"para la matriz 1 dame los sig datos"<<endl;
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<"dame el dato de la fila "<<j+1<<" de la columna"<<i+1<<endl;
			cin>>arreglo1[j][i];
		}
	}
	cout<<"para la matriz 2 dame el sig dato "<<endl;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout<<"dame el dato de la fila "<<j+1<<" de la columna"<<i+1<<endl;
			cin>>arreglo2[j][i];
		}
	}
	cout<<"las matrices que se multiplicaran son:"<<endl;
	cout<<"matriz 1"<<endl;
	for(int i=0; i<3; i++){
		cout<<"[";
		for(int j=0; j<3; j++){
			cout<<arreglo1[j][i]<<", ";
		}
		cout<<"]"<<endl;
	}
	cout<<"matriz 2"<<endl;
	for(int i=0; i<3; i++){
		cout<<"[";
		for(int j=0; j<3; j++){
			cout<<arreglo2[j][i]<<", ";
		}
		cout<<"]"<<endl;
	}
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
	return 0;
}
void pedirTamanos(int *a, int *b){
	
	cout<<"dame el tamano de las filas"<<endl;
	cin>>*a;
	cout<<"dame el unmero de las columnas"<<endl;
	cin>>*b;
}

void  multiplicacion(float *a, float *b, float **c){
}
void validarOmatriz(int a, int b){
	if(a == b){
		cout<<"datos correctos se pueden realizar"<<endl;
	}
	else{
		cout<<"datos erroneos cerrando programa"<<endl;
		usleep(4000);
		exit(EXIT_FAILURE);
	}
}
void mostrarDatos(float **c, int *a, int *b){
	cout<<"el resultado es"<<endl;
	for(int i = 0 ; i < *b ; i++){
		cout<<"[";
		for(int j = 0 ; j < *a ; j++){
			cout<<*c[j][i]<<", ";
		}
		cout<<"]"<<endl;
	}
}
