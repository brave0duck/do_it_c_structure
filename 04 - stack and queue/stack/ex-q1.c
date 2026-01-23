// int stack example
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int InitStack(IntStack *s, int max){
    s->now =0;
    s->pStack = (int *)calloc(max,sizeof(int));
    if (s->pStack == NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}
int Push(IntStack *s, int x){
    if(IsFull(s)){
        return -1;
    }
    s->pStack[s->now++] = x;
    return 0;
}
int Pop(IntStack *s, int *x){
    if(IsEmpty(s)){
        return -1;
    }
    *x =s->pStack[--s->now];
    return 0;
}
int Peek(const IntStack *s, int *x){
    if( IsEmpty(s)){
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
    printf("=== %d in Stack ===\n", s->now);
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
        printf("\n현재 데이터 수 : %d/%d\n",s->now, s->max);
        printf("(1)Push (2)Pop (3)Peek (4)Print (5)Clear \n");
        printf("(6)Capacity (7)Size (8)Search (0)Exit : ");
        scanf("%d", &menu);

        switch(menu){
            case 1: //push
                printf("push 데이터 : ");
                scanf("%d", &x);
                if( Push(s,x) == -1){
                    printf("stack이 가득찼습니다. push가 안됩니다.\n\n");
                }else{
                    printf("--> %d 데이터가 push\n\n",x);
                }
                break;
            case 2: // pop
                if( Pop(s, &x) == -1){
                    printf("stack이 비었습니다. pop이 안됩니다.\n\n");
                }else{
                    printf("--> %d 데이터가 pop\n\n", x);
                }
                break;
            case 3: //peek
                if( Peek(s,&x) == -1){
                    printf("stack이 비었습니다. peek이 안됩니다.\n\n");
                }else{
                    printf("--> peek : %d \n\n",x);
                }
                break;
            case 4: //print
                Print(s);
                break;
            case 5:
                Clear(s);
                printf("stack clean\n");
                break;
            case 6:
                printf("stack capacity is %d\n", Capacity(s));
                break;
            case 7:
                printf("stack size is %d\n", Size(s));
                break;
            case 8:
                int search; int number;
                printf("what data searching for? : ");
                scanf("%d", &search);
                number = Search(s,search);
                if( number  == -1){
                    printf("data not found\n");
                }else{
                    printf("%d found in stack[%d]\n", search, number);
                }
                break;
            case 0:
                printf("Program Exit");
                goto EXIT;
        }
        
    }
EXIT:
    Terminate(s);
    return 0;
}