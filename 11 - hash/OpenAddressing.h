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
    Member data;
    Status stat;
}Bucket;

typedef struct{
    int size;
    Bucket * table;
}ClosedHash;

int Initialize(ClosedHash * h, const int size);
Bucket * Search(ClosedHash *h, const Member *x);
int Add(ClosedHash *h,const Member *x);
int Remove(ClosedHash *h,const Member *x);
void Dump(ClosedHash *h);
void Clear(ClosedHash *h);
void Println(Bucket * b);
void Terminate(ClosedHash *h);

#endif
