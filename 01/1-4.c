// 1부터 n까지 합을 구하는 프로그램
#include <stdio.h>

int sum_to_n(int n);

int main(void)
{
    int input;
    int result;

    printf("sum 1 to N. input N (0 to exit): ");
    while (scanf("%d", &input) != EOF && input != 0)
    {
        result = sum_to_n(input);
        if (result != -1)
        {
            printf("sum result : %d\n", result);
        }
        else
        {
            printf("%d is must bigger than 0.\n", input);
        }
        printf("sum 1 to N. input N (0 to exit): ");
    }
    printf("Program exit.");
    return 0;
}
int sum_to_n(int n)
{
    int sum = 0;
    if (n < 1)
    {
        return -1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        return sum;
    }
}