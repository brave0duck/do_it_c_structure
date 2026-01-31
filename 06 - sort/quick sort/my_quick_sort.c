// 퀵소트 간이구현. 특정값x를 기준으로 왼쪽엔 x보다 작은값, 오른쪽엔 x보다 큰값이 오도록 조정
// 기준값 x 지정 = 2/n
// pl = 0, pr = n-1
// pl 0부터 n-1까지 증가하면서 x보다 큰값을 찾는다, 
// pr n-1부터 0Rkwl 감소하면서 x보다 작은값을 찾는다
// 찾으면 둘을 서로 스왑한다. 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM 10
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

int SWAP;
int COMP;

void my_quick_sort(int a[], int n){
   int x = n/2;
   int pl = 0;
   int pr = n-1;

   printf("\nx = %d\n",x);
   while(pl <= pr){
    
    while(a[pl] > a[x]) pl++;
    while(a[pr] < a[x]) pr--;

    if(pl <= pr){
        swap(int,a[pl],a[pr]);
        pl++;
        pr--;
    }
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

    my_quick_sort(x,MAXIMUM);

    printf("After : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    printf("\n%d번 비교. %d번 스왑", SWAP,COMP);
    free(x);
    return 0;
}