#ifndef __RING_BUFFER__
#define __RING_BUFFER__

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int *que;
}RingQueue;

int Initialize(RingQueue *q, int max);
int Enque(RingQueue *q, int x);
int Deque(RingQueue *q, int *x);
int Peek(const RingQueue *q,int *x);
void Clear(RingQueue *q);
int Capacity(const RingQueue *q);
int Size(const RingQueue *q);
int IsEmpty(const RingQueue *q);
int IsFull(const RingQueue *q);
int Search(const RingQueue *q, int x);
void Print(const RingQueue *q);
void Terminate(RingQueue *q);

#endif