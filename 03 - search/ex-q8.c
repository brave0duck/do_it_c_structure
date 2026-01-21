// bsearch() 직접구현. ft.chatgpt
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void *binsearch(const void *key, const void *base, size_t nmemb, size_t size,
                int (*func)(const void *, const void *))
{
    if (nmemb == 0 || base == NULL || key == NULL)
        return NULL;

    const char *b = (const char *)base;
    int low = 0;
    int high = (int)nmemb - 1;
    int mid;
    int is_asc;

    /* determine order using first and last elements */
    if (func(b, b + (nmemb - 1) * size) < 0)
        is_asc = 1; /* ascending */
    else if ( func(b, b + (nmemb - 1) * size) > 0)
        is_asc = 0; /* descending */
    else
        return NULL; /* all equal or cannot determine */

    while (low <= high) {
        mid = (low + high) / 2;
        const void *elem = b + mid * size;
        int cmp = func(elem, key);

        if (cmp == 0)
            return (void *)(b + mid * size);

        if (is_asc) {
            if (cmp < 0)
                low = mid + 1;
            else
                high = mid - 1;
        } else {
            if (cmp < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    return NULL;
}
int comp_asc(const void *x, const void *y)
{
    int a = *(const int *)x;
    int b = *(const int *)y;
    if (a < b)
        return -1;
    if (a > b)
        return 1;
    return 0;
}
int comp_dsc(const void *x, const void *y)
{
    int a = *(const int *)x;
    int b = *(const int *)y;
    if (a < b)
        return 1;
    if (a > b)
        return -1;
    return 0;
}
int main(void){
    int numbers, key;    int * parray;
    int *pIndex;

    srand(time(NULL));
    puts("===Binary Search v0.1===");
    printf("How many elements? : ");
    scanf("%d", &numbers);
    parray = (int *)malloc(numbers*sizeof(int));

    printf("ascending arrange ...\n");
    for(int i=0; i<numbers; i++){
        parray[i] = 1+ rand()%50;
    }
    qsort(parray,numbers,sizeof(int),comp_dsc);

    printf("What is number that you will find? (0~)");
    scanf("%d", &key);
    
    pIndex = (int *)binsearch(&key, parray, numbers, sizeof(int), comp_dsc);

    if (pIndex == NULL) {
        printf("unfortunaly, cannot find key\n");
    } else {
        int index = (int)(pIndex - parray);
        printf("%d is it %dth element\n", *pIndex, index + 1);
    }
    puts("elements : ");
    for(int i=0; i<numbers;i++)
        printf("%d ",parray[i]);

    free(parray);
    return 0;
}