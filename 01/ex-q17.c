// n단의 피라미드를 출력하는 함수를 작성하시오
#include <stdio.h>
// n=4, 7 = (4-1)*2 +1
// 1111111
//  22222
//   333
//    4
void nrPira(int n)
{
    int i, j;
    int z = (n - 1) * 2 + 1;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= z; j++)
        {
            printf("%d", i);
        }
        putchar('\n');
        for (int k = 1; k <= i; k++)
        {
            printf(" ");
        }
        z -= 2;
    }
}
void spira(int n)
{
    int i, j;
    int width = (n - 1) * 2 + 1; // n=4, z=7
    int half = width / 2 + 1;

    for (i = 1; i <= width; i += 2)
    {
        for (j = 1; j < half; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("*");
        }
        putchar('\n');
        half = half - 1;
    }
}
int main(void)
{
    int n;
    printf("what's lair ? : ");
    scanf("%d", &n);

    spira(n);
    nrPira(n);
    return 0;
}