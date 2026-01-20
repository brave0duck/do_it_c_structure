// 날짜를 나타내는 구조체가 있을경우 아래의 함수를 작성하시오
//  1. Date Dateof(int y, int m, int d);    y년m월d일을 나타내는 구조체를 반환하는 함수
//  2. Date After(Date x, int n);           날짜x의 n일 뒤의 날짜를 반환하는 함수
//  3. Date Before(Date x, int n);          날짜x의 n일 전의 날짜를 반환하는 함수
#include <stdio.h>

typedef struct{
    int year;
    int month;
    int day;
}Date;

int mdays[][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};
//윤년인가?
int isleap(int year){
    return year%4 == 0 && year%100 != 0 || year%400 == 0;
}
// 날짜구조체에 입력 
Date Dateof(int y,int m,int d){
    Date a;
    a.year = y;
    a.month = m;
    a.day = d;
    return a;
}
//몇일뒤로 이동
Date After(Date x, int n){
    int leap = isleap(x.year);  // 윤년 체크(윤년마다 마지막날이 다르다! 윤년 2월은 29일)
    while(n){
        if( n > (mdays[leap][x.month-1] - x.day)){   // 이동일이 그달 마지막날보다 더 큰가?
            n -= (mdays[leap][x.month-1] - x.day); // 차일을 계산
            x.day=0;
            x.month++;
            if(x.month==13){    //12월이 넘어가면 연,월을 다음해 1월로 갱신
                x.year++; x.month=1;
            }
        }else{  // 이동일이 마지막날보다 작으면 그냥 더해서 종료
            x.day += n;
            break;
        }
    }
    return x;
}
//몇일전으로 이동
Date Before(Date x, int n){
    int leap = isleap(x.year);  // 윤년 체크(윤년마다 마지막날이 다르다! 윤년 2월은 29일)
    while(n){
        if( n > x.day){  //이동일이 지정일보다 큰지 확인
            n = n - x.day;    //뺀날을 계산
            x.month--;
            if(x.month == 0){   // 1월밑으로 내려가면 연,월을 작년 12월로 갱신
                x.year--; x.month=12;
            }
            x.day = mdays[leap][x.month];
        }else{
            x.day = x.day - n;
            break;
        }
    }
    return x;
}
int main(void){
    Date x;
    int year,month,day;
    int yesno;

    int distance;

    printf("연 월 일 계산프로그램\n");
    printf("연 : ");
    scanf("%d", &year);
    printf("월 : ");
    scanf("%d", &month);
    printf("일 : ");
    scanf("%d", &day);

    x = Dateof(year,month,day);
    printf("지정한 날짜는 %d년- %d월 - %d일 입니다.\n", x.year, x.month, x.day);
    
    yesno=1;
    while(yesno != 0){
        
        printf("\n===================\n");
        printf("현 : %d년- %d월 - %d일\n", x.year, x.month, x.day);
        printf("1.After\n");
        printf("2.Before\n");
        printf("0.Exit\n : ");
        scanf("%d", &yesno);

        if (yesno == 1){
            printf("몇일 뒤로 이동할까요 ? ");
            scanf("%d", &distance);
            x = After(x,distance);
            printf("\n%d일 뒤는 %d년 %d월 %d일 입니다.\n", distance, x.year, x.month, x.day);
        }
        if (yesno == 2){
            printf("몇일 앞으로 이동할까요 ? ");
            scanf("%d", &distance);
            x = Before(x,distance);
            printf("\n%d일전은 %d년 %d월 %d일 입니다.\n", distance, x.year, x.month, x.day);
        }
        
        printf("\n===================\n");
        printf("현 : %d년- %d월 - %d일\n", x.year, x.month, x.day);
        printf("1.After\n");
        printf("2.Before\n");
        printf("0.Exit\n : ");
        scanf("%d", &yesno);
        
    }
    printf("프로그램을 종료합니다.\n\n");
    return 0;
}