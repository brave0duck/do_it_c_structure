#ifndef __CHAINHASH__
#define __CHAINHASH__

typedef int Member;

typedef struct __node{
    Member data;
    struct __node *next;
}Node;

typedef struct __hash{
    int size;
    Node ** table;
}ChainHash;

// 해시함수
int hash(int key,int size);
// 노드추가
void SetNode(Node * n,const Member *x,const Node *next);

// 해시테이블 초기화
int Init(ChainHash * h,int size);
// x검색
Node * Search(ChainHash *h,const Member *x);
// x추가
int Add(ChainHash *h, const Member *x);
// x삭제
int Remove(ChainHash *h,const Member *x);
// print all
void Dump(const ChainHash *h);
// 종료
void Terminate(ChainHash *h);
#endif