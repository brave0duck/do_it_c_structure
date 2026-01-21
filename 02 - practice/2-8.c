// 진수 간 변환 함수. 16->10진수 10진수->8진수 ....
#include <stdio.h>

// 진수 변환 함수 .  x = 타겟 숫자, n = 바꿀 진수 (16,8,10,2..) , d[] = 결과값을 저장할 배열
int card_conv(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;

    // 나머지를 1번째 배열에 저장하고 몫을구한후 다음으로 넘어가서 계속 반복. 몫이 0이 되기전까지
    if (x == 0)
    {
        d[digits++] = dchar[0];
    }
    else
    {
        while (x)
        {
            d[digits++] = dchar[x % n];
            x = x / n;
        }
    }
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
        printf("변환할 숫자 입력(양수만) : ");
        scanf("%u", &no);
        do
        {
            printf("변환할 진수를 선택하세요 (2-36) : ");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);

        dno = card_conv(no, cd, cno);
        printf("%d진수는 : ", cd);
        for (int i = dno - 1; i >= 0; i--)
        {
            printf("%c", cno[i]);
        }
        printf("\n계속할까요 ? (예:1, 아니오:0) : ");
        scanf("%d", &yesno);
    } while (yesno == 1);

    return 0;
}