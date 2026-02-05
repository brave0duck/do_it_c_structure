//비트 벡터 집합 여러가지 연산구현
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bitset.h"

// check member. yes=1, no=0
int IsMember(BitSet s, int n)
{
    return s & SetOf(n);
}
// add member
void Add(BitSet *s,int n){
    *s |= SetOf(n);
}
// remove member
void Remove(BitSet *s, int n){
    *s &= ~SetOf(n);
}
// size
int Size(BitSet s){
    int n=0;
    while(s != BitSetNull){ // 1을 0으로 하나하나 카운팅을 한다
        s &= s-1;   // s와 s-1을 논리곱하면 그 자리 숫자는 0이 된다
        n++;        // 1을 0으로 바꿨으므로 카운팅+1
    }
    return n;
}
//print
void Print(BitSet s){
    for(int i=0; i<BitSetBits; i++){
        if(IsMember(s,i)){
            printf("%d ",i);
        }
    }
}
// print line
void Println(BitSet s){
    Print(s);
    putchar('\n');
}
// 합집합
BitSet* Union(BitSet *bResult,const BitSet *b1, const BitSet *b2){
    *bResult = *b1 | *b2;
    return bResult;
}
// 교집합
BitSet* Intersection(BitSet *bResult, const BitSet *b1, const BitSet *b2){
    *bResult = *b1 & *b2;
    return bResult;
}
// 차집합
BitSet* Difference(BitSet * bResult, const BitSet *b1, const BitSet *b2){
    *bResult = *b1 & ~*b2;
    return bResult;
}
// 대칭 차집합 : (A 합집합 B) - (A 교집합 B)
BitSet* Symmetric_Difference(BitSet * bResult, const BitSet * b1, const BitSet * b2){
    BitSet bUni; BitSet bInter;
    Union(&bUni,b1,b2);
    Intersection(&bInter,b1,b2);
    *bResult = bUni & ~bInter;
    return bResult;
}
int main(void){
    srand(time(NULL));
    int random;
    BitSet b1=0;
    BitSet b2=0;
    BitSet bResult=0;

    BitSet* bSym=0;

    // random assignment
    for(int i=0; i<5; i++){
        random = rand() % 33;
        if(!IsMember(b1, random)){
            Add(&b1,random);
        }
    }
    for(int i=0; i<5; i++){
        random = rand() % 33;
        if(!IsMember(b2, random)){
            Add(&b2,random);
        }
    }
    printf("random data : \n");
    Print(b1);putchar('\n');
    Print(b2);putchar('\n');

    Union(&bResult,&b1,&b2);
    printf("Union : ");
    Print(bResult);putchar('\n');

    Intersection(&bResult,&b1,&b2);
    printf("Intersection : ");
    Print(bResult);putchar('\n');

    Difference(&bResult,&b1,&b2);
    printf("Difference : ");
    Print(bResult);putchar('\n');

    printf("대칭 차집합은 : ");
    bSym = Symmetric_Difference(&bResult,&b1,&b2);
    Print(*bSym); putchar('\n');

    return 0;
}