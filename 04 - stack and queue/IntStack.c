// int stack example
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int InitStack(IntStack *s, int max){
    s->now =0;
    if ( s->pStack = (IntStack*)calloc(max,sizeof(IntStack)) == NULL){
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
    *x =s->pStack[--p->now];
    return 0;
}
int Peek(const IntStack *s, int *x){
    if( s->now <= 0){
        return -1;
    }
    *x = s->pStack[s->now -1];
    return 0;
}
int Clear(IntStack *s){ s->now = 0; }
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
int Print(const IntStack *s){
    for(int i=0; i<s->now;i++){
        printf("%d --> |\t[%d]\t|\n",i, s->pStack[i]);
    }
}
void Terminate(IntStack *s){
    if( s->pStack != NULL){
        free(s->pStack);
    }
    s->max = s->now =0;
}
int main(void){
    IntStack * s;
    int max;    int input;

    printf("==== Stack ====\n");
    printf("스택 총량은? (0~) : ");
    scanf("%d", &max);
    if( InitStack(s,max) == -1){
        puts("스택 생성에 실패했습니다.");
        puts("Program Exit...");
        return -1;
    }

    while(1){
        int menu, x;
        printf("현재 데이터 수 : %d/%d",s->now, s->max);
        printf("(1)Push (2)Pop (3)Peek (4)Print (0)Exit : ");
        scanf("%d", &menu);

        switch( input){
            case 1:
                printf("데이터 : ");
                scanf("%d", &x);
                if( Push(s,x) == -1){
                    printf("stack is full...\n");
                }
                break;
            case 2:
                if( Pop(s, &x) == -1){
                    printf("stack is empty");
                }else{
                    printf("Pop 데이터는 %d입니다.", x);
                }
                break;
        }
        
    }
    return 0;
}