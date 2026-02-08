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
    if(p != NULL){
        do{
            if(compare(&p->data,x) == 0){
                list->crnt = p;
                return p;
            }
            p = p->next;
        }while(p->next != NULL);
    }
    return NULL;
}

void InsertFront(List* list,const Member *x){
    list->crnt = AllocNode();
    SetNode(list->crnt,x,list->head);
    list->head = list->crnt;
}

void InsertRear(List* list, const Member *x);

void RemoveFront(List * list);

void RemoveRear(List *list);

void RemoveCurrent(List * list);

void Clear(List* list);

void PrintCurrent(const List* list);

void PrintlnCurrent(const List* list);

void PrintAll(const List * list);

void Terminate(List * list);

int main(void){

    return 0;
}