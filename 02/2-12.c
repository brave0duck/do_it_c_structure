// 오늘이 올해 몇번째 날인지 계산하는 프로그램. 평년 ,윤년 계산이 필수적이다
#include <stdio.h>
#include <stdlib.h>

int mdays[][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};

int isleap(int year){
    return year%4 == 0 && year%100 != 0 || year%400 == 0;
}
int dayofyear(int year, int month, int day){
    int i;
    int days = day;
    int leap = isleap(year);

    for(i=1; i<month; i++){
        days += mdays[leap][i-1];
    }
    return days;
    
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
        
        printf("%d year's %d th day.\n", year, dayofyear(year,month,day));
        printf("continue ? (yes:1, no:0)");
        scanf("%d", &yesno);
    }while(yesno == 1);

    return 0;
}