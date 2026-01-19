// 신체검사 구조체 연습
#include <stdio.h>
#define VMAX 21

typedef struct{
    char name[20];
    int height;
    double vision;
}PhysCheck;

double ave_height(const PhysCheck dat[], int n){
    double sum=0;
    for(int i=0; i<n ; i++){
        sum += dat[i].height;
    }
    return sum/n;
}
void dist_vision(const PhysCheck dat[], int n, int dist[]){
    for(int i=0; i<VMAX; i++){
        dist[i]=0;
    }
    for(i=0; i<n; i++){
        if( 0.0 <= dat[i].vision && dat[i].vision <= VMAX/10.0 ){
            dist[(int)(dat[i].vision * 10)]++;
        }
    }
}
int main(void){
    int i;
    int st_size;
    int vdist[VMAX];

    PhysCheck x[] = {
        {"박현규", 162, 0.3},
        {"함진아", 173, 0.7},
        {"최윤미", 175, 2.0},
        {"홍연의", 171, 1.5},
        {"이수진", 168, 0.4},
        {"김영준", 174, 1.2},
        {"박용규", 169, 0.8}
    };

    st_size = sizeof(x) / sizeof(x[0]);

    puts("")
    return 0;
}