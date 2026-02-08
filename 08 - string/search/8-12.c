//부르트포스 법으로 문자열을 검색하는 프로그램
// 원본이나 패턴문자열이 널이 아닐때까지
//1. 문자하나씩 비교한다
//2. 같으면 다음, 같으면 다음...
//3  다르면 원본 시작을 +1
// 스택을 이용하면 맨뒤 인덱스도 얻을수있다

#include <stdio.h>
#include <string.h>
#define MAX 256

typedef struct stack{
    int ptr;
    int stk[10];
}Stack;

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
int Push(Stack *s,int n){
    if (s->ptr < MAX){
        s->stk[s->ptr++] = n;
    }
}
int Pop(Stack *s){
    if(s->ptr >0){
        return s->stk[--s->ptr];
    }
}
int IsEmpty(Stack *s){
    return s->ptr == 0;
}
int main(void){
    int pos=0;
    Stack stk;
    stk.ptr=0;

    int idx=0;
    
    char s1[MAX] = "ABEGABDEGGABDX";
    char s2[MAX] = "AB";
    

    while(1){
        idx = bf_match(&s1[pos],s2);
        if(idx == -1){
            break;
        }else{
            pos  += idx;
            Push(&stk,pos);
            pos  += strlen(s2);
        }
    }
    if(IsEmpty(&stk)){
        printf("패턴을 찾을수없습니다.");
    }else{
        printf("맨뒤의 인덱스는 %d입니다.\n",Pop(&stk));
    }
    

    return 0;
}