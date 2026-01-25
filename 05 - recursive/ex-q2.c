//gcd() 최대공약수 함수를 재귀함수없이 구현
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// a[n-2] a[n-1] a[2]
//  x       y       
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
//  10  20  30
//-----------------------여기까지
int gcd3(int a[], int n){
    if(a[n-1] <=0){
        return a[n-2];
    }
    return gcd3(a[n-1], a[n-2]%a[n-1]);
}
int main(void){
    int a[10];
    srand(time(NULL));

    printf("rand()함수로 만든 수 : ")
    for(int i=0; i<10; i++){
        a[i] = 1+ rand() % 1000;
        printf("%d ", a[i]);
    }
    
    printf("최대공약수는 %d 입니다.", gcd(a,b));
    
    return 0;
}