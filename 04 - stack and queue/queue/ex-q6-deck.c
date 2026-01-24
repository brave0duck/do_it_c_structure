// 양방향 큐(deck que) 구현
//  인큐                                   인큐
//   0  1   2   3   4   5   6   7   8   9   10
//  디큐                                    디큐

#include <stdio.h>
#include <stdlib.h>
#include "ex-q6-deck.h"

int InitQue(DeckQue *q, int max){
    q->que = (int*)malloc(max*sizeof(int));
    if(q->que == NULL){
        q->max=0;
        return -1;
    }
    q->max = max;
    q->a.ptr = q->a.num =0;
    q->b.ptr = q->max-1;    q->b.num =0;
    return 0;
}
int IsFull(const DeckQue *q){
    return q->a.num + q->b.num >= q->max;
}
int Enque(DeckQue *q, int type, int x){
    if(IsFull(q)){
        return -1;
    }else{
        if(type == FORWARD){    // ptr, num 전부 조정
            q->que[q->a.ptr++] = x;
            q->a.num++;
        }else if(type == REVERSE){
            q->que[q->b.ptr--] = x;
            q->b.num++;
        }
        return 0;
    }
}
int Deque(DeckQue *q,int type, int *x){
    if(type == FORWARD){
        if( q->a.num <= 0){
            return -1;
        }else{
            *x = q->que[0];
            
            for(int i=1; i<q->a.ptr; i++){
                q->que[i-1] = q->que[i];
            }
            q->a.num--;
            q->a.ptr--;
        }
    }else if(type == REVERSE){
        if( q->b.num <= 0){
            return -1;
        }else{
            *x = q->que[q->max - 1];
            for(int i= q->max-1; i >(q->max - q->b.num); i--){
                q->que[i] = q->que[i-1];
            }
            q->b.num--;
            q->b.ptr++;
        }
    }
    return 0;
}
int Peek(const DeckQue *q, int type, int *x){
    if(type == FORWARD){
        if(q->a.num <=0){
            return -1;
        }else{
            *x = q->que[0];
            return 0;
        }
    }else if(type == REVERSE){
        if(q->b.num <= 0){
            return -1;
        }else{
            *x = q->que[q->max-1];
            return 0;
        }
    }
}
void Clear(DeckQue *q){
    q->a.num = q->a.ptr = 0;
    q->b.num =0;
    q->b.ptr = q->max -1;
}
int Capacity(const DeckQue *q){
    return q->max;
}
int Size(const DeckQue *q, int type){
    if(type == FORWARD){
        return q->a.num;
    }else if(type == REVERSE){
        return q->b.num;
    }
}
int Search(const DeckQue *q, int x){
    for(int i=0; i<q->max; i++){
        if(q->que[i] == x){
            return i;
        }
    }
    return -1;
}
void Print(const DeckQue *q){
    int i;
    for(i=0; i< q->a.num; i++){
        if(i==0){
            printf("*%d ", q->que[i]);
        }else{
            printf("%d ", q->que[i]);
        }
        
    }
    for(i=q->a.num+1; i<= (q->max - q->b.num); i++){
        printf(" [ ] ");
    }
    for(i=(q->max - q->b.num); i<q->max; i++){
        if(i == q->max-1){
            printf("*%d",q->que[i]);
        }else{
            printf("%d ", q->que[i]);
        }
        
    }
    puts("\n\n");
}
void Terminate(DeckQue *q){
    if(q->que != NULL){
        free(q->que);
    }
}
int main(void){

    DeckQue * q;
    int max;

    printf("==== Double ended queue (Deck Queue) ====\n");
    printf("Queue Size? : ");
    scanf("%d", &max);
    if( InitQue(q,max) == -1){
        puts("Failed to create queue");
        puts("Program Exit...");
        return -1;
    }

    while(1){
        int menu, x, type;
        printf("Queue : F - %d, R - %d / %d\n",q->a.num,q->b.num, q->max);
        printf("(1)Enqueue (2)Dequeue (3)Peek (4)Print (5)Clear ");
        printf("(6)Capacity (7)Size (8)Search (0)Exit : ");
        scanf("%d", &menu);

        switch(menu){
            case 1: //Enqueue
                printf("Type (1:FORWARD or 2:REVERSE) , DATA : ");
                scanf("%d %d", &type, &x);

                if( Enque(q,type,x) == -1){
                    printf("Queue is full. can't enqueue\n");
                }else{
                    printf("--> %d Enqueue\n\n",x);
                }
                break;
            case 2: // Dequeue
                printf("Type (1:FORWARD or 2:REVERSE) : ");
                scanf("%d", &type);
                if( Deque(q, type, &x) == -1){
                    printf("Queue is empty. can't Dequeue\n");
                }else{
                    printf("--> %d Dequeue\n\n", x);
                }
                break;
            case 3: //peek
                printf("Type (1:FORWARD or 2:REVERSE) : ");
                scanf("%d", &type);
                if( Peek(q,type,&x) == -1){
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
                printf("Type (1:FORWARD or 2:REVERSE) : ");
                scanf("%d", &type);
                printf("Queue size is %d\n\n", Size(q,type));
                break;
            case 8: // search
                int search; int number;
                printf("What data searching ? : ");
                scanf("%d", &search);
                number = Search(q,search);
                if( number  == -1){
                    printf("data not found\n");
                }else{
                    if(number < q->a.num){
                        printf("--> %d data in FORWARD Queue[%d]\n", search, number);
                    }else{
                        printf("--> %d data in REVERSE Queue[%d]\n", search, number);
                    }
                    
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