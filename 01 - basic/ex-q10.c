// 두 변수 a,b에 정수를 입력하고 b-a를 출력하는 프로그램 작성. 단 b가 a보다 작을경우 b의 값을 다시 입력하시오
#include <stdio.h>

int main(void){
    int a,b;
    
    printf("a value = ");
    scanf("%d", &a);
    printf("b value = ");
    scanf("%d", &b);
    while ( b <= a){
        printf("b must be bigger than a\n");
        printf("b value = ");
        scanf("%d", &b);
    }
    printf("b - a is %d", b-a);

    return 0;
}