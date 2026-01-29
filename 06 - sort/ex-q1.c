// ex-q1.c
// bubble sort - 안쪽 반복문을 0부터 돌면서 큰수를 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define __MAX__ 33
#define swap(x,y) do{ int t; t=x; x=y; y=t;}while(0);

// 큰수를 뒤에다 배치하는 버블정렬
void bubble_sort2(int a[], int n){
    for(int i=0; i<n-1; i++){   //0 1 2
        for(int j=0; j<n-1-i; j++){    // 0 1
            if ( a[j] > a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main(void){
    int *a;
    a = (int*)malloc(__MAX__*sizeof(int));

    srand(time(NULL));
    printf("Before bubble sort : \t");
    for(int i=0; i<__MAX__; i++){
        a[i] = 1 + rand() % 200;
        printf("%d ", a[i]);
    }

    bubble_sort2(a,__MAX__);

    printf("\nAfter Bubble sort : \t");
    for(int i=0; i<__MAX__; i++){
        printf("%d ", a[i]);
    }
    putchar('\n');
    free(a);
    return 0;
}