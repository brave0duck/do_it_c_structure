// 배열 b의 모든 요소를 배열 a에 '역순'으로 복사하는 함수를 작성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//strcpy reverse version
void array_rcopy(int a[], const int b[], int n){
    for(int i=0; i<n; i++){
        a[i] = b[n-i-1];
    }
}
int main(void){
    int input;
    int src[10];
    int n = sizeof(src)/sizeof(int);
    int * pcopy;

    srand(time(NULL));
    for(int i=0; i<10; i++){
        src[i] = 1 + rand()%100;
    }
    pcopy = (int*)calloc(n,sizeof(int));

    array_rcopy(pcopy, src, n);

    printf("Src : ");
    for(int i=0; i<n ; i++){
        printf("%d  ",src[i]);
    }
    putchar('\n');

    printf("Cpy : ");
    for(int i=0; i<n ; i++){
        printf("%d  ",pcopy[i]);
    }
    putchar('\n');

    free(pcopy);
    return 0;
}

