#include <stdio.h>
#include <stdlib.h>

void fibo(int num, int max, int res){
	res = res + num;
	printf("%d, ",res);
	if(res < max)
		fibo(res,max,num);
}
int main(){
	int numero=1, ulti, res = 0;
	printf("programa de fibonacci recursivo\n");
	printf("dime maximo hasta que numero quieres ver");
	scanf("%d",&ulti);
	printf("la sucecion es :%d, %d, ", res, numero);
	fibo(numero, ulti, res);
	printf("\n");
}/*created by: cerebro*/
