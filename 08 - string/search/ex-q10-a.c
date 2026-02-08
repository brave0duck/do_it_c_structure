//부르트포스 법으로 가장 뒤쪽의 인덱스를 반환하는 bf_matchr함수를 작성 (스택을 이용)

#include <stdio.h>
#include <string.h>
#define MAX 256

// 패턴을 찾은 맨처음 인덱스 반환
int bf_match(const char txt[], const char pat[]){
    int pt=0;
    int pp=0;

    while(txt[pt] != '\0' && pat[pp]!= '\0'){
        if(txt[pt] == pat[pp]){
            pt++; pp++;
        }else{
            pt = pt - pp +1;
            pp =0;
        }
    }
    if(pat[pp] == 0)
        return pt-pp;
    else
        return -1;
}
// 패턴을 찾은 맨뒤의 인덱스 반환
int bf_matchr(const char txt[], const char pat[]){
    int result=-1;//저장용 변수
    int pt=0;
    int pp=0;

    while(txt[pt] != '\0'){// 원본 문자열이 널이 아닐동안
        pp=0;
        while(pat[pp] !='\0' && txt[pt]!='\0'){// 패턴문자열이 널이아닐동안
            if(txt[pt] == pat[pp]){
                pt++; pp++;
            }else{
                pt = pt - pp +1;
                pp =0;
            }
        }
        if(pat[pp] == 0){
            result = pt - pp;// 찾으면 위치저장
        }
    }
    if(result == -1){
        return -1;
    }else{
        return result;
    }
}
int main(void){
    int idx=0;
    //              0     5        13
    char s1[MAX] = "ABEACBABGYTBAKZABE";
    char s2[MAX] = "AB";
    

    idx = bf_matchr(s1,s2);
    if(idx == -1){
        puts("찾지 못했습니다.");
    }else{
        printf("%d번째 문자가 마지막 match.\n", idx+1);
    }

    return 0;
}