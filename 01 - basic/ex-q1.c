// 4개 중 최고값 찾기
#include <stdio.h>

int max4(int a, int b, int c, int d);
int main(void){
    int a,b,c,d;
    printf("input 4 digit : ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    
    printf("max find : %d\n", max4(a,b,c,d));
    return 0;
}
int max4(int a, int b, int c, int d){
    int max = a;
    if (b >= max){
        max = b;
    }
    if (c >= max){
        max = c;
    }
    if (d >= max){
        max = d;
    }
    return max;

}