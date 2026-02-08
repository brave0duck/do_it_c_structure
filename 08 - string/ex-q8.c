//대문자-소문자를 구분하지않고 두문자열을 비교하는 함수를 작성
// conv - 대문자를 소문자로 변환
// conv_comp - 대소문자 구분없이 비교하는 함수
#include <stdio.h>

// 대문자를 소문자로 변환
char conv(const char s){
    if('A' <= s && s <= 'Z'){
        return s+ ('a' - 'A');
    }
    return s;
}
// 대소문자 구별없이 문자간 비교
int conv_comp(const char *s1,const char * s2){
    return conv(*s1) - conv(*s2);
    
}
// c표준함수 strcmp구현
int str_cmp(const char * s1, const char * s2){
    while((conv(*s1) - conv(*s2))==0){
        if(*s1 == '\0'){
            return 0;
        }
        s1++;s2++;
    }
    return conv(*s1) - conv(*s2);
}
// c표준함수 strncmp구현
int str_ncmp(const char * s1,const char * s2, size_t n){
    int i;
    for(i=0; i <n; i++){
        if((conv_comp(&s1[i],&s2[i]) != 0)){
            break;
        }
        if(s1[i] == '\0'){
            return 0;
        }
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
int main(void){
    char st[128];
    puts("[ABCD]와 비교합니다.");
    puts("[XXXX]면 종료합니다.");

    
    while(1){
        printf("문자열 st (size 4): ");
        scanf("%s",st);
        if(str_ncmp("XXXX",st,4) == 0){
            break;
        }
        printf("str_cmp(\"ABCD\",st) = %d\n", str_ncmp("ABCD",st,4));
    }
    return 0;
}