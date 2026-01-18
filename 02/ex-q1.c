// 2-5.c 를 수정하여 최대값이 아닌 최소값을 구하는 함수로 바꾼다
#include <stdio.h>
#include <stdlib.h>

int minof(const int a[], int n){
    int min = a[0];
    for(int i=1; i<n ; i++){
        if( min > a[i]) min = a[i];
    }
    return min;
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
    printf("Minimum height is %d.\n", minof(pHeight,number));
    free(pHeight);
    return 0;
}