// 배열a에서 key값을 찾아 그 인덱스를 배열에 차곡차곡 저장하고 찾는갯수를 리턴하는 함수 작성
// ex) a={1,9,2,9,4,6,7,9} -----> idx = {1,3,7} return 3;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int search_idx(const int a[], int n, int key, int idx[]){
    int ncount=0;
    for(int i=0; i<n; i++){
        if(a[i] == key){
            idx[ncount++] = i;
        }
    }
    if (ncount == 0){
        return -1;
    }else{
        return ncount;
    }
}
int main(void){
    int i,n,key,idx;
    int *x, *index;
    srand(time(NULL));

    puts("정수배열을 만듭니다");
    printf("요소 개수 : ");
    scanf("%d", &n);
    x = (int *)calloc(n, sizeof(int));
    index = (int *)calloc(n, sizeof(int));

    for(i=0; i<n ; i++){
        x[i] = 1+ rand()%10;
    }

    printf("검색값 (1~10) : ");
    scanf("%d", &key);
    idx = search_idx(x,n,key,index);
    if(idx == -1){
        puts("검색에 실패했습니다.");
    }
    for(int i=0; i<n; i++){
        printf("%d  ",x[i]);
    }
    
    printf("\n같은값 %d개 : idx",idx);
    for(int j=0; j<idx; j++){
        printf("[%d] ", index[j]);
    }
    printf("\n\n");

    free(x);
    free(index);
    return 0;
}