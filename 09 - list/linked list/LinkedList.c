// 링크드리스트 구현 연습
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

static Node *AllocNode(void){
    return calloc(1,sizeof(Node));
}
static void SetNode(Node *n,const Member *x, const Node* next){
    n->data = *x;
    n->next = next;
}
int Initialize(List * list){
    list->head = NULL;
    list->crnt = NULL;
}
int compare(const Member *x, const Member *y){
    if(*x > *y) return -1;
    else if(*y < *y)    return 1;
    else return 0;
}
Node* Search(List *list,const Member *x, int compare(const Member *x, const Member *y)){
    Node * p = list->head;
    while(p != NULL){
        if(compare(&p->data,x) == 0){
            list->crnt = p;
            return p;
        }
        p = p->next;
    }
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
        list->crnt = p;
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
    for(int i=1; p != NULL; i++){
        printf("%dth Node data is %d\n", i, p->data);
        p= p->next;
    }
}
void Terminate(List * list){
    Clear(list);
    list->head=NULL;
    list->crnt=NULL;
}
int main(void){

    return 0;
}