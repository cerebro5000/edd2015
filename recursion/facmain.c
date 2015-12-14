#include <stdio.h>
#include <stdlib.h>

int factorial(int numero){
        if(numero == 0)
                return 1;
        return numero * factorial(numero-1);
}
int main(){
        int numero,res;
        printf("programa factorial \n");
        printf("dame un numero \n");
        scanf("%d",&numero);
        res = factorial(numero);
}
