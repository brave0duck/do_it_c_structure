// ex-q4.c 버블정렬버전 ver2버전을 교환,비교과정을 출력하는 프로그램으로 개선

#include <stdio.h>
#include <stdlib.h>
#define swap(type,x,y) do{ type t=x; x=y; y=t;}while(0)
int SWAP_COUNTER;
int COMPARE_COUNTER;

void arr_print(int a[], int max, int key, int flag){
    if(flag == 0){
        for(int i=0; i<max; i++){
            printf("%d",a[i]);
            if(i==key){
                printf(" - ");
            }else{
                printf("   ");
            }
        }
    }else{  // IF FLAG == 1
        for(int i=0; i<max; i++){
            printf("%d",a[i]);
            if(i==key){
                printf(" * ");
            }else{
                printf("   ");
            }
        }
    }
}
void bubble(int a[], int n){
    int i,j;
    int exchange;   //정렬되었는가를 체크하는 변수. 교환이 없으면 정렬 완성된것
    for(i=0; i<n-1; i++){
        exchange=0; //0으로 초기화
        printf("================================\n");
        printf("PASS %d : ",i+1);
        arr_print(a,n,-1,0);
        printf("\n================================\n");
        
        for(j=n-1; j>i; j--){
            if (a[j-1] > a[j]){
                swap(int,a[j-1],a[j]);
                SWAP_COUNTER++;     //스왑횟수저장 전역변수
                exchange++;         //정렬체크변수
                arr_print(a,n,j-1,1);
            }else{
                arr_print(a,n,j-1,0);
            }
            COMPARE_COUNTER++;      //비교횟수저장 전역변수
            printf("\n");
        }
        if(exchange == 0){  //한번도 교환이 없었나? (모두 정렬된 상태인가?)
            break;          // 그럼 아웃
        }
        printf("\n");
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
    printf("%d번을 비교하고 , %d번을 스왑했습니다.",COMPARE_COUNTER,SWAP_COUNTER);

    free(x);
    
    return 0;
}
