// 양방향 스택 구현
#ifndef __Q2STACK__
#define __Q2STACK__

typedef struct st{
    int ptr;
    int storage;
} stack;

typedef struct{
    int max;
    stack a;
    stack b;
    int *pStack;   // array pointer, stk
}DStack;


// stack 초기화
int Init(DStack *s, int max);
// 푸쉬
int Push(DStack *s, int type, int x);
// 팝
int Pop(DStack *s, int type, int *x);
// 스택에서 데이터를 피크(엿보기)
int Peek(const DStack *s, int type, int *x);
// 스택 비우기
void Clear(DStack *s, int type);
// 스택의 최대용량
int Capacity(const DStack *s, int type);
// 스택의 데이터갯수
int Size(const DStack *s, int type);
// 비어있나?
int IsEmpty(const DStack *s, int type);
// 가득찼나?
int IsFull(const DStack *s, int type);
// 검색
int Search(const DStack *s, int type, int x);
// 모든 데이터 출력
void Print(const DStack *s, int type);
// 스택 종료
void Terminate(DStack *s);

#endif