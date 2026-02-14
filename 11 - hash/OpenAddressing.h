#ifndef __OPEN_ADDRESSING__
#define __OPEN_ADDRESSING__

typedef int Member;

// 버킷노드의 상태
typedef enum{
    OCCUPIED,   //값이있다
    EMPTY,      //비어있다
    DELETED     //삭제됐다
} Status;

typedef struct{
    Memeber data;
    Status stat;
}Bucket;

typedef struct{
    int size;
    Bucket * table;
}ClosedHash;

int Initialize(ClosedHash * h, const int size);
Bucket * Search(CloseHash *h, const Member *x);
int Add(CloseHash *h,const Member *x);
int Remove(CloseHash *h,const Member *x);
void Dump(CloseHash *h);
void Terminate(CloseHash *h);

#endif
