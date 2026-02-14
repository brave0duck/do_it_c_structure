// 오픈어드레싱 해쉬. 자료를 골고루 나누어 저장하는 로직으로 재해싱을 통해 자료를 저장. 
// 자료의 위치가 유동적으로 변화하며 오직 함수를 통해서만 검색,삭제가 가능

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "OpenAddressing.h"
#include "bitset.h"
#define NOT_OK -1
#define OK 0

typedef unsigned long BitSet;
#define BitSetNull  (BitSet)0
#define BitSetBits  64
#define SetOf(no)   ((BitSet)1<<(no))


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
    Bucket * p = h->table[key];

    if( p->stat == EMPTY || p->stat == DELETED){
        p->data = mdata;
        p->stat = OCCUPIED;
    }else{
        while(p->stat == OCCUPIED){
            int another_key = rehash(mdata++,size);
            p = h->table[another_key];
            if(counting++ > h->size){
                return NOT_OK;
            }
        }
        p->data = *x;
        p->stat = OCCUPIED;
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
    
    while(counting <= h->size){
        if(h->table[index].data == *x){
            return p;
        }else{
            index = rehash(mdata++,h->size);
        }
        counting++;
    }
    return NULL;
}
// 비트셋 로직 활용해보자 (set)
// logic : 1.unsigned long a[size]
// 2. 처음 버킷부터 끝까지 돌면서 OCCUPIED상태의 버킷 값을 해시로 돌려서 인덱스값을 구한후 해당 배열 첨자의 bitset에 seton
// 3. 비트셋 처음부터 끝까지 돌면서 해당 인덱스를 얻어 그 값을 프린트





//-------------------------- 여기까지 ---------------------------------
void Dump(ClosedHash *h){
    BitSet * p = calloc(h->size,sizeof(BitSet));
    for(int i=0; i<h->size ; i++){
        if(h->table[i].stat == OCCUPIED){
            int index = hash(h->table[i].data,h->size);
            p[i] = p[i] | SetOf(index)
        }
    }
    *s |= SetOf(n);

}
// 테이블 메모리해제후 나머지 값 초기화
void Terminate(ClosedHash *h){

}

int main(void){

    return 0;
}