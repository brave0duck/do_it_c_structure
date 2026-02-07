//함수 swap_ptr를 함수형식 매크로로 변환하시오
// #define swap(type,x,y) do{ type t=x; x=y; y=t;}while(0)

#include <stdio.h>
#define SWAP(type,x,y) do{ type *t = *x; *x = *y; *y = t;} while(0)

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

    //swap_ptr(&s1,&s2);
    SWAP(char,&s1, &s2);

    printf("포인터 s1은 \"%s\"를 가리킵니다.\n", s1);
    printf("포인터 s2은 \"%s\"를 가리킵니다.\n", s2);

    return 0;
}