//1,000이하의 소수를 나열합니다 ver.1
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i,n;
    unsigned long counter=0;

    for(n=13; n <= 13; n++){
        for(i=2; i<n ; i++ ){
            counter++;
            if(n%i == 0){
                break;
            }
        }
        if(n==i){
            printf("%d\n", n);
        }
        printf("나눗셈을 실행한 횟수 : %lu\n", counter);
    }
    return 0;
}