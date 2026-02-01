// quick sort는 요소의 개수가 적은 배열에 대해서는 처리가 빠르다. 
// 그룹의 요소가 9개 이하면 단순삽입정렬로 동작하는 함수로 수정

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM 30
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

void insertion(int a[],int start, int end){
    int i,j;
    
    for(i=start+1; i<=end ; i++){
        int tmp = a[i];
        for(j=i; j>0 && a[j-1]>tmp ; j--){
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }
}
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

    if(left < pr && (pr-left) > 9){ // if over 9 -> quick , not ->insertion
        quick(a,left,pr);
    }else{
        insertion(a,left,pr);
    }

    if(pl < right && (right-pl) > 9){
        quick(a,pl,right);
    }else{
        insertion(a,pl,right);
    }
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

    quick(x,0,MAXIMUM-1);

    printf("\n\nAfter : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    
    free(x);
    return 0;
}