// 유클리드 호제법으로 최대공약수 구하기
// 22 8 / 8 6 / 6 
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y){
    if (y==0){
        return x;
    }else{
        return gcd(y ,x%y);
    }
}
int main(void){
    int x,y;
    puts("두 정수의 최대공약수를 구합니다\n");
    printf("두 정수를 입력하세요 : ");
    scanf("%d %d", &x, &y);
    
    printf("%d 와 %d 의 최대공약수는 %d 입니다.", x,y,gcd(x,y));

    return 0;
}