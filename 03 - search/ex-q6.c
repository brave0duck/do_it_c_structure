// 요소의 값이 내림차순으로 정렬된 long배열에서 검색을 bsearch함수를 사용하여 프로그램 작성
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 내림차순 함수. 10 9 8 7 6 5 ...
int long_compare_desc(const void *x, const void *y){
    long a = *(const long *)x;
    long b = *(const long *)y;
    if(a>b) return -1;
    if(a<b) return 1;
    return 0;
    
}
// 오름차순 함수. 1 2 3 4 5 ...
int long_compare_asce(const void *x, const void *y){
    long a = *(const long *)x;
    long b = *(const long *)y;
    if(a>b) return 1;
    if(a<b) return -1;
    return 0;
}
int main(void){
    int yesno;
    long * pl;
    int total;
    srand(time(NULL));

    printf("How many elements numbers : ");
    scanf("%d", &total);

    pl = (long*)calloc(total, sizeof(long));
    if(pl == NULL)
        return -1;

    for(int i=0; i<total; i++){
        pl[i] = rand()%1000;
    }
    qsort(pl,total,sizeof(long), long_compare_desc); //함수포인터가 내림차순인가 , 오름차순인가에 따라 정렬이 다름

    puts("Let's search");
    do{
        
        long input;
        long * p;
        printf("Searching for number : ");
        scanf("%ld", &input);

        p = bsearch(&input, pl, total, sizeof(long),long_compare_desc);
        if(p){
            printf("find ! %ld is pl[%d]\n", *p, (int)(p-pl));
        }else{
            printf("cannot find\n");
            for(int i=0; i<total; i++)  printf("%ld ", pl[i]);
        }
        printf("\nRe-try ? (1:yes, 0:no)  ");
        scanf("%d", &yesno);
    }while(yesno == 1);

    puts("\nProgram exit.");
    free(pl);

    return 0;
}