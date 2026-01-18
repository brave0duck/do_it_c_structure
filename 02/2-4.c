#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *a;
    int count;

    printf("요소 개수 : ");
    scanf("%d", &count);

    a = calloc(count,sizeof(int));

    if(a == NULL){
        puts("fail to memory allocation.");
    }else{
        printf("input %d integer numbers.\n", count);
        for(int i=0; i<count; i++){
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        }
        printf("result is : \n");
        for(int i=0; i<count ; i++){
            printf("a[%d] : %d\n", i, a[i]);
        }
        free(a);
        printf("free memory allocation(%p)",a);
    }
    return 0;
}