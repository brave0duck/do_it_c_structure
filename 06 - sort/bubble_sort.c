// bubble sort구현
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define __MAX__ 10

void bubble_sort(const int a[], int size){
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if (a[i] > a[j]){
                int tmp;
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
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
        a[i] = 1 + rand() % 100;
        printf("%d ", a[i]);
    }

    bubble_sort(a,__MAX__);

    printf("After Bubble sort : \t");
    for(int i=0; i<__MAX__; i++){
        a[i] = 1 + rand() % 100;
        printf("%d ", a[i]);
    }
    return 0;
}