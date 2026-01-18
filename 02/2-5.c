// 배열에 데이터를 입력하고 최대값을 구하는 함수
#include <stdio.h>
#include <stdlib.h>

int maxof(const int *a, int n){
    int max = a[0];
    for(int i=1; i<n ; i++){
        if(a[i]>max) max = a[i];
    }
    return max;
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
    printf("Max height is %d.\n", maxof(pHeight,number));
    free(pHeight);
    return 0;
}