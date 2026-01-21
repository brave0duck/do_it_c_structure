// require : 직각이등변 삼각형을 출력하는 함수 (*)
// 어느 부분의 직각이냐에 따라 4가지 함수
// triangleLU(n) : left up
// triangleRU(n) : right up
// triangleLB(n) : left bottom
// triangleRB(n) : right bottom
#include <stdio.h>
// left up
void triangleLU(int n)
{
    int i, j;
    for (i = n; i >= 1; i--)
    {
        for (j = i; j >= 1; j--)
        {
            printf("*");
        }
        putchar('\n');
    }
}
// right up
void triangleRU(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i > j)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        putchar('\n');
    }
}
// right bottom
void triangleRB(int n)
{
    int i, j;
    for (i = n; i >= 1; i--)
    {
        for (j = 1; j <= n; j++)
        {
            if (i > j)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        putchar('\n');
    }
}
// left bottom
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

    triangleLU(n);
    triangleRU(n);
    triangleLB(n);
    triangleRB(n);
    return 0;
}