// ...existing code...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define __MAX__ 5
#define swap(x,y) do{ int t; t=x; x=y; y=t;}while(0);
#define FIELD_WIDTH 6

// ...existing code...
static void print_centered_int(int x, int width){
    char buf[32];
    int len = snprintf(buf, sizeof(buf), "%d", x);
    if(len >= width){
        // too wide: just print number and a separating space
        printf("%s ", buf);
        return;
    }
    int left = (width - len) / 2;
    int right = width - len - left;
    for(int i=0;i<left;i++) putchar(' ');
    fputs(buf, stdout);
    for(int i=0;i<right;i++) putchar(' ');
    putchar(' ');
}

void bubble_sort(int a[], int size){
    for(int i=0; i<size; i++){  //0 1 2 3 4
        for(int j=size-1; j>i; j--){    //4 3 2 1
            print_centered_int(a[j], FIELD_WIDTH);
            if (a[j-1] > a[j]){
                swap(a[j-1],a[j]);
                printf("*");
            }else{
                printf("-");
            }
        }
    }
}
void array_print(int a[], int max, int key, int flag){
    for(int i=0; i<max; i++){
        print_centered_int(a[i], FIELD_WIDTH);
        if(i==key){
            putchar(flag ? '*' : '-');
        }else{
            putchar(' ');
        }
    }
}
void bubble_sort2(int a[], int n){
    int i,j;
    int flag=0;
    for(i=0; i<n-1; i++){   //0 1 2 3 4
        printf("PASS %d : \n",i+1);
        
        for(j=0; j<n-1-i; j++){    // 0 1 2 3 4
            if ( a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                array_print(a,n,j,1);
            }else{
                array_print(a,n,j,0);
            }
            printf("\n");
        }
        
        printf("\n");
    }
}
int main(void){
    int *a;
    a = (int*)malloc(__MAX__*sizeof(int));

    srand(time(NULL));
    printf("Before bubble sort : \t");
    for(int i=0; i<__MAX__; i++){
        a[i] = 1 + rand() % 200;
        print_centered_int(a[i], FIELD_WIDTH);
    }
    putchar('\n');

    bubble_sort2(a,__MAX__);

    printf("\nAfter Bubble sort : \t");
    for(int i=0; i<__MAX__; i++){
        print_centered_int(a[i], FIELD_WIDTH);
    }
    putchar('\n');
    free(a);
    return 0;
}
// ...existing code...