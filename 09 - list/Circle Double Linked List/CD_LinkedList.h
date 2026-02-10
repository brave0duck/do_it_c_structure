//원형 이중연결 리스트 구현
#ifndef __CD_LINKEDLIST.H__
#define __CD_LINKEDLIST.H__

typedef int DATA;

// 노드 데이타 x, 이전 prev ,다음 next
typedef struct __node{
    DATA x;
    struct __node * next;
    struct __node * prev;
}Dnode;

// 머리,꼬리, 검색을 위한 현재포인트
typedef struct {
    Node * head;
    Node * tail;
    Node * crnt;

}Dlist;

Dnode* CreateNode(void);
void SetNode(Dnode *node,const DATA *x,const Dnode* prev, const Dnode* next);
// 초기화
void Initialize(Dlist * list);

int IsEmpty(Dlist* list);
int IsLast(Dlist * list);
int IsOnlyOne(Dlist* list);
//리스트에서 특정 원소를 가진 요소 찾기
Dnode* Search(Dlist *list,const DATA *x);

//**************** print *******************//
// 모든 리스트 출력
void Print(const Dlist* list);
// 현재 가리키는 요소 출력
void PrintCurrent(const Dlist *list);
// 모든 리스트 출력 (반대로)
void PrintReverse(const Dlist* list);

//**************** move *******************//

//선택한 노드의 다음으로 
int CurrentNext(Dlist *list);
// 선택한 노드의 이전으로 
int CurrentPrev(Dlist *list);

//**************** insert *******************//
//머리에 노드를 삽입
void InsertFront(Dlist * list,const DATA *x);
//꼬리에 노드를 삽입
void InsertRear(Dlist * list, const DATA *x);
// p가 가리키는 노드 바로 뒤에 노드를 삽입
void InsertAfter(Dlist * list, Dnode *p, const DATA *x);


//**************** delete ******************//
// p가 가리키는 노드 삭제
void Remove(Dlist *list,Dnode *p);
//머리 노드 삭제
void RemoveFront(Dlist * list);
//꼬리 노드 삭제
void RemoveRear(Dlist * list);
// 선택한 노드 삭제
void RemoveCurrent(Dlist *list);

// 모든 노드를 삭제
void Clear(Dlist* list);

// 원형 이중연결 리스트 종료
void Terminate(Dlist *list);

#endif