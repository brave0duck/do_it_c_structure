// shell sort
// 삽입정렬과 비슷하나 배열을 나누어서 처리한다는 차이점.
// 1. 배열을 반으로 나눠 간격으로 사용(h=4) h는 계속 h/2씩 반복해서 1이 될때까지
// 2. 0부터 간격값과 비교. ex) 0-4비교, 1-5 비교, 2-6 비교, 3-7비교 ...
// 3. 간격값을 4에서 2로 조정 - ex) 0-2-4-6비교,  1-3-5-7비교
// 4. 2반복
// 5  간격을 2에서 1로 조정 ex) 0-1-2-3-4-5-6-7비교
// 6  2반복

// 셸소트 = 삽입정렬에서 비교대상이 정렬상태이면 비교가 줄어들어 속도가 빨라진다는데 착안한 알고리즘

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM 100
#define swap(type,x,y) do{type t=x; x=y; y=t;}while(0)

int SWAP;
int COMP;

// [0] [1] [2] [3] [4] [5] [6] [7]
//  8   1   4   2   7   6   3   5
// h=간격
void shellsort(int a[], int n){
    int i,j,h;
    for(h=n/2 ; h>0 ; h/=2){    //h=4
        for(i=h; i<n ; i++){    //i=4 5 6 7 8
            int tmp = a[i];     //tmp = 7
            for(j=i-h; j>=0 && a[j]>tmp ; j -= h){  //j=0   j= j-h
                a[j+h] = a[j];
                SWAP++;
                COMP++;
            }
            a[j+h] = tmp;
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

    shellsort(x,MAXIMUM);

    printf("After : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    printf("\n%d번 비교. %d번 스왑", SWAP,COMP);
    free(x);
    return 0;
}