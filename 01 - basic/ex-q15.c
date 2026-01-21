//요구사항 : 입력한 2 수를 변으로한 정사각형*을 만드시오
#include <stdio.h>

void makeSqure2(int a,int b){
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            printf("*");
        }
        putchar('\n');
    }
}
int main(void){
    int height,width;
    
    printf("print squre.\n");
    printf("input height : ");
    scanf("%d", &height);
    printf("input width : ");
    scanf("%d",&width);

    makeSqure2(height, width);
    
    return 0;
}