// quick sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM 10
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

void quick(int a[], int left, int right){
    int pl = left;
    int pr = right;
    int x = a[(pl+pr)/2];

    do{
        while(a[pl] < x)    pl++;
        while(a[pr] > x)    pr--;
        if(pl <= pr){
            swap(int, a[pl],a[pr]);
            pl++;
            pr--;
        }
    }while(pl <= pr);

    if(left < pr)   quick(a,left,pr);
    if(pl < right)   quick(a,pl,right);
}
void quick_sort(int a[], int n){
    quick(a,0,n-1);
}
int main(void){
    srand(time(NULL));
    int *x;

    x =(int*)malloc(MAXIMUM*sizeof(int));

    printf("Original : \t");
    for(int i=0; i<MAXIMUM; i++){
        x[i] = 1+ rand()% 1999;
        printf("%d ",x[i]);
    }
    printf("\n");

    quick_sort(x,MAXIMUM);

    printf("\n\nAfter : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    
    free(x);
    return 0;
}