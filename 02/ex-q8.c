// 배열 b를 배열 a에 복사하는 함수를 작성하세요
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// strcpy() 구현
void array_copy(int a[], const int b[], int n){
    for(int i=0; i<n; i++){
        a[i] = b[i];
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

    array_copy(pcopy, src, n);

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

