// 난수를 이용해 배열의 요소값 설정하기
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int maxof(const int *a, int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
int main(void)
{
    int *pHeight;
    int number;
    printf("How many students? : ");
    scanf("%d", &number);

    pHeight = (int *)calloc(number, sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < number; i++)
    {
        pHeight[i] = 150 + rand() % 50;
        printf("height[%d] = %d\n", i, pHeight[i]);
    }
    printf("== Max height is %d\n", maxof(pHeight, number));

    free(pHeight);
    return 0;
}