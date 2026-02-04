//int형 집합 my_set집합
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_set.h"

#define MAX 10

//집합 초기화
int Initialize(IntSet *s, int max){
    s->pSet = (int*)calloc(max,sizeof(int));
    if(s->pSet == NULL)
        return -1;
    s->max = max;
    s->num = 0;
    return 0;
}
// 집합s에 n이 포함되어있는지 확인. 위치리턴
int IsMember(const IntSet *s, int n){
    for(int i=0; i<num; i++){
        if( s->pSet[i] == n)
            return i;
    }
    return 0;
}
//집합s에 원소n 추가
int Add(IntSet *s, int n){
    if( !IsMember(s,n) || s->num >= s->max )
        return -1;
    s->pSet[s->num++];
    return 0;
}
//집합s에 원소n삭제 
int Remove(IntSet *s, int n){
    int pos = IsMember(s,n);
    if( !pos|| s-<num <= 0 ){
        return -1;
    }else{
        for(int i=pos+1; i<s->num ; i++){
            s->pSet[i-1] = s->pSet[i];
        }
        s->num--;
    }
    return 0;
}
//집합s에 넣을수있는 최대원소 개수를 반환
int Capacity(const IntSet *s){
    return s->max - s->num;
}
//집합s의 원소개수
int Size(const IntSet *s){
    return s->num;
}
//집합s2를 집합s1에 대입
int Assign(IntSet *s1,const IntSet *s2){
    if(s2->max > s1->max){
        return -1;
    }
    for(int i=0;i<s1->num; i++){// all delete
        s1->pSet[i] = 0;
    }
    s1->num=0;//init num
    for(int i=0; i<s2->num ; i++){// new assignment
        s1->pSet[i] = s2->pSet[i];
        s1->num++;
    }
    return 0;
}
//집합s1과 집합s2가 같은지 확인
int Equal(const IntSet *s1,const IntSet *s2){
    
    for(int i=0; i<s1->num; i++){
        if(!IsMember(s2, s1->pSet[i]))//s2집합에 s1의 모든 요소가 다 있고
            return 0;
    }
    for(int i=0; i<s2->num ; i++){
        if(!IsMember(s1,s2->pSet[i]))//s1집합에 s2의 모든 요소가 다 있으면 같은것이다
            return 0;
    }
    return 1;
}
//합집합. s2와 s3의 합집합을 s1에 대입
IntSet* Union(IntSet * s1,const IntSet *s2, const IntSet *s3){
    int i;
    s1->num=0;
    for(i=0; i<s2->num; i++ ){
        s1->pSet[i] = s2->pSet[i];
        s1->num++;
    }
    // 두번째는 중복여부를 확인
    for(int k=0; k<s3->num; k++,i++){
        if(!IsMember(s1,s3->pSet[k])){
            s1->pSet[i] = s3->pSet[k];
            s1->num++;
        }
    }
    return s1;
}
//교집합. s2와 s3의 교집합을 s1에 대입
IntSet* Intersection(IntSet *s1,const IntSet *s2, const IntSet *s3){
    s1->num=0;
    for(int i=0; i<s2->num; i++){
        if(IsMember(s3,s2->pSet[i])){
            Add(s1,s2->pSet[i]);
            s1->num++;
        }
    }
    return s1;
}
//차집합. s2에서 s3를 뺀 차집합을 s1에 대입
IntSet* Difference(IntSet *s1, const IntSet *s2, const  IntSet *s3){
    s1->num=0;
    for(int i=0; i<s2->num; i++){
        if(!IsMember(s3,s2->pSet[i])){
            Add(s1,s2->pSet[i]);
            s1->num++;
        }
    }
}
// 집합s의 모든 원소를 출력한다
void Print(const IntSet * s){
    for(int i=0; i<s->num; i++){
        printf("%d ",s->pSet[i]);
    }
}
//집합s의 모든 원소를 출력 줄바꿈포함
void Println(const IntSet *s){
    for(int i=0; i<s->num; i++){
        printf("%d\n",s->pSet[i]);
    }
}
//집합종료
void Terminate(IntSet *s){
    if(s->pSet != NULL){
        free(s->pSet);
        s->max=0;
        s->num=0;
    }
}
int main(void){
    IntSet s1,s2,s3;
    srand(time(NULL));

    printf("==== 집합 예제 ====\n");
    printf("s1,s2,s3집합을 생성했습니다...");
    
    Initialize(s1,MAX+MAX);
    Initialize(s2,MAX); Initialize(s3,MAX);

    for(int i=0; i<MAX; i++){
        s2->pSet[i] = 1 + rand() % 20;
        s3->pSetp[i] = 1 + rand() % 20;
    }

    while(1){
        int menu, x, data;
        int yesno;
        printf("s1집합 : %d ,s2집합 :%d, s3집합 : %d/n",s1->max, s2->max, s3->max);
        printf("(1)IsMember (2)Add (3)Remove (4)Print (5)Equal \n");
        printf("(6)Assign (7)Equal (8)Union (9)Intersection (10)Difference (11)PrintAll (0)Exit\n")
        scanf("%d", &menu);

        switch(menu){
            case 1: //IsMember
                printf("Set , data : ");
                scanf("%d %d", &x, &data);
                if(x==2){
                    if(IsMember(s2,data)){
                        printf("s2집합에 %d [있다] o\n,data");
                    }else{
                        printf("s2집합에 %d [없다] x\n",data);
                    }
                }else if(x==3){
                    if(IsMember(s3,data)){
                        printf("s3집합에 %d [있다] o\n",data);
                    }else{
                        printf("s3집합에 %d [없다] x\n",data);
                    }
                }
                break;
            case 2: // Add
                printf("Set , data : ");
                scanf("%d %d", &x, &data);
                if(x==2){
                    if(Add(s2,data)){
                        printf("s2집합에 %d Add x\n",data);
                    }else{
                        printf("s2집합에 %d Add o\n",data);
                    }
                }else if(x==3){
                    if(Add(s3,data)){
                        printf("s3집합에 %d Add x\n",data);
                    }else{
                        printf("s3집합에 %d Add o\n",data);
                    }
                }
                break;
            case 3: //Remove
                printf("Set , data : ");
                scanf("%d %d", &x, &data);
                if(x==2){
                    if(Remove(s2,data)){
                        printf("s2집합에 %d Remove x\n",data);
                    }else{
                        printf("s2집합에 %d Remove o\n",data);
                    }
                }else if(x==3){
                    if(Remove(s3,data)){
                        printf("s3집합에 %d Remove x\n",data);
                    }else{
                        printf("s3집합에 %d Remove o\n",data);
                    }
                }
                break;
            case 4: //print
                printf("s2집합 : "); Print(s2);
                printf("s3집합 : "); Print(s3);
                break;
            case 5: // Equal
                if(Equal(s2,s3)){
                    printf("s2와 s3은 같습니다. equal=0\n");
                }else{
                    printf("s2와 s3은 틀립니다. equal=x\n");
                }
                break;
            case 6: // Assign
                if(Assign(s2,s3)){
                    printf("s3가 s2보다 더 큽니다. 대입연산 실패\n");
                }else{
                    printf("대입했습니다...\n");
                }
                break;
            case 7:// Equal
                if(Equal(s2,s3)){
                    printf("s2와 s2는 같은 집합입니다.(o)\n");
                }else{
                    printf("s2와 s3는 같지않습니다.(x)\n");
                }
            case 8://union
                s1=Union(s1,s2,s3);
                break;
            case 9://intersection
                s1=Intersection(s1,s2,s3);
                break;
            case 10://union
                s1=Difference(s1,s2,s3);
                break;
            case 11://printAll
                for(int i=0; i<s1->num; i++){
                    printf("%d ",s1->pSet[i]);
                }
                break;
            case 0:
                printf("Program Exit");
                goto EXIT;
        }
        
    }
EXIT:
    Terminate(s);
    return 0;
}