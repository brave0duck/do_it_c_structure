#ifndef ___INTSTACK
#define ___INTSTACK

typedef struct{
    int max;    // max elemets
    int now;    // stack pos , ptr
    int *pStack;   // array pointer, stk
}IntStack;

// stack 초기화
int InitStack(IntStack *s, int max);
// 푸쉬
int Push(IntStack *s, int x);
// 팝
int Pop(IntStack *s, int *x);
// 스택에서 데이터를 피크(엿보기)
int Peek(const IntStack *s, int *x);
// 스택 비우기
void Clear(IntStack *s);
// 스택의 최대용량
int Capacity(const IntStack *s);
// 스택의 데이터갯수
int Size(const IntStack *s);
// 비어있나?
int IsEmpty(const IntStack *s);
// 가득찼나?
int IsFull(const IntStack *s);
// 검색
int Search(const IntStack *s, int x);
// 모든 데이터 출력
void Print(const IntStack *s);
// 스택 종료
void Terminate(IntStack *s);

#endif