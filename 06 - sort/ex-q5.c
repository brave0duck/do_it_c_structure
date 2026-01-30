//버블정렬 ver3. 스왑한 부분을 저장해서 다음 비교때 거기부터 시작하도록한다.
// k변수는 마지막 스왑한 위치를 저장. 더이상 스왑이 없었다는건? 정렬이 이미 되어있다는것. 그러니 다음 비교는 그자리부터 시작
// 1    3   4   9   6   7   8
// |<-  k ->|
// ex-q5.c -> 이것을 비교,교환과정을 자세히 출력하는 프로그램으로 

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
    printf("\n");
}
void bubble3(int a[], int n){
    int pass_counter=0;
    int k=0;
    while(k < n-1){
        int j;
        int last = n-1;
        
        printf("================================\n");
        printf("%d 단계 : ",pass_counter++);
        arr_print(a,n,-1,0);
        printf("================================\n");

        for(j=n-1; j>k;j--){
            if(a[j-1] > a[j]){
                swap(int,a[j-1],a[j]);
                last = j;
                arr_print(a,n,j-1,1);
                SWAP_COUNTER++;
            }else{
                arr_print(a,n,j-1,0);
            }
            COMPARE_COUNTER++;
        }
        k = last;
    }
}
int main(void){
    int i;
    int nx=7;
    int x[7]={1,3,9,4,7,8,6};

    bubble3(x,nx);

    puts("오름차순으로 정렬했습니다.");
    for(i=0; i<nx ; i++){
        printf("x[%d] = %d\n",i,x[i]);
    }
    printf("%d번을 비교하고 , %d번을 스왑했습니다.",COMPARE_COUNTER,SWAP_COUNTER);
    return 0;
}