#include <stdio.h>
#include <stdlib.h>
#include "ChainHash.h"

int hash(int key,int size){
    return key % size;
}
void SetNode(Node * n,const Member *x,const Node *next){
    n->data = *x;
    n->next = next;
}
/ 해시테이블 초기화
int Init(ChainHash * h,int size){

}
// x검색
Node * Search(ChainHash *h,const Member *x){

}
// x추가
int Add(ChainHash *h, const Member *x){

}
// x삭제
int Remove(ChainHash *h,const Memeber *x){

}
// print all
void Dump(const ChainHash *h){

}

void Terminate(ChainHash *h){

}
int main(void){

    return 0;
}