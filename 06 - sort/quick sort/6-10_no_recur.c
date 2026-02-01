// quick sort를 재귀없는 함수로 바꾼다
// stack을 이용해서 left,right 위치를 스택에 푸쉬,팝

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "IntStack.h"

#define MAXIMUM 10
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

void quick(int a[], int left, int right){
    IntStack left_stack;
    IntStack right_stack;
    // 스택 초기화
    InitStack(&left_stack , right-left+1);
    InitStack(&right_stack , right-left+1);
    // 첫 시작은 일단 푸쉬
    Push(&left_stack,left);
    Push(&right_stack,right);

    // 스택이 비어있을때까지 반복한다
    while(!IsEmpty(&left_stack)&& !IsEmpty(&right_stack)){
        // pl, pr, x를 지정
        int pl = (Pop(&left_stack,&left),left);
        int pr = (Pop(&right_stack,&right),right);
        int x = a[(left+right)/2];
        
        // 퀵소트 알고리즘은 똑같다
        do{
            while(a[pl] < x)    pl++;
            while(a[pr] > x)    pr--;
            if(pl <= pr){
                swap(int, a[pl],a[pr]);
                pl++;
                pr--;
            }
        }while(pl <= pr);

        // 재귀를 돌리는것이 아니라 푸쉬를 한다
        if(left<pr){
            Push(&left_stack,left);
            Push(&right_stack,pr);
        }
        if(pl < right){
            Push(&left_stack,pl);
            Push(&right_stack,right);
        }
    }
    // 스택을 해제
    Terminate(&left_stack);
    Terminate(&right_stack);

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

    quick(x,0,MAXIMUM-1);

    printf("\n\nAfter : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    
    free(x);
    return 0;
}