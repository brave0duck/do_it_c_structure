// 진수 간 변환 함수. 16->10진수 10진수->8진수 
// 2-8.c를 수정하여 배열의 맨앞쪽에 아랫자리가 아니라 윗자리를 저장하는 card_conv함수를 작성

#include <stdio.h>

// 진수 변환 함수 
// 자릿수 리턴 card_conv( x = 타겟 숫자, n = 바꿀 진수 (16,8,10,2..) , d[] = 결과값을 저장할 배열)
int card_conv(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits=x; // 계산용 변수
    int nCount=0; // 자릿수 카운팅
    int result_value=0; // 리턴값

    // 0이 들어오면
    if (x == 0)
    {
        d[0] = dchar[0];
    }
    else
    {
        // 자릿수가 몇개인가?
        while(digits){
            digits /= n;
            nCount++;
        }
        // 자릿수를 리턴할것이므로 미리 저장
        result_value = nCount; 
        // 자릿수를 오른쪽부터 차곡차곡 넣는다
        while(x){
            d[--nCount] = dchar[x%n];
            x = x / n;
        }
    }
    
    return result_value;
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
        printf("%d진수로 ", cd);
        for (int i =0; i < dno ; i++)
        {
            printf("%c", cno[i]);
        }
        printf(" 입니다.\n");
        printf("\n계속할까요 ? (예:1, 아니오:0) : ");
        scanf("%d", &yesno);
    } while (yesno == 1);

    return 0;
}