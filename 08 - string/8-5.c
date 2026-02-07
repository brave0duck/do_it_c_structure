//두 포인터 값을 서로 교환하는 함수가 있는 프로그램
#include <stdio.h>

void swap_ptr(char **x, char **y){
    char *temp = *x;
    *x = *y;
    *y = temp;
}
int main(void){
    char *s1 = "ABCD";
    char *s2 = "EFGH";

    printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
    printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);

    swap_ptr(&s1,&s2);

    printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
    printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);

    return 0;
}