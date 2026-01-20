// 선형 검색(보초법)
#include <stdio.h>
#include <stdlib.h>

int search(int a[],int n,int key){
    char tap='\t';
    char dash[] = "---";
    printf("   |");
    for(int i=0; i<n ; i++){
        printf("%2d ", i);
    }
    printf("\n---|");
    for (int i=0; i<n ;i++){
        printf("%s",dash);
    }
    putchar('\n');
    for(int i=0; i<n;i++){
        printf("   |");
        for(int j=0; j<i; j++)putchar(tap);
        printf("*");
        printf("\n%d  |", i);
        for(int j=0;j<n;j++){
            printf("%2d ",a[j]);
        }
        putchar('\n');
        
        if(a[i]==key){
            return i;
        }
    }
    return -1;
}
int main(void){
    int i,nx,ky,idx;
    int *x;

    puts("선형 검색(보초법)");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for(i=0; i<nx ; i++){
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("검색값 : ");
    scanf("%d", &ky);
    idx = search(x,nx,ky);
    if(idx == -1){
        puts("\n검색에 실패했습니다.");
    }else{
        printf("\n%d는 x[%d]에 있습니다.\n", ky, idx);
    }
    free(x);

    return 0;
}