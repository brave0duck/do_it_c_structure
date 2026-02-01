// int stack example
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int InitStack(IntStack *s, int max){
    s->now =0;
    s->pStack = (int *)calloc(max,sizeof(int));
    if ( s->pStack == NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}
int Push(IntStack *s, int x){
    if(s->now >= s->max){
        return -1;
    }
    s->pStack[s->now++] = x;
    return 0;
}
int Pop(IntStack *s, int *x){
    if(s->now <= 0){
        return -1;
    }
    *x =s->pStack[--s->now];
    return 0;
}
int Peek(const IntStack *s, int *x){
    if( s->now <= 0){
        return -1;
    }
    *x = s->pStack[s->now -1];
    return 0;
}
void Clear(IntStack *s){ s->now = 0; }
inline int Capacity(const IntStack *s){ return s->max;  }
inline int Size(const IntStack *s){     return s->now;    }
inline int IsEmpty(const IntStack *s){  return s->now <= 0? 1:0; }
inline int IsFull(const IntStack *s){   return s->now >= s->max? 1: 0;  }
int Search(const IntStack *s, int x){
    for(int i=0; i < s->now; i++){
        if( s->pStack[i] == x){
            return i;
        }
    }
    return -1;
}
void Print(const IntStack *s){
    for(int i=0; i<s->now;i++){
        printf("%d --> [%d]\n",i, s->pStack[i]);
    }
}
void Terminate(IntStack *s){
    if( s->pStack != NULL){
        free(s->pStack);
    }
    s->max = s->now =0;
}