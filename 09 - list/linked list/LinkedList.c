// 싱글 1링크드리스트 구현 연습
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node *AllocNode(void){
    return calloc(1,sizeof(Node));
}
static void SetNode(Node *n,const Member *x, const Node* next){
    n->data = *x;
    n->next = (Node*)next;
}
int Initialize(List * list){
    list->head = NULL;
    list->crnt = NULL;
}
int compare(const Member *x, const Member *y){
    if(*x > *y){
        return -1;
    }
    else if(*x < *y){
        return 1;
    }else{
        return 0;
    } 
}
Node* Search(List *list,const Member *x, int compare(const Member *x, const Member *y)){
    Node * p = list->head;
    do{
        if(compare(&p->data,x) == 0){
            list->crnt = p;
            return p;
        }
        p = p->next;
    }while(p != NULL);
    
    return NULL;
}
// 맨앞 노드에 추가
void InsertFront(List* list,const Member *x){
    Node *p = list->head;
    list->head = AllocNode();
    SetNode(list->head,x,p);
}
// 맨뒤 노드에 추가
void InsertRear(List* list, const Member *x){
    if(list->head == NULL){
        InsertFront(list,x);
    }else{
        Node * p = list->head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = list->crnt = AllocNode();
        SetNode(list->crnt,x,NULL);
    }
}
// 맨앞 노드 삭제
void RemoveFront(List * list){
    if(list->head != NULL){
        Node * p = list->head;
        list->head = p->next;
        free(p);
    }
}
// 맨뒤 노드 삭제
void RemoveRear(List *list){
    if(list->head !=NULL){
        if(list->head->next == NULL){   //if node only 1
            RemoveFront(list);
        }else{
            Node *p = list->head;
            while(p->next->next != NULL){
                p = p->next;
            }
            free(p->next);
            p->next = NULL;
        }
    }
}
void RemoveCurrent(List * list){
    Node * p = list->head;
    if(p->next == NULL){    // if only node 1
        RemoveFront(list);
    }else{
        while(p->next != list->crnt){
            p = p->next;
        }
        p->next = list->crnt->next;
        free(list->crnt);
        list->crnt = NULL;
    }
}
void Clear(List* list){
    while(list->head != NULL){
        RemoveFront(list);
    }
}
void PrintCurrent(const List* list){
    printf("Current Node data is %d",list->crnt->data);
}
void PrintlnCurrent(const List* list){
    printf("Current Node data is %d\n",list->crnt->data);
}
void PrintAll(const List * list){
    Node *p = list->head;
    if(p == NULL){
        printf("No Element");
    }else{
        printf("[Head] -> ");
        while(p != NULL){
            printf("%d ",p->data);
            p= p->next;
        }
    }
    putchar('\n');
}
void Terminate(List * list){
    Clear(list);
    list->head=NULL;
    list->crnt=NULL;
}
int main(void){
    
    printf("<원형 더블 링크드 리스트 예제>\n");
    

    // initialize
    List sll;
    Initialize(&sll);

    while(1){
        int menu, x, data;
        Node *s;
        
        printf("\n============ 싱글 링크드-리스트 ===================\n");
        printf("(1)앞 추가 (2)뒤 추가 (3)검색 (4)현재 출력 (5)전체 출력\n");
        printf("(6)앞 삭제 (7)뒤 삭제 (8)검색 삭제  (9)초기화 (0)종료 \n");
        printf("=======================================================\n");
        scanf("%d", &menu);

        switch(menu){
            case 1: // InsertFront
                printf("데이터 입력 : ");
                scanf("%d",&data);
                InsertFront(&sll,&data);
                break;
            case 2: // InsertRear
                printf("데이터 입력 : ");
                scanf("%d",&data);
                InsertRear(&sll,&data);
                break;
            case 3: // Search and Insert
                printf("검색 : ");
                scanf("%d",&x);
                s = Search(&sll,&x,compare);
                if(s){
                    printf("찾았습니다. %d in list\n",s->data);
                }else{
                    printf("검색 데이터를 찾지못했습니다.\n");
                }
                break;
            case 4: // current print
                PrintlnCurrent(&sll);
                break;
            case 5: // print
                PrintAll(&sll);
                break;
            case 6: // Remove Front
                RemoveFront(&sll);
                printf("삭제했습니다\n");
                break;
            case 7:// Remove Rear
                RemoveRear(&sll);
                printf("삭제했습니다\n");
                break;
            case 8:// Search and Remove
                printf("검색해서 삭제 : ");
                scanf("%d",&x);
                s = Search(&sll,&x,compare);
                if(s){
                    RemoveCurrent(&sll);
                }else{
                    printf("삭제할 데이터 찾지못했습니다.\n");
                }
                break;
            case 9://Clear
                Clear(&sll);
                printf("모든 노드가 초기화되었습니다.\n");
                break;
            case 0:// Exit
                printf("프로그램을 종료합니다...\n");
                goto EXIT;
        }
        
    }
EXIT:
    Terminate(&sll);
    return 0;
}