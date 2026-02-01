// 퀵소트 원리. 특정값x를 기준으로 왼쪽엔 x보다 작은값, 오른쪽엔 x보다 큰값이 오도록 조정
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

void my_quick_sort(int a[], int n){
   int x = a[n/2];
   int pl = 0;
   int pr = n-1;

   printf("\nx = %d\n",x);
   while(pl <= pr){
    while(a[pl] < x) pl++;
    while(a[pr] > x) pr--;
    if(pl <= pr){
        swap(int,a[pl],a[pr]);
        pl++;
        pr--;
    }

   }
   printf("피벗의 값은 %d입니다.\n",x);
   printf("피벗이하의 그룹\n");
   for(int i=0; i<pl-1; i++){
    printf("%d ",a[i]);
   }
   putchar('\n');
   if(pl > pr+1){
    printf("피벗과 일치하는 그룹\n");
    for(int i=pr+1; i<=pl-1 ; i++){
        printf("%d ",a[i]);
    }

    putchar('\n');
    printf("피벗이상의 그룹\n");
        for(int i=pr+1; i<n ; i++){
        printf("%d ",a[i]);
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

    printf("\n\nAfter : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    
    free(x);
    return 0;
}