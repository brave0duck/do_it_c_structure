#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, y;
    for (int i = 1; i < 50; i++)
    {
        x = rand();
        y = rand();
        if (x == y)
        {
            printf("same : x %d, y %d\n", x, y);
        }
        else
        {
            printf("not same : x %d, y %d\n", x, y);
        }
    }

    return 0;
}