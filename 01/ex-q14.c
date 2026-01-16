//요구사항 : 입력한 수를 한변으로 정사각형*을 만드시오
#include <stdio.h>

void makeSqure(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("*");
        }
        putchar('\n');
    }
}
int main(void){
    int input=0;
    do{
        printf("print squre.\n");
        printf("input number : ");
        scanf("%d", &input);
        if (input >= 0){
            makeSqure(input);
        }
    }while(input != 0);
    
    return 0;
}