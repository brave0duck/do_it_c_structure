//단순삽입정렬 개인구현. 1부터 N-1까지 순환하면서 알맞은 위치에 삽입한다
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM 100
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

int SWAP;
int COMP;

void insertion(int a[], int n){
    int i,j;
    // i = unsorted index, j = sorted index
    for(i=1; i<n ; i++){
        int tmp = a[i];
        for(j=i; j>0 && a[j-1]>tmp ; j--){
            a[j] = a[j-1];
            SWAP++;
            COMP++;
        }
        a[j] = tmp;
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

    insertion(x,MAXIMUM);

    printf("After : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    printf("\n%d번 비교. %d번 스왑", SWAP,COMP);
    free(x);
    return 0;
}