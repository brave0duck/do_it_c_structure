// shell sort ver2
// 간격값을 규칙적으로 하게되면 1그룹과 2그룹이 마지막까지 섞이지않아 비효율적일수 있다는점을 개선
// 간격 값 h를 비규칙적으로 바꾼다

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM 100
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

int SWAP;
int COMP;

void shellsort2(int a[], int n){
    int i,j,h;
    for(h=1; h<n/9 ; h = h*3+1)
    ;
    for(; h>0 ; h/=3){    //h=4
        for(i=h; i<n ; i++){    //i=4 5 6 7 8
            int tmp = a[i];     //tmp = 7
            for(j=i-h; j>=0 && a[j]>tmp ; j -= h){  //j=0   j= j-h
                a[j+h] = a[j];
                SWAP++;
                COMP++;
            }
            a[j+h] = tmp;
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

    shellsort2(x,MAXIMUM);

    printf("After : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    printf("\n%d번 비교. %d번 스왑", SWAP,COMP);
    free(x);
    return 0;
}