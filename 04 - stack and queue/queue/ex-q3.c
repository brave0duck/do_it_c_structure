//
#include <stdio.h>
#include <stdlib.h>
#include "ex-q3.h"

int Initialize(ArrayIntQueue *q, int max){
    q->que = (int *)malloc(max*sizeof(int));
    if (q->que == NULL){
        return -1;
    }
    q->max = max;
    q->num=0;
    return 0;
}
int Enque(ArrayIntQueue *q, int x);
int Deque(ArrayIntQueue *q, int *x);
int Peek(const ArrayIntQueue *q, int *x);
void Clear(ArrayIntQueue *q);
int Capacity(cost ArrayIntQueue *q);
int Size(const ArrayIntQueue *q);
int IsEmpty(const ArrayIntQueue *q);
int IsFull(const ArrayIntQueue *q);
int Search(const ArrayIntQueue *q);
void Print(const ArrayIntQueue *q);
void Terminate(ArrayIntQueue *q);
int main(void){

    return 0;
}