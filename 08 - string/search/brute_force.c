// 문자열내 패턴검색
// 1. brute force 
// 배열처음부터 마지막까지 패턴문자열과 일치하는지 순서대로 비교
#include <stdio.h>
#include <string.h>

int brute_force(const char* src, const char * find){
    int src_size = strlen(src);
    int find_size = strlen(find);
    
    for(int i=0;i< src_size - find_size; i++){  // 원본문자열-찾는문자열
        for(int j=i; j+find_size < src_size; j++ ){
            if( strncmp(&src[j],find,find_size) == 0){
                return j;
            }
        }
    }
    return 0;
}
int main(void){
    int index;
    char * src = "asdfefefga";  //10
    char * find ="fef";    //3

    if(index = brute_force(src,find)){
        printf("find! %s is %dth in %s",find,index,src);
    }else{
        printf("Not found");
    }

    return 0;
}