// chain-hash 임시구현
// 해시충돌을 방지하기위해 해시테이블내에 링크드리스트로 연결된다
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "ChainHash.h"
#define SIZE 10

enum MAIN_MENU {
    EXIT,    //0,
    ADD,    //1
    SEARCH, //2
    REMOVE, //3
    PRINT,  //4
};
// 해시함수 . 값 % 사이즈
int hash(int key,int size){
    return key%size;
}
void SetNode(Node * n,Member *x,Node *next){
    n->data = *x;
    n->next = next;
}
Node * CreateNode(void){
    return calloc(1,sizeof(Node));
}
// 해시테이블 초기화
int Init(ChainHash * h,int size){
    h->table = (Node **)calloc(size,sizeof(Node*));
    assert(h->table != NULL);
    
    for(int i=0; i<size ; i++){
        h->table[i] = NULL;
    }
    h->size = size;
}
// x추가. 1.해시함수로 얻은 결과에 해당하는 인덱스를 찾는다
// 2. 인덱스가 널이면 노드를 새로 만든다
// 3. 널이아니라면 노드의 마지막을 찾아 추가한다
int Add(ChainHash *h, Member *x){
    // 1
    int index = hash(*x,h->size);
    
    // 2
    if( h->table[index] == NULL){
        Node * p = CreateNode();
        SetNode(p,x,NULL);
        h->table[index] = p;
    }// 3
    else{  
        Node * p = h->table[index];
        while(p->next != NULL){
            if(p->next->data == *x)// 겹치는 숫자는 입력하지 않는다 (필요없으면 제외)
                return -1;
            p = p->next;
        }
        p->next = CreateNode();
        SetNode(p->next,x,NULL);
    }
    return 0;
}
// x검색. 
/*  1. 해시함수로 얻은 결과로 초기 인덱스를 찾는다
    2. 인덱스의 처음부터 끝까지 반복하면서 노드를 찾는다
    3. 찾은노드의 이전노드를 리턴
 $ 해당노드가 아닌 해당노드의 전노드를 리턴한다. 
   그래야 노드연결작업이 가능. 더블링크드리스트가 아니기때문에
*/

Node * Search(ChainHash *h,Member *x){
    // 1
    int index = hash(*x,h->size);
    assert(0 <= index && index < SIZE);

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
                }
                prev = find;
                find = find->next;
            }
        }
        
    }
    return NULL;

}
// x삭제.
// 1. Search()함수로 이전노드를 찾는다
// 2. 링크연결작업후
// 3. 메모리해제
int Remove(ChainHash *h,Member *x){
    // 1
    Node* find_prev = Search(h,x);
    // 멤버가 없으면 종료
    if(find_prev->next == NULL){
        return -1;
    }else{
        Node * del = find_prev->next;
        find_prev->next = del->next;    //2
        free(del);                      //3
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
        Node * del, * next_del; // 다음삭제할 포인트를 next_del에 저장. sll이므로
        del = h->table[i];
        
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
static int menu_view(void){
    int x;
    printf("======== hash table (chain version) ========\n");
    printf("(1)ADD (2)SEARCH (3)REMOVE (4)PRINT (0)EXIT\n");
    printf("============================================\n");
    printf("select : ");
    scanf("%d",&x);
    return x;
}
int main(void){
    srand(time(NULL));
    int menu,select,user_input;

    ChainHash h;
    Init(&h,SIZE);

    for(int i=0; i<30; i++){
        Member x = rand() % 100;
        Add(&h, &x);
    }
    printf("랜덤수(0-99) 30개가 해시테이블에 저장되어있습니다.")
//------------------------------여기까지
    while(select = menu_view()){
        switch(select){
            case ADD:
                printf("추가할 정수 : ");
                scanf("%d",&user_input);
                if( -1 == Add(h,&user_input)){
                    printf("데이터중복. 입력x\n");
                }
                break;
            case SEARCH:
                printf("찾을 정수 : ");

        }
    }

    Dump(&h);
    return 0;
}