//하노이의 탑
#include <stdio.h>
int NCOUNT;
void move(int no, int x, int y){
    if(no>1)
        move(no-1,x,6-x-y);     // 6-x-y = 중간기둥

    printf("%d - 원반[%d]를 %d에서 %d 으로 옮김\n", ++NCOUNT,no, x,y);

    if(no>1)
        move(no-1, 6-x-y,y);

}
int main(void){
    int n;
    printf("하노이의 탑. 원반 개수 : ");
    scanf("%d", &n);
    move(n,1,3);

    return 0;
}