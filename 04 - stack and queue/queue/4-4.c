// Ring Queue구현(원형큐). front rear로 앞뒤를 조절

#include <stdio.h>
#include <stdlib.h>
#include "4-4.h"

int Initialize(RingQueue *q, int max){
    q->que = (int *)malloc(max*sizeof(int));
    if (q->que == NULL){
        return -1;
    }
    q->max = max;
    q->num= q->front = q->rear = 0;
    return 0;
}
int IsEmpty(const RingQueue *q){
    return q->num <= 0;
}
int IsFull(const RingQueue *q){
    return q->num >= q->max;
}
int Enque(RingQueue *q, int x){
    if(IsFull(q)){
        return -1;
    }else{
        q->que[q->rear % q->max] = x;   // 원형이므로 %로 순환해준다
        q->rear = (q->rear+1) % q->max;                      // rear 1+ 증가
        q->num++;                       // 총량 1+ 증가
        return 0;
    }
}
int Deque(RingQueue *q, int *x){
    if(IsEmpty(q)){
        return -1;
    }else{
        *x = q->que[q->front];          // 뽑아서 반환하고
        q->front = (q->front+1) % q->max; // front +1. %로 순환
        q->num--;                       // 총량 -1
        return 0;
    }
}
int Peek(const RingQueue *q,int *x){
    if(IsEmpty(q)){
        return -1;
    }else{
        *x = q->que[q->front];
        return *x;
    }
}
void Clear(RingQueue *q){
    q->num = q->front = q->rear = 0;
}
int Capacity(const RingQueue *q){
    return q->max;
}
int Size(const RingQueue *q){
    return q->num;
}
int Search(const RingQueue *q,int x){
    int pos = q->front;
    for(int i=0; i< q->num; i++){
        pos %= q->max;
        if(q->que[pos] == x){
            return pos;
        }
        pos++;
    }
    return -1;
}
void Print(const RingQueue *q){
    int pos = q->front;
    printf("\n=== %d/%d in Queue ===\n",q->num,q->max);
    for(int i=0; i< q->num; i++){
        pos %= q->max;
        if(pos == q->front){
            printf("--> %d\n", q->que[pos]);
        }else{
            printf("    %d\n",q->que[pos]);
        }
        pos++;
    }
}
void Terminate(RingQueue *q){
    if(q->que != NULL){
        free(q->que);
    }
    q->front = q->rear = q->num = q->max = 0;
}
int main(void){
    RingQueue * q;
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