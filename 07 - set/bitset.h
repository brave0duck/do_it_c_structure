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
void Print(BitSet s);

#endif