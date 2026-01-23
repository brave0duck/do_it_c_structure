/************************************************************************************
*  양방향 스택구현
*
*  a스택--> * (type1)
*  [0]     [1]     [2]     [3]     [4]     [5]     [6]     [7]     [8]     [9]
*                                                                   *  <-- b스택 (type2)
*
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "ex-q2.h"

int Init(DStack *s, int max){
    s->pStack = (int *)calloc(max,sizeof(max));
    if(s->pStack == NULL){
        s->max=0;
        return -1;
    }
    s->max = max;
    s->a.ptr=0; s->a.storage=0;
    s->b.ptr = s->max-1; s->b.storage =0;
    
    return 0;
}
int IsEmpty(const DStack *s, int type){
    // type1 = a, type2 = b
    if (type == 1){
        return s->a.ptr <= 0;
    }else{
        return s->b.ptr >= s->max;
    }
}
int IsFull(const DStack *s, int type){
    if( type ==1 ){
        return s->a.ptr > s->b.ptr;
    }else{
        return s->b.ptr < s->a.ptr;
    }
}
int Push(DStack *s, int type, int x){
    switch(type){
        case 1:
            if(IsFull(s,1)) 
                return -1;
            s->pStack[s->a.ptr++] = x;
            s->a.storage++;
            break;
        case 2:
            if(IsFull(s,2))
                return -1;
            s->pStack[s->b.ptr--] = x;
            s->b.storage++;
            break;
        default:
            return -1;
    }
    return 0;
}
int Pop(DStack *s, int type, int *x){
    switch(type){
        case 1:
            if(IsEmpty(s,1))    return -1;
            *x = s->pStack[--s->a.ptr];
            s->a.storage--;
            break;
        case 2:
            if(IsEmpty(s,2))    return -1;
            *x = s->pStack[s->b.ptr++];
            s->b.storage--;
            break;
        default:
            return -1;
    }
    return 0;
}
int Peek(const DStack *s, int type, int *x){
    switch(type){
        case 1:
            if(IsEmpty(s,1))    return -1;
            *x = s->pStack[s->a.ptr -1];
            break;
        case 2:
            if(IsEmpty(s,2))    return -1;
            *x = s->pStack[s->b.ptr];
            break;
        default:
            return -1;
    }
    return 0;
}
void Clear(DStack *s,int type){
    if( type == 1){
        s->a.ptr = 0;
        s->a.storage=0;
    }else if(type ==2){
        s->b.ptr = s->max -1;
        s->b.storage =0;
    }
}
int Capacity(const DStack *s){
    return s->max - (s->a.storage + s->b.storage);
}
int Size(const DStack *s, int type){
    if(type ==1){
        return s->a.storage;
    }else if(type ==2) {
        return s->b.storage;
    }
}
int Search(const DStack *s, int type, int x){
    switch(type){
        case 1:
            for(int i=0; i<s->a.storage; i++){
                if(s->pStack[i] == x){
                    return i;
                }
            }
            break;
        case 2:
            for(int i=(s->max-1); i >=0 ; i--){
                if(s->pStack[i] == x){
                    return i;
                }
            }
            break;
    }
    return -1;
}
void Print(const DStack *s, int type){
    if(type ==1){
        printf("=== %d in Stack A\n", s->a.storage);
        for(int i=0; i < s->a.storage; i++){
            printf("%d --> [%d]\n", i, s->pStack[i]);
        }
    }else if(type == 2){
        printf("=== %d in Stack B ===\n",s->b.storage);
        for(int i= s->max -1 ; i>= (s->max - s->b.storage); i--){
            printf("%d --> [%d]\n", i, s->pStack[i]);
        }
    }
}
void Terminate(DStack *s){
    if( s->pStack != NULL){
        free(s->pStack);
    }
    s->max = s->a.ptr = s->a.storage = s->b.ptr = s->b.storage = 0;
}
int main(void){
    DStack *s;
    int max;    int input;

    printf("==== Double Stack ====\n");
    printf("What stack size ? (0-) : ");
    scanf("%d", &max);
    if( Init(s, max) == -1){
        puts("Failed to create stack. can't allocation ");
        puts("Program Exit...");
        return -1;
    }

    while(1){
        int menu, x, st;
        printf("\nStack : 1-%d, 2-%d  (%d/%d)\n",s->a.storage, s->b.storage, (s->a.storage+s->b.storage), s->max);
        printf("(1)Push (2)Pop (3)Peek (4)Print (5)Clear \n");
        printf("(6)Capacity (7)Size (8)Search (0)Exit : ");
        scanf("%d", &menu);

        switch(menu){
            case 1: //push
                printf("Stack (1 or 2) , DATA Input : ");
                scanf("%d %d", &st,&x);
                if(Push(s,st,x) == -1){
                    printf("%d stack is Full. Can't push.\n", st);
                }else{
                    printf("--> %d data in %dstack. PUSH\n", x, st);
                }
                break;
            case 2: // pop
                printf("Stack (1 or 2) : ");
                scanf("%d", &st);
                if( Pop(s,st,&x) == -1){
                    printf("stack is Empty. Can't Pop\n");
                }else{
                    printf("--> %d data in %dstack. POP\n", x,st);
                }
                break;
            case 3: //peek
                printf("Stack (1 or 2) : ");
                scanf("%d", &st);
                if( Peek(s,st,&x) == -1){
                    printf("stack is Empty. Can't Peek\n");
                }else{
                    printf("--> %d data in %dstack. PEEK\n",x,st);
                }
                break;
            case 4: //print
                Print(s, 1);
                putchar('\n');
                Print(s,2);
                break;
            case 5: // clear
                printf("Stack Clear ... 1 or 2 or 3(all)) : ");
                scanf("%d", &st);
                if( st == 1){
                    Clear(s,1);
                }else if(st == 2){
                    Clear(s,2);
                }else if(st == 3){
                    Clear(s,1);
                    Clear(s,2);
                }else{
                    printf("\nWrong input\n");
                }
                break;
            case 6: // capacity
                printf("Stack capacity is %d\n", Capacity(s));
                break;
            case 7: // size
                printf("Stack Size ... 1 or 2 or 3(all) : ");
                scanf("%d", &st);
                if( st == 1){
                    printf("Stack 1 size is %d\n", Size(s,1));
                }else if(st == 2){
                    printf("Stack 2 size is %d\n", Size(s,2));
                }else if(st == 3){
                    printf("Stack 1 size is %d\n", Size(s,1));
                    printf("Stack 2 size is %d\n", Size(s,2));
                }else{
                    printf("\nWrong input\n");
                }
                break;
            case 8: //search
                int search; int number;
                printf("Stack (1 or 2 ) , Searching Data : ");
                scanf("%d %d", &st, &search);
                number = Search(s,st,search);
                if( number == -1){
                    printf("Data not found\n");
                }else{
                    printf("%d found in %d stack[%d]\n", search, st, number);
                }
                break;
            case 0: // eixt
                printf("Program Exit\n");
                goto EXIT;
        }
        
    }
EXIT:
    Terminate(s);
    return 0;
}