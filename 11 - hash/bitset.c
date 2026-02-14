//비트 벡터 집합 여러가지 연산구현
#include "bitset.h"

// check member. yes=1, no=0
int IsMember_Bit(BitSet s, int n)
{
    return s & SetOf(n);
}
// add member
void Add_Bit(BitSet *s,int n){
    *s |= SetOf(n);
}
// remove member
void Remove_Bit(BitSet *s, int n){
    *s &= ~SetOf(n);
}
// size bitset
int Size_Bit(BitSet s){
    int n=0;
    while(s != BitSetNull){ // 1을 0으로 하나하나 카운팅을 한다
        s &= s-1;   // s와 s-1을 논리곱하면 그 자리 숫자는 0이 된다
        n++;        // 1을 0으로 바꿨으므로 카운팅+1
    }
    return n;
}
//print
void Print_Bit(BitSet s){
    for(int i=0; i<BitSetBits; i++){
        if(IsMember(s,i)){
            printf("%d ",i);
        }
    }
}
// print line
void Println_Bit(BitSet s){
    Print(s);
    putchar('\n');
}
// 합집합
BitSet* Union_Bit(BitSet *bResult,const BitSet *b1, const BitSet *b2){
    *bResult = *b1 | *b2;
    return bResult;
}
// 교집합
BitSet* Intersection_Bit(BitSet *bResult, const BitSet *b1, const BitSet *b2){
    *bResult = *b1 & *b2;
    return bResult;
}
// 차집합
BitSet* Difference_Bit(BitSet * bResult, const BitSet *b1, const BitSet *b2){
    *bResult = *b1 & ~*b2;
    return bResult;
}
// 대칭 차집합 : (A 합집합 B) - (A 교집합 B)
BitSet* Symmetric_Difference_Bit(BitSet * bResult, const BitSet * b1, const BitSet * b2){
    BitSet bUni; BitSet bInter;
    Union(&bUni,b1,b2);
    Intersection(&bInter,b1,b2);
    *bResult = bUni & ~bInter;
    return bResult;
}