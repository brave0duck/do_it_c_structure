// require : 직각이등변 삼각형을 출력하는 함수 (*로)
#include <stdio.h>

void triangleLB(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        putchar('\n');
    }
}
int main(void)
{
    int n;
    do
    {
        printf("몇 단 삼각형 입니까? : ");
        scanf("%d", &n);
    } while (n <= 0);

    triangleLB(n);

    return 0;
}