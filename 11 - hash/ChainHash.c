//**************************************************************
// chain-hash 임시구현. 해시테이블내에 링크드리스트로 연결된다
//  [**table]
//   |
//  table[0]-table[1]-table[2]-table[3]-table[4] <-- hash table
//  |       |         |        |         | 
//  []      []        []       []        x        <-- node
//  []      []        x        x
//*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "ChainHash.h"
#define SIZE 13

typedef enum {
    ADD=1,    //1
    SEARCH, //2
    REMOVE, //3
    PRINT,  //4
    EXIT,   //5

} MENU;

static int hash(int key,int size){
    return key%size;
}
Node * CreateNode(void){
    return calloc(1,sizeof(Node));
}
static void SetNode(Node * n,Member *x,Node *next){
    n->data = *x;
    n->next = next;
}
static MENU menu_view(void){
    char buf[64];
    long val;
    char *end;

    for(;;){
        printf("======== hash table (chain version) ========\n");
        printf("(1)ADD (2)SEARCH (3)REMOVE (4)PRINT (5)EXIT\n");
        printf("============================================\n");
        printf("select : ");

        if(!fgets(buf, sizeof(buf), stdin)){
            clearerr(stdin);
            continue;
        }

        val = strtol(buf, &end, 10);
        if (end == buf) {
            printf("잘못된 입력입니다. 숫자(1-5)를 입력하세요.\n");
            continue;
        }
        /* 남은 문자가 숫자 외인 경우도 거르기 */
        while (*end == ' ' || *end == '\t') end++;
        if (*end != '\n' && *end != '\0') {
            printf("잘못된 입력입니다. 숫자(1-5)를 입력하세요.\n");
            continue;
        }

        if (val >= 1 && val <= 5)
            return (MENU)val;

        printf("범위를 벗어났습니다. 1~5 사이를 입력하세요.\n");
    }
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
// Add() 
// 1. 해시함수로 인덱스를 구한다
// 2. 인덱스가 널이면 (멤버가 없으면) 노드를 새로 만든다
// 3. 널이아니면 (기존 멤버가 있으면) 노드의 마지막을 찾아 추가한다
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
        
        while(p != NULL){
            if(p->data == *x){  //요소가 겹치지않게 하려면 이 문장추가
                return -1;
            }
            if(p->next == NULL){
                break;
            }
            p = p->next;
        }
        p->next = CreateNode();
        SetNode(p->next,x,NULL);
    }
    return 0;
}
// Search()
/*  1. 해시함수로 인덱스를 구한다
    2. 인덱스의 링크드리스트 처음부터 끝까지 반복. 노드를 찾는다
    3. 찾은노드의 이전노드를 리턴 (이전노드를 리턴. 그래야 노드연결작업이 가능. 더블링크드리스트가 아니기때문에)
*/
Node * Search(ChainHash *h,Member *x){
    // 1
    int index = hash(*x,h->size);
    assert(0 <= index && index < SIZE);

    if(h->table[index] != NULL){
        if(h->table[index]->data == *x){// 첫노드면 그냥 첫노드를 리턴
            return h->table[index];
        }
        Node * prev = h->table[index];
        Node * find = prev->next;
        
        while(find != NULL){
            if(find->data == *x){       //찾으면 노드 리턴
                return prev;
            }
            prev = find;
            find = find->next;
        }
    }
    return NULL;
}
// Remove()
// 1. Search()함수로 노드를 찾는다 (삭제할 노드의 이전노드)
// 2. 링크연결작업후
// 3. 메모리해제
int Remove(ChainHash *h,Member *x){
    int index = hash(*x,h->size);
    // 1
    Node* find_prev = Search(h,x);
    
    if(find_prev == NULL)
        return -1;

    if(find_prev == h->table[index]){ // 첫 노드인 경우 이전노드가 없으므로 그냥 삭제한다
        free(find_prev);
        h->table[index] = NULL;
    }else{                              // 첫 노드가 아니면 링크연결작업 후 메모리삭제
        Node * del = find_prev->next;
        find_prev->next = del->next;    //2
        free(del);       
        return 0;               //3
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
        Node * del;
        Node * next_del; // 다음삭제할 포인트를 next_del에 저장. sll이므로
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
int main(void){
    srand(time(NULL));
    MENU menu_select;
    Member user_input;

    ChainHash h;
    Init(&h,SIZE);

    for(int i=0; i<30; i++){
        Member x = rand() % 100;
        Add(&h, &x);
    }
    printf("랜덤수(0-99) 30개가 해시테이블에 저장되어있습니다.");

    while((menu_select = menu_view()) ){
        switch(menu_select){
            case ADD:
                printf("추가 : ");
                scanf("%d",&user_input);
                if( -1 == Add(&h,&user_input)){
                    printf("데이터중복. 입력x\n");
                }
                break;
            case SEARCH:
                Node * node_prev;
                printf("검색 : ");
                scanf("%d",&user_input);
                node_prev = Search(&h,&user_input);
                if(node_prev == NULL){
                    printf("찾을수 없습니다.\n");
                }else{
                    printf("[%d]가 테이블에 존재합니다.\n", user_input);
                }
                break;
            case REMOVE:
                printf("삭제할 정수 : ");
                scanf("%d",&user_input);
                if( Remove(&h,&user_input) != -1){
                    printf("\n삭제했습니다.\n");
                }else{
                    printf("찾을수 없습니다.\n");
                }
                break;
            case PRINT:
                printf("=== 테이블 상태 ===\n");
                Dump(&h);
                break;
            case EXIT:
                printf("\n프로그램을 종료합니다...\n");
                Terminate(&h);
                return 0;
            default:
                break;
        }
    }
    return 0;
}