// ex-q1.c를 수정해서 합계를 구하는 함수를 작성한다

#include <stdio.h>
#include <stdlib.h>

int sumof(const int a[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum += a[i];
    }
    return sum;
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
    printf("sum height is %d.\n", sumof(pHeight,number));
    free(pHeight);
    return 0;
}