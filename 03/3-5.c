// c언어 표준라이브러리 함수 bsearch함수를 사용해 오름차순으로 정렬된 배열을 검색합니다
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int int_cmp(const int *a, const int *b){
    if(*a < *b){
        return -1;
    }else if(*a > *b){
        return 1;
    }else{
        return 0;
    }
}
int main(void){
    int nx,ky;
    int *x, *p;
    srand(time(NULL));
    
    puts("c표준라이브러리 bsearch()함수를 사용하여 검색");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx,sizeof(int));

    for(int i=0; i<nx; i++){
        x[i] = i*5 + rand()%5;
    }

    printf("검색값 : ");
    scanf("%d", &ky);
    p = bsearch(&ky,x,nx,sizeof(int),(int(*)(const void *, const void *)) int_cmp);

    for(int i=0; i<nx; i++){
        printf("%d ", x[i]);
    }
    putchar('\n');
    if(p == NULL){
        puts("검색에 실패했습니다.");
    }else{
        printf("%d는 x[%d]에 있습니다.\n",ky,p-x);
    }
    free(x);
    return 0;
}