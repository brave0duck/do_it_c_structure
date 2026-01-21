// 이진검색 간단구현
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(const int *p, int n, int key){
    int start=0;
    int end = n-1;
    int mid;
    
    while(end >= start){
        mid = (end + start)/2;
        if (key == p[mid]){
            return mid;
        }else if( key > p[mid]){
            start = mid+1;
            
        }else if( key < p[mid]){
            end = mid-1;
        }
    }
    return -1;
}
// 9 8 7 6 5 4 3 2 1 key=7
int binary_search2(const int *p, int n ,int key){
    int start = n-1;
    int end = 0;
    int mid;

    while(start >= end){
        mid = (start +end )/2;
        if (key == p[mid]){
            return mid;
        }else if( key > p[mid]){
            end = mid-1;
        }else if( key < p[mid]){
            start = mid +1;
        }
    }
    return -1;
}
void * binsearch(const void *key, const void *base, size_t nmemb, sizt_t size, comp_asc){
    int start,end,mid;
    int is_asc=0;       // if ascending
    if(comp_asc(base[0],base[nmemb-1]) == -1){
        start = 0;
        end = nmemb -1;
        is_asc = 1;
    }else if (comp_asc(base[0],base[nmemb-1] == 1)){
        end = 0;
        start = nmemb-1;
        is_asc = 0;
    }else{
        return -1;
    }

    while(end >= start){
        mid = (end + start)/2;
        if (key == p[mid]){
            return mid;
        }else if( key > p[mid]){
            if(is_acs)  start = mid+1;
            else end = mid -1;
            
        }else if( key < p[mid]){
            if(is_acs)  end = mid-1;
            else    start = mid+1;
        }
    }
    return -1;
}
int comp_asc(const void *x, const void *y){
    int a = *(const int*)x;
    int b = *(const int*)y;
    if(a>b) return -1;
    if(a<b) return 1;
    return 0;
}
int main(void){
    int numbers, key, index;    int * parray;

    srand(time(NULL));
    puts("===Binary Search v0.1===");
    printf("How many elements? : ");
    scanf("%d", &numbers);
    parray = (int *)malloc(numbers*sizeof(int));

    printf("ascending arrange ...\n");
    for(int i=0; i<numbers; i++){
        parray[i] = rand()%1000;
    }
    qsort(parray,numbers,sizeof(int),comp_asc);

    printf("What is number that you will find? (0~)");
    scanf("%d", &key);
    
    index = binary_search(parray,numbers,key);

    if(index == -1){
        printf("unfortunaly, cannot find key\n");
    }else{
        printf("%d is it %dth element\n", parray[index], index+1);
    }
    puts("elements : ");
    for(int i=0; i<numbers;i++)
        printf("%d ",parray[i]);

    free(parray);
    return 0;
}