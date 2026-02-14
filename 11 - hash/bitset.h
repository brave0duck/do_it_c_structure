#ifndef ___BITSET
#define ___BITSET

typedef unsigned long BitSet;

#define BitSetNull  (BitSet)0
#define BitSetBits  32
#define SetOf(no)    ((BitSet)1<<(no))

// check member
int IsMember_Bit(BitSet s, int n);
// add member
void Add_Bit(BitSet *s,int n);
// remove member
void Remove_Bit(BitSet *s, int n);
// size
int Size_Bit(BitSet s);
//print
void Print_Bit(BitSet s);
// print line
void Println_Bit(BitSet s);
// 합집합
BitSet* Union_Bit(BitSet *bResult,const BitSet *b1, const BitSet *b2);
// 교집합
BitSet*  Intersection_Bit(BitSet *bResult, const BitSet *b1, const BitSet *b2);
// 차집합
BitSet*  Difference_Bit(BitSet * bResult, const BitSet *b1, const BitSet *b2);
// 대칭차집합
BitSet* Symmetric_Difference_Bit(BitSet * bResult, const BitSet * b1, const BitSet * b2);

#endif