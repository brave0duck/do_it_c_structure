// ex-q2.c를 수정해서 평균값을 구하는 프로그램
#include <stdio.h>
#include <stdlib.h>

int sumof(const int a[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    return sum;
}
double aveof(const int a[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    return (double)sum/n;
}
int main(void){
    int *pHeight;
    int number;

    printf("How many people? : ");
    scanf("%d", &number);
    pHeight = (int *)calloc(number, sizeof(int));

    printf("Input height %d person.\n", number);
    for(int i=0; i<number; i++){
        printf("height[%d] : ", i);
        scanf("%d", &pHeight[i]);
    }
    printf("sum height is %d\n", sumof(pHeight,number));
    printf("average height is %.2f\n", aveof(pHeight, number));
    free(pHeight);
    return 0;
}