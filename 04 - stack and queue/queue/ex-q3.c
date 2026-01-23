// 배열큐 구현. 0부터 ---->n까지 디큐는 0 인큐는 n
// 큰 단점. 디큐되면 배열의 나머지를 쉬프트한다.
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
int IsEmpty(const ArrayIntQueue *q){
    return q->num <= 0;
}
int IsFull(const ArrayIntQueue *q){
    return q->num >= q->max;
}
int Enque(ArrayIntQueue *q, int x){
    if(IsFull(q)){
        return -1;
    }else{
        q->que[q->num++] = x;
        return 0;
    }
}
int Deque(ArrayIntQueue *q, int *x){
    if(IsEmpty(q)){
        return -1;
    }else{
        *x = q->que[0];
        for(int i=1; i<q->num; i++){
            q->que[i-1] = q->que[i];    // array shift
        }
        q->num--;
        return 0;
    }
}
int Peek(const ArrayIntQueue *q,int *x){
    if(IsEmpty(q)){
        return -1;
    }else{
        *x = q->que[0];
        return *x;
    }
}
void Clear(ArrayIntQueue *q){
    q->num =0;
}
int Capacity(const ArrayIntQueue *q){
    return q->max;
}
int Size(const ArrayIntQueue *q){
    return q->num;
}
int Search(const ArrayIntQueue *q,int x){
    for(int i=0; i< q->num; i++){
        if(q->que[i] == x){
            return i;
        }
    }
    return -1;
}
void Print(const ArrayIntQueue *q){
    printf("\n=== %d/%d in Queue ===\n",q->num,q->max);
    for(int i=0; i<q->num; i++){
        if(i==0){
            printf("--> %d\n", q->que[i]);
        }else{
            printf("    %d\n",q->que[i]);
        }
    }
}
void Terminate(ArrayIntQueue *q){
    if(q->que != NULL){
        free(q->que);
    }
    q->num = q->max = 0;
}
int main(void){
    ArrayIntQueue * q;
    int max;

    printf("==== Queue v0.01 ====\n");
    printf("Queue Size? : ");
    scanf("%d", &max);
    if( Initialize(q,max) == -1){
        puts("Failed to create queue");
        puts("Program Exit...");
        return -1;
    }

    while(1){
        int menu, x;
        printf("Queue : %d/%d\n",q->num, q->max);
        printf("(1)Enqueue (2)Dequeue (3)Peek (4)Print (5)Clear ");
        printf("(6)Capacity (7)Size (8)Search (0)Exit : ");
        scanf("%d", &menu);

        switch(menu){
            case 1: //Enqueue
                printf("data : ");
                scanf("%d", &x);
                if( Enque(q,x) == -1){
                    printf("Queue is full. can't enqueue\n");
                }else{
                    printf("--> %d Enqueue\n\n",x);
                }
                break;
            case 2: // Dequeue
                if( Deque(q, &x) == -1){
                    printf("Queue is empty. can't Dequeue\n");
                }else{
                    printf("--> %d Dequeue\n\n", x);
                }
                break;
            case 3: //peek
                if( Peek(q,&x) == -1){
                    printf("Queue is empty. can't peek\n");
                }else{
                    printf("--> peek : %d\n\n",x);
                }
                break;
            case 4: //print
                Print(q);
                break;
            case 5: // clear
                Clear(q);
                printf("Queue is clean\n");
                break;
            case 6: // capacity
                printf("Queue capacity is %d\n\n", Capacity(q));
                break;
            case 7: // size
                printf("Queue size is %d\n\n", Size(q));
                break;
            case 8: // search
                int search; int number;
                printf("What data searching ? : ");
                scanf("%d", &search);
                number = Search(q,search);
                if( number  == -1){
                    printf("data not found\n");
                }else{
                    printf("--> %d data in Queue[%d]\n", search, number);
                }
                break;
            case 0:// exit
                printf("Program Exit");
                goto EXIT;
        }
        
    }
EXIT:
    Terminate(q);
    return 0;
}