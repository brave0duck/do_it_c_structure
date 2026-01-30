//버블정렬 ver2. => 만약 한번도 교환을 하지않으면 모두 정렬되었다는 뜻이므로 break로 나온다
#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{ type t=x; x=y; y=t;}while(0)

void bubble(int a[], int n){
    int i,j;
    int exchange;   //교환횟수 체크 변수
    for(i=0; i<n-1; i++){
        exchange=0; //0으로 초기화
        for(j=n-1; j>i; j--){
            if (a[j-1] > a[j]){
                swap(int,a[j-1],a[j]);
                exchange++;
            }
        }
        if(exchange == 0){  //한번도 교환이 없었나? (모두 정렬된 상태인가?)
            break;          // 그럼 아웃
        }
    }
}
int main(void){
    int i,nx;
    int *x;

    puts("버블 정렬");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = (int *)calloc(nx,sizeof(int));

    for(i=0; i<nx; i++){
        printf("x[%d] : ",i);
        scanf("%d", &x[i]);
    }
    bubble(x,nx);

    puts("오름차순으로 정렬했습니다.");
    for(i=0; i<nx ; i++){
        printf("x[%d] = %d\n",i,x[i]);
    }
    free(x);
    
    return 0;
}