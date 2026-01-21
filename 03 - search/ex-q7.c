// seqsearch()함수 작성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _MAX_ 20

int comp_asc(const void *x, const void *y){
    int a = *(const int*)x;
    int b = *(const int*)y;
    if(a>b) return 1;
    if(a<b) return -1;
    return 0;
}
void * seqsearch(const void* key, const void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void *)){
    int *p_key = (int *)key;
    int *p_base = (int *)base;

    for(int i=0; i< nmemb; i++){
        if (p_base[i] == *p_key){
            return (void*)(p_base + i);
        }
    }
    return NULL;
}
int main(void){
    int number,yesno;    int *x;    int * ps;
    srand(time(NULL));

    x = (int*)calloc(_MAX_,sizeof(int));
    for(int i=0; i<_MAX_; i++){
        x[i] = rand()%1000;
    }
    qsort(x,_MAX_,sizeof(int),comp_asc);

    do{
        printf("what's number searching for? : ");
        scanf("%d", &number);

        ps = seqsearch(&number, x, _MAX_, sizeof(int), comp_asc);

        if(ps){
            printf("find! %d is x[%d]\n", *ps, (int)(ps - x));
        }else{
            printf("Cannot find. \n");
            for(int i=0; i<_MAX_; i++)printf("%d ", x[i]);
        }
        printf("\nContinue? (1:yes , 0:no) ");
        scanf("%d", &yesno);
    }while(yesno ==1 );
    
    free(x);
    return 0;
}