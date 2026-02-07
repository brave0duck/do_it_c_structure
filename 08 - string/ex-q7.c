//c언어 표준라이브러리 함수 strncmp함수와 같은 동작을 하는 함수 str_ncmp를 작성
#include <stdio.h>

int str_cmp(const char * s1, const char * s2){
    while(*s1 == *s2){
        if(*s1 == '\0'){
            return 0;
        }
        s1++;s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}
int str_ncmp(const char * s1,const char * s2, size_t n){
    int i;
    for(i=0; i <n; i++){
        if(s1[i] != s2[i]){
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