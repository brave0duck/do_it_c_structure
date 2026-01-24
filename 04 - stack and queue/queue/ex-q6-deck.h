#ifndef __DECK_QUE__
#define __DECK_QUE__
#define FORWARD 1
#define REVERSE 2

typedef struct{
    int ptr;
    int num;
}Deck;

typedef struct {
    int max;
    Deck a;
    Deck b;
    int *que;
}DeckQue;

int InitQue(DeckQue *q, int max);
int Enque(DeckQue *q, int type, int x);
int Deque(DeckQue *q, int type, int *x);
int Peek(const DeckQue *q,int type,int *x);
void Clear(DeckQue *q);
int Capacity(const DeckQue *q);
int Size(const DeckQue *q, int type);
int IsEmpty(const DeckQue *q);
int IsFull(const DeckQue *q);
int Search(const DeckQue *q,int x);
void Print(const DeckQue *q);
void Terminate(DeckQue *q);

#endif