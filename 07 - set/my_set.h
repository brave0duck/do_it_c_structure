#ifndef __MYSET__
#define __MYSET__

typedef struct{
    int max;
    int num;
    int * pSet;
}IntSet;

int Initialize(IntSet *s, int max);

