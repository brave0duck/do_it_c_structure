// 진수 변환 함수. 변환과정을 상세히 출력하는 프로그램 작성
// 
#include <stdio.h>

// [자릿수 리턴] card_conv( x = 오리지널 숫자, n = 바꿀 진수 (16,8,10,2..) , d[] = 결과값을 저장할 배열)
int card_conv(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;

    putchar('\n');
    // 나머지를 1번째 배열에 저장하고 몫을구한후 다음으로 넘어가서 계속 반복. 몫이 0이 되기전까지
    if (x == 0)
    {
        d[digits++] = dchar[0];
        printf("%2d | \t%2d --- %d\n", n, x, x%n);
        printf("   +-------\n");
    }
    else
    {
        while (x)
        {
            printf("%3d | \t%3d --- %3d\n", n, x, x%n);
            printf("    +-------\n");
            d[digits++] = dchar[x % n];
            x = x / n;
        }
        printf("\t%3d\n", x);
    }
    putchar('\n');
    return digits;
}

int main(void)
{

    unsigned int no; // 변환하고자 하는 수 입력
    int cd;          // 변환 진수 입력
    int dno;
    char cno[512];

    int yesno;

    printf("10진수를 기수변환 합니다.\n");
    do
    {
        printf("변환하는 음이 아닌 정수 : ");
        scanf("%u", &no);
        do
        {
            printf("어떤 진수로 변환할까요? (2-36) : ");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);


        dno = card_conv(no, cd, cno);
        printf("%d진수로 ", cd);
        for (int i=dno-1; i >=0 ; i--)
        {
            printf("%c", cno[i]);
        }
        printf(" 입니다.\n");
        printf("\n계속할까요 ? (예:1, 아니오:0) : ");
        scanf("%d", &yesno);
    } while (yesno == 1);

    return 0;
}