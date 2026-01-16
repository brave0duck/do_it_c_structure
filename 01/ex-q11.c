// 조건 : 양의 정수를 입력하고, 자릿수를 출력하는 프로그램을 작성하시오. 
// ex) 135 = '그 수는 3자리 입니다'출력. 1314 = '그 수는 4자리입니다'출력
#include <stdio.h>

int main(void){
    int n=1;
    int ncount=0;
    long input;
    do{
        printf("양의 정수를 입력하세요 : ");
        scanf("%ld", &input);
    }while( input <= 0);

    while( 1 <= input/n){
        n *= 10;
        ncount++;
    }
    printf("그 수는 %d자리입니다\n", ncount);
    return 0;
}