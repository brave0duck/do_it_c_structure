//문자열 리터럴을 가리키는 포인터를 서로 스왑하는 함수
#include <stdio.h>


void swap_ptr(char ** x,char ** y){
    char* temp = *x;
    *x = *y;
    *y = temp;    
}
int main(void){
    char * s1 = "ABCD";
    char * s2 = "EFGH";

    printf("s1 is pointing %s\n",s1);
    printf("s2 is pointing %s\n",s2);

    swap_ptr(&s1,&s2);

    printf("s1 is pointing %s\n",s1);
    printf("s2 is pointing %s\n",s2);

    return 0;
}