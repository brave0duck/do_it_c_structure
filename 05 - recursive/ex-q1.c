// factorial 재귀함수를 재귀없이 구현
#include <stdio.h>
#include <stdlib.h>

int factorial(int x){
    if(x<=0){
        return 1;
    }
    return x*factorial(x-1);
}
unsigned long long factorial2(int x){
    unsigned long long result=1;
    for(int i=x; i > 0; i--){
        result *= i;
    }
    return result;
}
int main(void){
    int input;
    printf("factorial : ");
    scanf("%d", &input);

    printf("factorial result = %llu", factorial2(input));
    return 0;
}