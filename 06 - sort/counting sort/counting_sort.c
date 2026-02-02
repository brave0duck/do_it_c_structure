/** 도수정렬 counting sort
 * 
 * <4단계 로직>
 * 1. 원본배열 a와 같은 크기의 f배열을 만들어 a배열을 순회. 순회하면서 a[i]값에 해당하는 f배열 인덱스에 +1을 한다 (도수분포 만들기)
 * 2. f배열을 순회하며 각 인덱스의 증가분을 누적해서 기록 (도수누적분포도 만들기)
 * 3. 목적배열 b배열을 만든다. 
 *  3-1. a배열 마지막부터 첫번째까지 반복
 *  3-2. a배열의 값에 해당하는 f배열 인덱스를 찾는다. 그 배열의 값(누적용량)에 -1을 한후 a배열의 값을 b배열 인덱스에 저장
 * 4. b배열을 a배열에 복사한다
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void counting_sort(int a[], int nsize, int max_value){
    int * f = (int *)calloc(nsize,sizeof(int));
    int * b = (int *)calloc(nsize,sizeof(int)); //3

    for(int i=0; i<nsize ; i++){     //1
        f[a[i]]++;
    }
    for(int i=1; i<nsize ; i++){     //2
        f[i] = f[i] + f[i-1];
    }
    for(int i= nsize-1; i>=0; i--){  // 3-1
        b[--f[a[i]]] = a[i];        // 3-2
    }
    for(int i=0; i<nsize;i++){      // 4
        a[i] = b[i];
    }

    free(b);
    free(f);
    
}
int main(void){
    srand(time(NULL));
    int *x;

    x =(int*)malloc(MAX*sizeof(int));

    printf("Original : \t");
    for(int i=0; i<MAX; i++){
        x[i] = rand()% 10;
        printf("%d ",x[i]);
    }
    printf("\n");

    counting_sort(x,MAX,MAX);

    printf("\nAfter : \t");
    for(int i=0; i<MAX ; i++){
        printf("%d ",x[i]);
    }
    printf("\n");

    free(x);
    return 0;
}