// 직각 이등변 삼각형 출력
#include <stdio.h>

int main(void)
{
    int i, j, n;
    do
    {
        printf("몇층짜리 삼각형 입니까? : ");
        scanf("%d", &n);

    } while (n <= 0);

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}