//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int int_comp(const void *x, const void *y){
    const int *a = (const int *)x;
    const int *b = (const int *)y;
    if(*a < *b){
        return -1;
    }else if(*a > *b){
        return 1;
    }else{
        return 0;
    }
}
int main(void){
    srand(time(NULL));
    int *x;

    x =(int*)malloc(MAX*sizeof(int));

    printf("Original : \t");
    for(int i=0; i<MAX; i++){
        x[i] = 1+ rand()% 1999;
        printf("%d ",x[i]);
    }
    printf("\n");

    qsort(x,MAX,sizeof(int), int_comp);

    printf("\n\nAfter : \t");
    for(int i=0; i<MAX ; i++){
        printf("%d ",x[i]);
    }
    
    free(x);
    return 0;
}