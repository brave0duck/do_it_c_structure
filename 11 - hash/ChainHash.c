// 체인해시 임시구현
// 해시충돌을 방지하기위해 해시테이블내에 링크드리스트로 연결된다
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "ChainHash.h"

// 해시함수 . 값 % 사이즈
static int hash(int key,int size){
    return key%size;
}
static void SetNode(Node * n,const Member *x,const Node *next){
    n->data = *x;
    n->next = next;
}
static Node * CreateNode(void){
    return calloc(1,sizeof(Node));
}
// 해시테이블 초기화
int Init(ChainHash * h,int size){
    h->table = calloc(size,sizeof(Node));
    assert(h->table != NULL);
    
    for(int i=0; i<size ; i++){
        h->table[i] = NULL;
    }
    h->size = size;
}
// x추가. 1.해시함수로 얻은 결과에 해당하는 인덱스를 찾는다
// 2. 인덱스가 널이면 노드를 새로 만든다
// 3. 널이아니라면 노드의 마지막을 찾아 추가한다
int Add(ChainHash *h, const Member *x){
    // 1
    int index = hash(*x,h->size);
    assert(0 <= index && index < size);
    // 2
    if( h->table[index] == NULL){
        Node * p = CreateNode();
        SetNode(p,*x,NULL);
        h->table[index] = p;
    }// 3
    else{  
        Node * p = h->table[index];
        while(p->next != NULL){
            p = p->next;
        }
        p->next = CreateNode();
        SetNode(p->next,*x,NULL);
    }
    return index;
}
// x검색. 해당노드가 아닌 해당노드의 전노드를 리턴한다. 그래야 노드연결작업이 가능. 더블링크드리스트가 아니기때문에
Node * Search(ChainHash *h,const Member *x){
    int index = hash(*x,h->size);
    assert(0 <= index && index < size);

    if(h->table[index] == NULL){
        printf("Error. can't find [%d] data",*x);
    }else{
        if(h->table[index]->data == *x){
            return h->table[index];
        }else{
            Node * prev = h->table[index];
            Node * find = prev->next;
            
            while(find != NULL){
                if(find->data == *x){
                    return prev;
                }else{
                    prev = find;
                    find = find->next;
                }
            }
        }
        
    }
    return NULL;

}
// x삭제. 1. 해시함수로 얻은 결과에 해당하는 인덱스를 찾는다
// 2. 인덱스가 널이면 오류메세지를 출력하고 종료
// 3. 찾았다면 노드 교환작업을 하고 해당노드는 해제한다.
// 교환작업 - 해당노드 이전 next를 해당노드 다음과 연결

//-------------------- 여기까지 
int Remove(ChainHash *h,const Memeber *x){

    Node* result = Search(h,x);
    if(result == NULL){
        return -1;
    }else{
        int index = hash(*x,h->size);
        if(h->table[index] == result){

        }else{

        }
        // 삭제될 노드 이전 노드가 리턴된다. 따라서 삭제되는 노드는 result->next다
        Node * del = result->next;
        result->next = del->next;
        free(del);
        return 0;
    }
    
}
// print all
void Dump(const ChainHash *h){
    for(int i=0; i<h->size; i++){
        Node *p = h->table[i];
        printf("[%d] -- ",i);
        while(p!=NULL){
            printf("%d ",p->data);
            p = p->next;
        }
        putchar('\n');
    }
}
void Terminate(ChainHash *h){
    // 포인터배열내에 링크드리스트 모두 해제
    for(int i=0; i<h->size; i++){
        Node * del = h->table[i];
        Node * next_del;
        while(del != NULL){
            next_del = del->next;
            free(del);
            del = next_del;
        }
    }
    // 포인터배열 자체도 해제
    free(h->table);
    h->size=0;
}
int main(void){
    srand(time(NULL));

    ChainHash h;
    Init(&h);

    for(int i=0; i<10; i++){
        rand() % 10
    }
    return 0;
}