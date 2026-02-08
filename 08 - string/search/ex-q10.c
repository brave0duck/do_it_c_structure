//부르트포스 법으로 가장 뒤쪽의 인덱스를 반환하는 bf_matchr함수를 작성
// 스택을 한번 이용해봄. 찾은 문자열간의 또 다른 연산을 할경우 유용
#include <stdio.h>
#include <string.h>
#define MAX 256

typedef struct stack{
    int ptr;
    int stk[10];
}Stack;

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
int bf_matchr(const char txt[], const char pat[]){
    Stack stk;
    stk.ptr=0;
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
            Push(&stk, pt - pp);// 스택에 푸쉬
        }
    }
    if(IsEmpty(&stk)){
        return -1;
    }else{
        return Pop(&stk);// 팝
    }
}
int main(void){
    int idx=0;
    
    char s1[MAX] = "ABEABGA";
    char s2[MAX] = "AB";
    

    idx = bf_matchr(s1,s2);
    if(idx == -1){
        puts("찾지 못했습니다.");
    }else{
        printf("%d번째 문자가 마지막 match.\n", idx+1);
    }

    return 0;
}