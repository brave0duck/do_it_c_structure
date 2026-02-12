//이진검색트리 구현
#ifndef __BINTREE__
#define __BINTREE__

typedef int Member;

typedef struct __bnode{
    Member data;
    struct __bnode *left;
    struct __bnode *right;
}BinNode;
//검색
BinNode* Search(BinNode *p,const Member *x);
//추가
BinNode* Add(BinNode *p,const Member *x);
//삭제
int Remove(BinNode **root,const Member *x);
//출력
void PrintTree(const BinNode *p);
//모두해제
void FreeTree(BinNode *p);

#endif