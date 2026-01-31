//단순삽입정렬 개인구현. 1부터 N-1까지 순환하면서 알맞은 위치에 삽입한다
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXIMUM 10
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

typedef int INT;
INT COMP_COUNTER;
INT SWAP_COUNTER;
//  3   5   2
void arr_shift(int a[],int from, int to){
    int tmp = a[to];
    for(int i=to+1; i<=from; i++){

    }
}
void insertion_sort(int a[],int n){
    for(int i=1; i<=n-1; i++){
        for(int j=0; j<i; j++){
            if (a[j] < a[i]){
                swap(int,a[i],a[j]);
            }
        }
    }
}
int main(void){
    srand(time(NULL));
    int *x;

    x =(int*)malloc(MAXIMUM*sizeof(int));

    printf("Original : \t");
    for(int i=0; i<MAXIMUM; i++){
        x[i] = 1+ rand()% 1999;
        printf("%d ",x[i]);
    }
    printf("\n");

    insertion_sort(x,MAXIMUM);

    printf("After : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    printf("\n%d번 비교했습니다. %d스왑했습니다",COMP_COUNTER,SWAP_COUNTER);
    free(x);
    return 0;
}