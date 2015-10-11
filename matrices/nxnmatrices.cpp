#include <iostream>
using namespace std;

int main(){
	float arreglo1[3][3], arreglo2[3][3], mres[3][3], acu=0;

	cout<<"programa que multiplica matrices de 3x3"<<endl;
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
