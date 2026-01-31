//단순삽입정렬 개인구현. 1부터 N-1까지 순환하면서 알맞은 위치에 삽입한다
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXIMUM 100
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

typedef int INT;
INT COMP_COUNTER;
INT SFT_COUNTER;

// 배열 쉬프트함수(배열, 삽입해야할 요소의 인덱스, 삽입될 자리의 인덱스)
void arr_shift(int a[],int from, int to){
    int tmp = a[from];
    for(int i=from; i>to; i--){
        a[i] = a[i-1];
        SFT_COUNTER++;
    }
    a[to] = tmp;
}
// 단순삽입정렬 함수
void insertion_sort(int a[],int n){
    for(int i=1; i<n ; i++){    // 정렬되지않은 배열 unsorted array
        for(int j=0; j<i; j++){ // 정렬된 배열  sorted array
            if (a[j] > a[i]){   // 정렬안된 배열중 더 작은수가 등장하면
                arr_shift(a,i,j);   // 바꾸고 쉬프트한다
            }
            COMP_COUNTER++;
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
    printf("\n%d번 비교했습니다. %d번 쉬프트했습니다",COMP_COUNTER,SFT_COUNTER);
    free(x);
    return 0;
}