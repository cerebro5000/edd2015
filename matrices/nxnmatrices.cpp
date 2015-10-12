#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;

void validarOperacion(int *x, int *y);
void ingresarTamano(int *x, int *y)
int main(){
	int tx1,ty1,tx2,ty2;
	float m1[3][3], m2[3][3], mres[3][3], acu=0;

	cout<<"programa que multiplica matrices de nxn"<<endl;
	//seingresan los tamanos de las matrices
	cout<<"para la matriz 1 dame los sig datos"<<endl;
	ingresarTamano(tx1,ty1);
	cout<<"para la matriz 2 dame el sig dato "<<endl;
	ingresarTamano(tx2,ty2);

	//validamos si la operacion se peude realizar
	validarOperacion(&tx1,&ty2);

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
