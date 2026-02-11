#ifndef __LINKEDLIST__
#define __LINKEDLIST__

typedef struct __node{
    int data;
    struct __node * next;
}Node;

typedef struct {
    Node * head;
    Node * crnt;
}List;

typedef int Member;

int Initialize(List * list);
Node* Search(List *list,const Member *x, int compare(const int *x, const int *y));
void InsertFront(List* list,const Member *x);
void InsertRear(List* list, const Member *x);
void RemoveFront(List * list);
void RemoveRear(List *list);
void RemoveCurrent(List * list);
void Clear(List* list);
void PrintCurrent(const List* list);
void PrintlnCurrent(const List* list);
void PrintAll(const List * list);
void Terminate(List * list);

#endif