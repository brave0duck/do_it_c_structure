// 배열a의 모든 요소의 순서를 뒤섞는 shuffle함수를 작성. n은 요소의 개수
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _SHUFFLE_MAX_ 150

void shuffle(int a[], int n){
    srand(time(NULL));
    for(int i=0; i<_SHUFFLE_MAX_ ; i++){
        int key = rand()%n;
        int temp = a[0];
        a[0] = a[key];
        a[key] = temp;
    }
}
int main(void){
    
    int src[10];
    int n = 10;
    
    srand(time(NULL));
    for(int i=0; i<10; i++){
        src[i] = 1 + rand()%1000;
    }

    printf("before : ");
    for(int i=0; i<n ; i++){
        printf("%d  ",src[i]);
    }
    putchar('\n');

    shuffle(src, n);

    printf("after  : ");
    for(int i=0; i<n ; i++){
        printf("%d  ",src[i]);
    }
    putchar('\n');

    return 0;
}

