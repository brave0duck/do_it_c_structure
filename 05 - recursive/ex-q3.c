//배열a의 모든 요소의 최대공약수를 구하는 함수 gcd_array[]를 작성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int gcd(int x, int y){
    if(y<=0){
        return x;
    }
    return gcd(y, x%y);
}
int gcd_array(const int a[], int n){
    int x;
    x = a[0];
    for(int i=1; i<n; i++){
        x = gcd(x,a[i]);
    }
    return x;
}
int main(void){
    int a[10] = {100,120,140,160,180,200,240,400,480,600};
    // srand(time(NULL));

    // printf("rand()함수로 만든 수 : ");
    // for(int i=0; i<10; i++){
    //     a[i] = 10*i + rand() % 101;
    //     printf("%d ", a[i]);
    // }
    
    printf("최대공약수는 %d 입니다.", gcd_array(a,10));    // 20   
    return 0;
}