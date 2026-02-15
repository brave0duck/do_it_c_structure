#include <stdio.h>
#include <stdlib.h>
#include "OpenAddressing.h"

#define NOT_OK -1
#define OK 0


typedef enum{
    TERMINATE,
    ADD,
    DELETE,
    SEARCH,
    CLEAR,
    DUMP
} Menu;

static int hash(int key,int size){
    return key%size;
}
static int rehash(int key,int size){
    return (key+1)%size;
}
Bucket * CreateBucket(void){
    return calloc(1,sizeof(Bucket));
}
static void SetNode(Bucket * b,Member *x,Status stat){
    b->data = *x;
    b->stat = stat;
}
int Initialize(ClosedHash * h, const int size){
    h->table = calloc(size,sizeof(Bucket));

    if(h->table == NULL){
        h->size =0;
        return NOT_OK;
    }else{
        for(int i=0; i<size; i++){
            h->table[i].stat = EMPTY;
        }
        h->size = size;
        return OK;
    }
}
// logic : 1. 해시함수로 돌린 결과에 해당하는 인덱스에 있는 자료가 비어있는지 확인?
//         2. if EMPTY or DELETED -> 결과 입력
//         3. if OCCUPITED라면 EMPTY OR DELETE가 나올때까지 rehash()
int Add(ClosedHash *h,const Member *x){
    int counting=0;
    Member mdata = *x;
    int key = hash(*x,h->size);
    
    if( h->table[key].stat == EMPTY || h->table[key].stat == DELETED){
        h->table[key].data = mdata;
        h->table[key].stat = OCCUPIED;
    }else{
        while(h->table[key].stat == OCCUPIED){
            key = rehash(mdata++,h->size);
            if(counting++ > h->size){
                return NOT_OK;
            }
        }
        h->table[key].data = *x;
        h->table[key].stat = OCCUPIED;
    }
    return OK;
}
// logic : 1.자료를 찾아서 찾은자료의 stat를 deleted로 바꾼다
int Remove(ClosedHash *h,const Member *x){
    Bucket * p = Search(h,x);
    if(p != NULL){
        p->stat = DELETED;
        return OK;
    }
    return NOT_OK;
}
// logic : 1.해시함수를 돌린다.
// 2. 그결과에 따라 거기부터 마지막까지 반복
// 3. 현재 인덱스의 값과 찾는값을 비교
// 4. 없으면 rehash
Bucket * Search(ClosedHash *h, const Member *x){
    int counting=0;
    Member mdata = *x;
    int index = hash(mdata,h->size);
    
    if(h->table[index].stat == EMPTY){
        return NULL;
    }else{
        while(counting <= h->size){
            if(h->table[index].data == *x){
                return &(h->table[index]);
            }else{
                index = rehash(mdata++,h->size);
            }
            counting++;
        }
    }
    return NULL;
}
// 비트셋 로직 활용해보자 (set)
// logic : 1.unsigned long a[size]
// 2. 처음 버킷부터 끝까지 돌면서 OCCUPIED상태의 버킷 값을 해시로 돌려서 인덱스값을 구한후 해당 배열 첨자의 bitset에 seton
// 3. 비트셋 처음부터 끝까지 돌면서 해당 인덱스를 얻어 그 값을 프린트
void Dump(ClosedHash *h){
    
    for(int i=0; i<h->size ; i++){
        printf("[%d] -- ",i);
        switch(h->table[i].stat){
            case OCCUPIED:
                printf("%d ", h->table[i].data);
                break;
            case DELETED:
                printf("[삭제]");
                break;
            case EMPTY:
                printf("[비어있습]");
                break;
        }
        putchar('\n');
    }
}
void Clear(ClosedHash *h){
    for(int i=0; i<h->size; i++){
        h->table[i].stat = EMPTY;
    }
}
void Println(Bucket * b){
    printf("%d\n",b->data);
}
// 테이블 메모리해제후 나머지 값 초기화
void Terminate(ClosedHash *h){
    Clear(h);
    if(h->table != NULL){
        free(h->table);
    }
    h->size=0;
}
Menu SelectMenu(void){
    int ch;
    do{
        printf("================ Open Addressing Hash =====================\n");
        printf("(1)Add (2)Remove (3)Search (4)All Delete (5)Dump (0)Exit\n");
        printf("===========================================================\n\n");
        printf("select : ");
        scanf("%d",&ch);
    }while( ch < TERMINATE || ch > DUMP);

    return (Menu)ch;
}
int main(void){
    Menu menu;
    ClosedHash hash;
    if(Initialize(&hash,13) == NOT_OK)
        return -1;

    do{
        int result;
        Member x;
        Bucket *temp;
        switch(menu = SelectMenu()){
            case ADD:
                printf("추가할 데이터는 : ");
                scanf("%d",&x);
                if(Add(&hash,&x)== NOT_OK){
                    printf("오류 : 추가에 실패했습니다\n");
                }else{
                    printf("추가되었습니다.\n");
                }
                break;
            case DELETE:
                printf("삭제할 데이터는 : ");
                scanf("%d",&x);
                if(Remove(&hash,&x)==NOT_OK){
                    printf("오류 : 삭제에 실패했습니다\n");
                }else{
                    printf("삭제했습니다\n");
                }
                break;
            case SEARCH:
                printf("검색할 데이터는 : ");
                scanf("%d",&x);
                Bucket * p = Search(&hash,&x);
                if(p==NULL){
                    printf("오류 : 검색에 실패했습니다\n");
                }else{
                    printf("검색되었습니다. ");
                    Println(p);
                }
                break;
            case CLEAR:
                Clear(&hash);
                printf("해시테이블이 초기화되었습니다\n");
                break;
            case DUMP:
                Dump(&hash);
                break;

        }
    }while(menu != TERMINATE);
    Terminate(&hash);
    printf("프로그램을 종료합니다\n");
    return 0;
}