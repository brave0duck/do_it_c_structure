// 배열에 데이터를 입력하고 최대값을 구하는 함수. 랜덤함수 활용
#include <time.h>
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

    srand(time(NULL));
    number = 5 + rand() % 16 ;
    printf("Random people select : %d\n", number);
    
    pHeight = (int *)calloc(number, sizeof(int));

    printf("Input height %d person.\n", number);
    for(int i=0; i<number; i++){
        pHeight[i] = 150 + rand() % 60;
        printf("pHeight[%d] : %d\n", i, pHeight[i]);
    }
    printf("\nMax height is %d\n", maxof(pHeight,number));
    free(pHeight);
    return 0;
}