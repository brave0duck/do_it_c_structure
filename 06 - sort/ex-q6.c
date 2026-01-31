// ex-q6.c  
// 양방향 정렬(bidirection bubble sort) 구현
// [0] [1] [2] [3] [4] [5] [6]   
//  1   3   9   4   7   8   6
// 홀수번째는 ----> 진행. 제일 큰수를 맨 오른쪽에 저장 (그리고 오른쪽끝은 검색에서 제외)
// 짝수번째는 <---- 진행. 제일 작은수를 맨 왼쪽에 저장 (그리고 왼쪽끝은 검색에서 제외)
// 이런식으로 저장하면서 배열의 양쪽끝을 채워나간다


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FORWARD 1
#define BACKWARD 2
#define MAXIMUM 100

#define swap(type,x,y) do{ type t=x; x=y; y=t;}while(0)

typedef int INT;
INT SWAP_COUNTER;
INT COMP_COUNTER;

// 완전정렬여부 리턴 pass함수(배열, 시작, 끝,방향)
int pass(int a[], int x, int y, int direction){
    int flag=0; // 완전 정렬상태인가 체크변수.교환을 안하면 0유지
    
    if(direction == FORWARD){
        for(int i=x; i<y ; i++){
            if(a[i] > a[i+1]){
                swap(int,a[i],a[i+1]);
                SWAP_COUNTER++;
                flag++;
            }
            COMP_COUNTER++;
        }
    }else if(direction == BACKWARD){
        for(int i=y; i>x ; i--){
            if(a[i-1] > a[i]){
                swap(int,a[i-1],a[i]);
                SWAP_COUNTER++;
                flag++;
            }
            COMP_COUNTER++;
        }
    }
    if(flag == 0){
        return 0;
    }
    return 1;
}
//홀짝 돌아가면서
void bid_bubble(int a[], int n){
    int first=0;
    int last = n-1;
    int nCount=0;   //홀짝용변수
    while( first<last ){
        if (nCount%2 == 0){
            if(pass(a,first,last,FORWARD) == 0){    // 정방향( 큰수를 오른쪽으로 )
                break;  // 스왑이 없었으면 정렬상태다. 종료
            }
            last--; // 오른쪽 -1
        }else{
            if(pass(a,first,last,BACKWARD) == 0){   // 역방향( 작은수를 왼쪽으로)
                break;
            }
            first++;    // 왼쪽+1
        }
        nCount++;
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

    bid_bubble(x,MAXIMUM);

    printf("After : \t");
    for(int i=0; i<MAXIMUM ; i++){
        printf("%d ",x[i]);
    }
    printf("\n%d번 비교했습니다. %d스왑했습니다",COMP_COUNTER,SWAP_COUNTER);
    free(x);
    return 0;
}