// 배열요소를 역순으로 정렬
#include <stdio.h>
#include <stdlib.h>

#define swap(type,x,y) do{ type t=x; x=y; y=t;}while(0)

void array_reverse(int a[], int n){
    for(int i=0; i < n/2; i++){
        swap(int,a[i],a[n-i-1]);
    }
}
int main(void){
    int i;
    int *pArray;
    int nCount;

    // input count numbers and memory allocation
    printf("요소 개수 : ");
    scanf("%d", &nCount);
    pArray = (int *)calloc(nCount, sizeof(int));

    // data input one by one
    printf("%d개의 정수를 입력하세요.\n", nCount);
    for(i=0; i<nCount ; i++){
        printf("pArray[%d] : ", i);
        scanf("%d", &pArray[i]);
    }
    // call function reverse
    array_reverse(pArray,nCount);

    // print result
    printf("배열을 역순으로 정렬했습니다.\n");
    for(i=0; i<nCount; i++){
        printf("pArray[%d] : %d\n", i, pArray[i]);
    }

    // free alloc
    free(pArray);

    return 0;
}