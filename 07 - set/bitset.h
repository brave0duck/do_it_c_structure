#ifndef ___BITSET
#define ___BITSET

typedef unsigned long BitSet;

#define BitSetNull  (BitSet)0
#define BitSetBits  32
#define SetOf(no)    ((BitSet)1<<(no))

// check member
int IsMember(BitSet s, int n);
// add member
void Add(BitSet *s,int n);
// remove member
void Remove(BitSet *s, int n);
// size
int Size(BitSet s);
//print
void Print(BitSet s);
// print line
void Println(BitSet s);
// 합집합
BitSet* Union(BitSet *bResult,const BitSet *b1, const BitSet *b2);
// 교집합
BitSet*  Intersection(BitSet *bResult, const BitSet *b1, const BitSet *b2);
// 차집합
BitSet*  Difference(BitSet * bResult, const BitSet *b1, const BitSet *b2);
// 대칭차집합
BitSet* Symmetric_Difference(BitSet * bResult, const BitSet * b1, const BitSet * b2);

#endif