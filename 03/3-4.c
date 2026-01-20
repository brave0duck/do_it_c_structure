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
int main(void){
    int numbers, key, index;    int * parray;

    srand(time(NULL));
    puts("===Binary Search v0.1===");
    printf("How many elements? : ");
    scanf("%d", &numbers);

    parray = (int *)malloc(numbers*sizeof(int));

    printf("shuffle number into array...\n");
    for(int i=0; i<numbers; i++){
        parray[i] = i*10 + rand()%10;
    }

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