// bubble sort구현. 교환과정을 상세하게 출력하면서 버블정렬하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define __MAX__ 10
#define swap(x,y) do{ int t; t=x; x=y; y=t;}while(0);

int COMPARE;
int SWAP;
// 작은수를 앞에다 배열하는 버블정렬
void bubble_sort(int a[], int size){
    for(int i=0; i<size; i++){  //0 1 2 3 4
        for(int j=size-1; j>i; j--){    //4 3 2 1
            printf("%d ");
            if (a[j-1] > a[j]){
                swap(a[j-1],a[j]);
                printf("*");
            }else{
                printf("-");
            }
            printf(" ");
        }
    }
}
void array_print(int a[], int max, int key, int flag){
    if(flag == 0){
        for(int i=0; i<max; i++){
            printf("%3d ",a[i]);
            if(i==key){
                printf("-");
            }
        }
    }else{
        for(int i=0; i<max; i++){
            printf("%3d ",a[i]);
            if(i==key){
                printf("*");
            }
        }
    }

}
void bubble_sort2(int a[], int n){
    int i,j;
    for(i=0; i<n-1; i++){   //0 1 2 3 4
        printf("PASS %d : \n",i+1);
        
        for(j=0; j<n-1-i; j++){    // 0 1 2 3 4
            if ( a[j] > a[j+1]){
                SWAP++;
                swap(a[j],a[j+1]);
                array_print(a,n,j,1);
            }else{
                array_print(a,n,j,0);
            }
            COMPARE++;
            printf("\n");
        }
        
        printf("\n");
    }
}
int main(void){
    int *a;
    a = (int*)malloc(__MAX__*sizeof(int));

    srand(time(NULL));
    printf("Before bubble sort : \t");
    for(int i=0; i<__MAX__; i++){
        a[i] = 1 + rand() % 200;
        printf("%d ", a[i]);
    }
    putchar('\n');

    bubble_sort2(a,__MAX__);

    printf("\nAfter Bubble sort : \t");
    for(int i=0; i<__MAX__; i++){
        printf("%d ", a[i]);
    }
    printf("\n\n비교를 %d회 했습니다\n", COMPARE);
    printf("교환을 %d회 했습니다\n", SWAP); 
    putchar('\n');
    free(a);
    return 0;
}