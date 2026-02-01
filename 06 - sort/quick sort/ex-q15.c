// 6-10.c 의 개선판
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "IntStack.h"

#define MAXIMUM 10
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

void quick(int a[], int left, int right){
    IntStack left_stack;
    IntStack right_stack;

    InitStack(&left_stack , right-left+1);
    InitStack(&right_stack , right-left+1);

    Push(&left_stack,left);
    Push(&right_stack,right);

    while(!IsEmpty(&left_stack)&& !IsEmpty(&right_stack)){
        int pl = (Pop(&left_stack,&left),left);
        int pr = (Pop(&right_stack,&right),right);
        int x = a[(left+right)/2];

        do{
            while(a[pl] < x)    pl++;
            while(a[pr] > x)    pr--;
            if(pl <= pr){
                swap(int, a[pl],a[pr]);
                pl++;
                pr--;
            }
        }while(pl <= pr);

        // 남은 요소가 많은 쪽을 먼저 푸쉬하는것이 스택총량을 조금이라도 줄일수있다
        if ((pr-left)< (right-pl)){
            if(pl < right){
                Push(&left_stack,pl);
                Push(&right_stack,right);
            }
            if(left<pr){
                Push(&left_stack,left);
                Push(&right_stack,pr);
            }
        }else{  
            if(left<pr){
                Push(&left_stack,left);
                Push(&right_stack,pr);
            }
            if(pl < right){
                Push(&left_stack,pl);
                Push(&right_stack,right);
            }
        }            
    }   
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