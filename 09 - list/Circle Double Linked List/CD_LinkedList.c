// 원형 이중연결 리스트 구현
#include <stdio.h>
#include <stdlib.h>
#include "CD_LinkedList.h"

Dnode* CreateNode(void){
    return calloc(Dnode,sizeof(Dnode));
}
void SetNode(Dnode *node,const DATA *x,const Dnode* prev, const Dnode* next){
    node->x = *x;
    node->prev = prev;
    node->next = next;
}
// 초기화
void Initialize(Dlist * list){
    list->head = NULL;
    list->crnt = NULL;
    list->tail = NULL;
}
int IsEmpty(Dlist *list){
    return list->head == NULL;
}
int IsLast(Dlist * list){
    return list->head == list->head->next;
}
int IsOnlyOne(Dlist * list){
    return list->head == list->head->next;
}
//리스트에서 특정 원소를 가진 요소 찾기
Dnode* Search(Dlist *list,const DATA *x){
    Dnode *p = list->head;
    if(p != NULL){
        do{
            if(p->x == *x){
                list->crnt = p;
                return p;
            }
            p = p->next;
        }while(p != list->head);
    }
    return NULL;
}
// 모든 리스트 출력
void Print(const Dlist* list){
    Dnode * pNode = list->head;
    if(pNode != NULL){
        do{
            printf("%d ",pNode->x);
            pNode = pNode->next;
        }while(pNode != list->head);
    }
}
// 현재 가리키는 요소 출력
void PrintCurrent(const Dlist *list){
    if(list->crnt != NULL){
        printf("%d\n",list->crnt->x);
    }
}
// 모든 리스트 출력 (반대로)
void PrintReverse(const Dlist* list){
    Dnode * pNode = list->tail;
    if(pNode != NULL){
        do{
            printf("%d ",pNode->x);
            pNode = pNode->prev;
        }while(pNode != list->tail);
    }
}
//선택한 노드의 다음으로 
int CurrentNext(Dlist *list){
    if(IsEmpty(list) || list->crnt->next == list->head){
        return 0;
    }
    list->crnt = list->crnt->next;
    return 1;
}
// 선택한 노드의 이전으로 
int CurrentPrev(Dlist *list){
    if(IsEmpty(list) || list->crnt->prev == list->tail){
        return 0;
    }
    list->crnt = list->crnt->prev;
    return 1;
}
//**************** insert *******************//
//머리에 노드를 삽입
void InsertFront(Dlist * list,const DATA *x){
    if(IsEmpty(list)){
        Dnode * p = CreateNode();
        list->head = p;
        list->tail = p;
        list->crnt = p;
        SetNode(p,x,list->tail,list->head);
    }else{
        Dnode * p = CreateNode();
        SetNode(p,x,list->tail,list->head)
        p = list->head->prev;
        list->head = p;
    }
}
//꼬리에 노드를 삽입
void InsertRear(Dlist * list, const DATA *x){
    if(IsEmpty(list)){
        Dnode * new = CreateNode();
        list->head = new;
        list->tail = new;
        list->crnt = new;
        SetNode(new,x,list->tail,list->head);
    }else{
        Dnode *p = CreateNode();
        SetNode(p,x,list->tail,list->head);
        list->tail->next = p;
        list->tail = p;
    }
}
// p가 가리키는 노드 바로 뒤에 노드를 삽입
void InsertAfter(Dlist * list, Dnode *p, const DATA *x){
    //필요정보 p 이전노드 주소, p다음노드 주소
    Dnode * new = CreateNode();
    SetNode(new,x,p,p->next);
    new = p->next->prev;
    p->next = new;

    if( p == list->tail){
        list->tail = new;
    }
}
// 삽입,삭제 작업에서 해야될일
// 1. 양쪽포인터 재조정
// 2. 리스트 head,tail포인터 재조정
//**************** delete ******************//
//머리 노드 삭제.  [head] --> [][del][] -->[][next element][]
void RemoveFront(Dlist * list){
    if(!IsEmpty(list)){
        if(IsOnlyOne(list)){
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->crnt = NULL;
        }else{
            Dnode * del = list->head;
            list->head = del->next;
            del->next->prev = list->tail;
            free(del);
        }
    }
}
//꼬리 노드 삭제
void RemoveRear(Dlist * list){
    if(!IsEmpty(list)){
        if(IsOnlyOne(list)){
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->crnt = NULL;
        }else{

        }
        Dnode * del = list->tail;
        list->tail = del->prev;
        del->prev->next = list->head;
        free(del);
    }
}
// 선택한 노드 삭제
void RemoveCurrent(Dlist *list){
    if(list->crnt != NULL){
        Remove(list,list->crnt);
    }
}
// p가 가리키는 노드 삭제
void Remove(Dlist *list,Dnode *p){
    if(!IsEmpty(list)){
        if(p!= NULL){
            if(p == list->head){
                list->head = p->next;
            }
            if(p == list->tail){
                list->tail = p->prev;
            }
            p->prev->next = del->next;
            p->next->prev = del->prev;
            free(p);
        }
    }
}
// 모든 노드를 삭제
void Clear(Dlist* list){

}
// 원형 이중연결 리스트 종료
void Terminate(Dlist *list){

}
int main(void){
    
    printf("==== 집합 예제 ====\n");
    srand(time(NULL));

    // initialize
    assert(!Initialize(&s1,(max*2)));
    assert(!Initialize(&s2,max)); 
    assert(!Initialize(&s3,max));

    //assign random number 
    for(int i=0; i<max; i++){
        s2.pSet[i] = 1 + rand() % 20;
        s3.pSet[i] = 1 + rand() % 20;
    }

    while(1){
        int menu, x, data;
        int yesno;
        
        printf("\n================= S E T ====================\n");
        printf("(1)IsMember(2)Add (3)Remove (4)Print (5)Equal \n");
        printf("(6)Assign     (7)Union     (8)Intersection \n");
        printf("(9)Difference (0)Exit \n");
        printf("============================================\n");
        scanf("%d", &menu);

        switch(menu){
            case 1: //IsMember
                printf("Set , data : ");
                scanf("%d %d", &x, &data);
                if(x==2){
                    if(IsMember(&s2,data) == NOT){
                        printf("s2집합에 %d [없다]\n",data);
                    }else{
                        printf("s2집합에 %d [있다]\n",data);
                    }
                }else if(x==3){
                    if(IsMember(&s3,data) == NOT){
                        printf("s3집합에 %d [없다]\n",data);
                    }else{
                        printf("s3집합에 %d [있다]\n",data);
                    }
                }
                break;
            case 2: // Add
                printf("Set , data : ");
                scanf("%d %d", &x, &data);
                if(x==2){
                    if(Add(&s2,data)){
                        printf("s2집합에 %d Add x\n",data);
                    }else{
                        printf("s2집합에 %d Add o\n",data);
                    }
                }else if(x==3){
                    if(Add(&s3,data)){
                        printf("s3집합에 %d Add x\n",data);
                    }else{
                        printf("s3집합에 %d Add o\n",data);
                    }
                }
                break;
            case 3: //Remove
                printf("Set , data : ");
                scanf("%d %d", &x, &data);
                if(x==2){
                    if(Remove(&s2,data)){
                        printf("s2집합에 %d Remove x\n",data);
                    }else{
                        printf("s2집합에 %d Remove o\n",data);
                    }
                }else if(x==3){
                    if(Remove(&s3,data)){
                        printf("s3집합에 %d Remove x\n",data);
                    }else{
                        printf("s3집합에 %d Remove o\n",data);
                    }
                }
                break;
            case 4://print
                printf("s1 set : ");
                for(int i=0; i< s1.num;  i++){
                    printf("%d ",s1.pSet[i]);
                }putchar('\n');
                printf("s2 set : ");
                for(int i=0; i<s2.num; i++){
                    printf("%d ",s2.pSet[i]);
                }putchar('\n');
                printf("s1 set : ");
                for(int i=0; i<s3.num; i++){
                    printf("%d ",s3.pSet[i]);
                }putchar('\n');
                break;
            case 5: // Equal
                if(Equal(&s2,&s3)){
                    printf("s2와 s3은 같습니다. equal=0\n");
                }else{
                    printf("s2와 s3은 틀립니다. equal=x\n");
                }
                break;
            case 6: // Assign
                if(Assign(&s2,&s3)){
                    printf("s3가 s2보다 더 큽니다. 대입연산 실패\n");
                }else{
                    printf("대입했습니다...\n");
                }
                break;
            case 7://union
                pSet=Union(&s1,&s2,&s3);
                break;
            case 8://intersection
                pSet=Intersection(&s1,&s2,&s3);
                break;
            case 9://difference
                pSet=Difference(&s1,&s2,&s3);
                break;
            case 0:// Exit
                printf("Program Exit");
                goto EXIT;
        }
        
    }
EXIT:
    Terminate(&s1);Terminate(&s2);Terminate(&s3);
    return 0;
}