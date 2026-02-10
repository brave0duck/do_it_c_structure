// 원형 이중연결 리스트 구현
#include <stdio.h>
#include <stdlib.h>
#include "CD_LinkedList.h"

static Dnode* CreateNode(void){
    return calloc(1,sizeof(Dnode));
}
static void SetNode(Dnode * node, const DATA *x, Dnode * prev, Dnode * next){
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
        printf("[head] -> ");
        do{
            printf("%d ",pNode->x);
            pNode = pNode->next;
        }while(pNode != list->head);
    }else{
        printf("No Element\n");
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
// 삽입,삭제 작업에서 해야될일
// 1. 양쪽포인터 재조정
// 2. 리스트 head,tail포인터 재조정
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
        SetNode(p,x,list->tail,list->head);
        list->head->prev = p;
        list->head = p;

        list->tail->next = p;
        
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
    //new = p->next->prev;
    p->next = new;
    list->tail = new;

    if(new->next == list->head){
        list->head->prev = new;
    }
    
}
//**************** delete ******************//
//머리 노드 삭제.  [head] --> [][del][] -->[][next element][]
void RemoveFront(Dlist * list){
    if(!IsEmpty(list)){
        if(IsLast(list)){
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->crnt = NULL;
        }else{
            Dnode * del = list->head;
            // head, tail 작업
            list->head = del->next;
            list->tail->next = del->next;
            del->next->prev = list->tail;
            
            free(del);

        }
    }
}
//꼬리 노드 삭제. 삭제전 작업. head,tail 재조정 + 전노드의 next를 바꾸기
void RemoveRear(Dlist * list){
    if(!IsEmpty(list)){
        if(IsLast(list)){
            free(list->head);
            list->head = NULL;
            list->tail = NULL;
            list->crnt = NULL;
        }else{
            // del 삭제할 노드
            Dnode * del = list->tail;
            // 1. head노드를 재조정
            list->head->prev = del->prev;
            // 2. tail 재조정
            list->tail = del->prev;
            // 3. 새 노드의 next를 head로 바꿈
            del->prev->next = list->head;
            // 4. 최종적으로 del 삭제
            free(del);
        }
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
            p->prev->next = p->next;
            p->next->prev = p->prev;
            
            if(p == list->head){
                list->head = p->next;
                p->next->prev = list->tail;
                list->tail->next = p->next;
            }
            if(p == list->tail){
                list->tail = p->prev;
                list->head->prev = p->prev;
                list->tail->next = list->head;
            }
            free(p);
        }
    }
}
// 모든 노드를 삭제
void Clear(Dlist* list){
    while(!IsEmpty(list)){
        Remove(list,list->head);
    }
}
// 원형 이중연결 리스트 종료
void Terminate(Dlist *list){
    Clear(list);
    list->head = NULL;
    list->crnt = NULL;
    list->tail = NULL;
}
int main(void){
    
    printf("==== 원형 더블 링크드 리스트 예제 ====\n");
    

    // initialize
    Dlist dlist;
    Initialize(&dlist);

    while(1){
        int menu, x, data;
        Dnode *s;
        
        printf("\n========== Circle Double Linked-List =============\n");
        printf("(1)앞 추가 (2)뒤 추가 (3)검색뒤 추가 (4)검색  (5)출력 \n");
        printf("(6)앞 삭제 (7)뒤 삭제 (8)검색후 삭제 (9)초기화 (0)종료 \n");
        printf("====================================================\n");
        scanf("%d", &menu);

        switch(menu){
            case 1: // InsertFront
                printf("데이터 입력 : ");
                scanf("%d",&data);
                InsertFront(&dlist,&data);
                break;
            case 2: // InsertRear
                printf("데이터 입력 : ");
                scanf("%d",&data);
                InsertRear(&dlist,&data);
                break;
            case 3: // Search and Insert
                printf("검색, 데이터 : ");
                scanf("%d %d",&x, &data);
                s = Search(&dlist,&x);
                if(s){
                    InsertAfter(&dlist, s, &data);
                }else{
                    printf("검색 데이터를 찾지못했습니다.\n");
                }
                break;
            case 4: // search
                printf("검색 : ");
                scanf("%d",&data);
                if(!Search(&dlist,&data)){
                    printf("검색 데이터를 찾지못했습니다.\n");
                }
                break;
            case 5: // print
                Print(&dlist);
                break;
            case 6: // Remove Front
                RemoveFront(&dlist);
                break;
            case 7:// Remove Rear
                RemoveRear(&dlist);
                break;
            case 8:// Search and Remove
                printf("검색해서 삭제 : ");
                scanf("%d",&x);
                s = Search(&dlist,&x);
                if(s){
                    Remove(&dlist, s);
                }else{
                    printf("삭제할 데이터 찾지못했습니다.\n");
                }
                break;
            case 9://Clear
                Clear(&dlist);
                break;
            case 0:// Exit
                printf("Program Exit");
                goto EXIT;
        }
        
    }
EXIT:
    Terminate(&dlist);
    return 0;
}