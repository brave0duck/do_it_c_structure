#include <stdio.h>
#include <stdlib.h>
#include "OpenAddressing.h"

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

int Initialize(ClosedHash * h, const int size);
Bucket * Search(CloseHash *h, const Member *x);
int Add(CloseHash *h,const Member *x);
int Remove(CloseHash *h,const Member *x);
void Dump(CloseHash *h);
void Terminate(CloseHash *h);

int main(void){

    return 0;
}