// require : 직각이등변 삼각형을 출력하는 함수 (*로)
#include <stdio.h>
void triangleLB(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            printf("*");
        }
        putchar('\n');
    }
}
int main(void){
    
    return 0;
}