// 3개 중 최소값 구하기
#include <stdio.h>

int min3(int a, int b, int c);
int main(void){
    int one,two,three;
    printf("find min value. input 3 digit : ");
    scanf("%d", &one);
    scanf("%d", &two);
    scanf("%d", &three);

    printf("min value is %d\n\n", min3(one,two,three));

    return 0;
}
int min3(int a, int b, int c){
    int min = a;
    if (min >= b){
        min = b;
    }
    if (min >= c){
        min = c;
    }
    return min;
}