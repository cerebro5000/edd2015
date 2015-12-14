#include <stdio.h>
#include <stdlib.h>

void fibo(int num, int max, res){
	res = res + num;
	pritf("%d",res);
	if(res < max)
		fibo(res,max,res)
}
int main(){
	int numero=0, ulti, res=1;
	printf("programa de fibonacci recursivo\n");
	pritnf("dime maximo hasta que numero quieres ver");
	scanf("%d",&ulti);
	printf("la sucecion es :%d", numero);
	fibo(numero, ulti, res);
	printf("\n");
}/*created by: cerebro*/
