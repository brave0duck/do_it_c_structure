#ifndef __EXQ3__
#define __EXQ3__

typedef struct{
    int max;    // max node
    int num;    // now node
    int *que;   // array pointer
}ArrayIntQueue;

int Initialize(ArrayIntQueue *q, int max);
int Enque(ArrayIntQueue *q, int x);
int Deque(ArrayIntQueue *q, int *x);
int Peek(const ArrayIntQueue *q, int *x);
void Clear(ArrayIntQueue *q);
int Capacity(cost ArrayIntQueue *q);
int Size(const ArrayIntQueue *q);
int IsEmpty(const ArrayIntQueue *q);
int IsFull(const ArrayIntQueue *q);
int Search(const ArrayIntQueue *q);
void Print(const ArrayIntQueue *q);
void Terminate(ArrayIntQueue *q);

#endif