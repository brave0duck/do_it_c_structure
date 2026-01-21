// 4개 중 최소값 찾기
#include <stdio.h>

int min4(int a, int b, int c, int d);
int main(void){
    int a,b,c,d;
    printf("input 4 digit : ");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    
    printf("min value is %d\n", min4(a,b,c,d));
    return 0;
}
int min4(int a, int b, int c, int d){
    int min = a;
    if (min >= b){
        min = b;
    }
    if (min >= c){
        min = c;
    }
    if (min >= d){
        min = d;
    }
    return min;

}