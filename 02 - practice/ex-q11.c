// 2-12.c를 수정해서 for문 변수i와 days를 사용하지않고 dayofyear()함수 변환. while문사용
#include <stdio.h>
#include <stdlib.h>

const int mdays[][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};

int isleap(int year){
    return year%4 == 0 && year%100 != 0 || year%400 == 0;
}
int dayofyear2(int year, int month, int day){
    int leap = isleap(year);
    while(month--){
        day += mdays[leap][month-1];
    }
    return day;
}
int main(void){
    int year, month, day;
    int yesno;

    printf("=== What day of the year is it day ===\n");
    do{
        printf("Year : ");
        scanf("%d",&year);
        printf("Month : ");
        scanf("%d", &month);
        printf("day : ");
        scanf("%d", &day);
        
        printf("%d year's %d th day.\n", year, dayofyear2(year,month,day));
        printf("continue ? (yes:1, no:0) : ");
        scanf("%d", &yesno);
    }while(yesno == 1);

    return 0;
}