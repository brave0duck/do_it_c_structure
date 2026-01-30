// bubble sort구현
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define __MAX__ 10
#define swap(x,y) do{ int t; t=x; x=y; y=t;}while(0)

// 작은수를 앞에다 배열하는 버블정렬
void bubble_sort(int a[], int size){
    for(int i=0; i<size; i++){
        for(int j=size-1; j>i; j--){
            if (a[j-1] > a[j]){
                swap(a[j-1],a[j]);
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

    bubble_sort(a,__MAX__);
    
    printf("\nAfter Bubble sort : \t");
    for(int i=0; i<__MAX__; i++){
        printf("%d ", a[i]);
    }
    putchar('\n');
    free(a);
    return 0;
}