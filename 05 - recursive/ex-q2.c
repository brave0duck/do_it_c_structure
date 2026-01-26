//gcd() 최대공약수 함수를 재귀함수없이 구현
#include <stdio.h>
#include <stdlib.h>


int gcd(int x, int y){
    if(y<=0){
        return x;
    }
    return gcd(y, x%y);
}
int gcd2(int x, int y){
    int tmp;
    int a = x;  int b = y;
    if(x < y){
        a = y;  b = x;
    }
    while(b>0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
int main(void){
    int a,b;
    printf("최대공약수를 구합니다.\n");
    scanf("%d %d", &a,&b);

    printf("최대공약수는 %d 입니다.", gcd(a,b));
    
    return 0;
}