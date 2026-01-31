// selection sort  재귀로 구현해봄. 비교횟수는 셀렉션소트나 버블소트나 비슷하나 스왑횟수가 현저히 작다는것이 특징
// 최고값을 오른쪽으로 보내고 재귀함수호출
// 혹은 최소값을 왼쪽으로 보내고 재귀함수호출
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXIMUM 100
#define swap(type,x,y) do{ type t=x; x=y; y=t;}while(0)

typedef int INT;
INT SWAP_COUNTER;
INT COMP_COUNTER;

int selection_bubble(int a[], int n){
    if(n <= 0){
        return 0;
    }
    int max=0;// 최고값 저장용
    for(int i=1; i<=n-1; i++){
        if( a[i] > a[max]){
            max = i;
        }
        COMP_COUNTER++;
    }
    swap(int,a[max],a[n-1]); // 최고값을 맨 오른쪽에 보냄
    SWAP_COUNTER++;
        
    return selection_bubble(a, n-1); // 재귀
}
int selection_bubble2(int a[], int n){
    if(n <= 0){
        return 0;
    }
    int min=0;// 최소값 저장용
    for(int i=1; i<n; i++){
        if( a[i] < a[min]){
            min = i;
        }
        COMP_COUNTER++;
    }
    swap(int,a[min],a[0]); // 최소값을 맨 왼쪽에 보냄
    SWAP_COUNTER++;
        
    return selection_bubble2(a+1, n-1); // 재귀
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

    selection_bubble2(x,MAXIMUM);

    printf("After : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    printf("\n%d번 비교했습니다. %d스왑했습니다",COMP_COUNTER,SWAP_COUNTER);
    free(x);
    return 0;
}