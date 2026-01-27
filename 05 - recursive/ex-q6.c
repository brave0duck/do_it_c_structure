// 재귀함수를 비재귀함수로 변환
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int ptr;
    int * pStack;
}IntStack;

void Init(IntStack *s, int n){
    s->pStack = (int*)calloc(n,sizeof(int));
    if( s != NULL){
        s->ptr = 0;
    }
}
void Terminate(IntStack *s){
    if(s->pStack != NULL){
        s->ptr = 0;
        free(s->pStack);
    }
}
int IsEmpty(IntStack *s){
    if (s->ptr <= 0){
        return 1;
    }else{
        return 0;
    }
}
int IsFull(IntStack *s){
    if(s->ptr >= 100){
        return 1;
    }else{
        return 0;
    }
}
void Push(IntStack *s, int n){
    if(!IsFull(s)){
        s->pStack[s->ptr++] = n;
    }
}
int Pop(IntStack *s){
    if(!IsEmpty(s)){
        return s->pStack[--s->ptr];
    }
}
void recur3(int n){
    if(n>0){
        recur3(n-1);
        recur3(n-2);
        printf("%d\n",n);
    }
}
void recur4(int n){
    IntStack stk;
    Init(&stk,100);
    
    TOP:
    if(n>0){
        Push(&stk,n);
        n = n - 1;
        goto TOP;
        n = n - 2;
        goto TOP;
        
    }
    printf("%d\n", Pop(&stk));
    
    // while(!IsEmpty(&stk)){
    //     printf("%d\n", Pop(&stk));
    // }
    Terminate(&stk);
}
int main(void){
    /*
    int n;
    printf("재귀함수 n(0-100) : ");
    scanf("%d",&n);
*/
    printf("\n=== recur3 ===\n");
    recur3(3);
    printf("\n=== recur4 ===\n");
    recur4(3);
    
    return 0;
}