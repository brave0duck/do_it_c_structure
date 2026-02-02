// qsort함수를 이용해서 배열을 오름차순으로 정렬하는 프로그램 작성
// char a[][7] = {"LISP","C","Ada","Pascal"};
// 배열포인터와 포인터배열에 약간 차이가 있다
// 배열포인터 = 그냥 넘기면된다. char * a[][7] => const char* x
// 포인터배열 = const*형으로 한번더 변환해서 넘김(이중포인터). char *p[] => const char* const* x
// const char* const * ??? 
// (x)--->[const]--->[const char]  ()변경가능. []변경불가

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_str(const void *x, const void *y){
    return strcmp((const char*)x,(const char*)y);
}
int cmp_ptr(const void *x, const void * y){
    const char *const* a = x;
    const char *const* b = y;
    return strcmp(*a,*b);
}
int main(void){
    char a[][7] = {"LISP","C","Ada","Pascal"};
    char *p[] = {"LISP","C","Ada","Pascal"};
    
    size_t size_a = sizeof(a) / sizeof(a[0]);
    size_t size_p = sizeof(p) / sizeof(p[0]);

    qsort(a,size_a, sizeof(a[0]),cmp_str);
    printf("\na[][7] sort : \n");
    for(int i=0; i<size_a ; i++){
        printf("%s\n",a[i]);
    }
    putchar('\n');
    

    qsort(p,size_p,sizeof(p[0]), cmp_ptr);

    printf("\n*p[] sort : \n");
    for(int i=0; i<size_p ; i++){
        printf("%s\n",p[i]);
    }
    putchar('\n');
    
    return 0;
}