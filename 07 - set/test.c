#include <stdio.h>

int main(void){
    printf("int size - %d\n",sizeof(int));
    printf("float size - %d\n",sizeof(float));
    printf("double size - %d\n",sizeof(double));
    printf("long size - %d\n",sizeof(long));
    printf("unsigned long size - %d\n",sizeof(unsigned long));
    printf("unsigned long long size - %d\n",sizeof(unsigned long long));

    return 0;
}