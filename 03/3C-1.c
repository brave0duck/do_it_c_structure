// 덧셈,곱셈표
#include <stdio.h>

int sum(int a,int b){
    return a+b;
}
int mul(int a,int b){
    return a*b;
}
void kuku(int (*calc)(int,int)){
    int i,j;
    for(i=1; i<=9; i++){
        for(j=1; j<=9; j++){
            printf("%3d", (*calc)(i,j));
        }
        putchar('\n');
    }
}
int main(void){
    puts("덧셈표");
    kuku(sum);
    puts("곱셈표");
    kuku(mul);
    
    return 0;
}