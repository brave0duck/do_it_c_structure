// 곱셈표를 출력합니다
#include <stdio.h>

int main(void){
    
    
    for(int i=0; i<=9; i++){
        if (i==0){
            printf("   |");
        }else{
            printf("%3d", i);
        }
    }
    putchar('\n');
    for(int i=0; i<=9; i++){
        if (i==0){
            printf("---+");
        }else{
            printf("---");
        }
    }
    putchar('\n');
    for(int i=1; i<=9; i++){
        printf("%-3d|",i);
        for(int j=1; j<=9; j++){
            printf("%3d", i*j);
        }
        putchar('\n');
    }
   
    return 0;
}