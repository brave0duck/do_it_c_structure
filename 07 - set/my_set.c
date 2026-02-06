//집합의 모든 연산 구현
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "my_set.h"

#define NOT -1

//집합 초기화
int Initialize(IntSet *s, int max){
    s->pSet = (int*)calloc(max,sizeof(int));
    if(s->pSet == NULL)
        return NOT;
    s->max = max;
    s->num = 0;
    return 0;
}
// 집합s에 n이 포함되어있는지 확인. 위치리턴
int IsMember(const IntSet *s, int n){
    for(int i=0; i<s->num; i++){
        if( s->pSet[i] == n)
            return i;
    }
    return NOT;
}
//집합s에 원소n 추가
int Add(IntSet *s, int n){
    if( s->num >= s->max || IsMember(s,n) != NOT){
        return NOT;
    }
    s->pSet[s->num++] = n;
    return 0;
}
//집합s에 원소n삭제 
int Remove(IntSet *s, int n){
   int pos = IsMember(s,n);
    if( s->num <= 0 || pos == NOT){
        return NOT;
    }else{
        s->pSet[pos] = s->pSet[--s->num];
    }
    return 0;
}
//집합s에 넣을수있는 최대원소 개수를 반환
int Capacity(const IntSet *s){
    return (s->max - s->num);
}
//집합s의 원소개수
int Size(const IntSet *s){
    return s->num;
}
//집합s2를 집합s1에 대입. s1요소는 없애고 전부 대체한다. s1->num을 새로운 집합에 맞게 조정한다
int Assign(IntSet *s1,const IntSet *s2){
    int n = (s1->max < s2->num) ? s1->max : s2->num;// s1 max나 s2 num중 큰수에 맞춰
    for(int i=0; i<n ; i++){
        s1->pSet[i] = s2->pSet[i];
    }
    s1->num = n;
    return 0;
}
//집합s1과 집합s2가 같은지 확인
int Equal(const IntSet *s1,const IntSet *s2){
    
    if(s1->num != s2->num)// 크기가 다르면 다르다
        return 0;
    for(int i=0; i<s1->num; i++){
        if(IsMember(s2, s1->pSet[i]) == NOT)//s2집합에 s1의 모든 요소가 다 있고
            return 0;
    }
    for(int i=0; i<s2->num ; i++){
        if(IsMember(s1,s2->pSet[i]) == NOT)//s1집합에 s2의 모든 요소가 다 있으면 같은것이다
            return 0;
    }
    return 1;
}
//합집합. s2와 s3의 합집합을 s1에 대입
IntSet* Union(IntSet * s1,const IntSet *s2, const IntSet *s3){
    s1->num=0;
    for(int i=0; i<s2->num; i++ ){
        Add(s1,s2->pSet[i]);
    }
    // 두번째는 중복여부를 확인
    for(int k=0; k<s3->num; k++){
        if(IsMember(s1,s3->pSet[k]) == NOT){
            Add(s1,s3->pSet[k]);
        }
    }
    return s1;
}
//교집합. s2와 s3의 교집합을 s1에 대입
IntSet* Intersection(IntSet *s1,const IntSet *s2, const IntSet *s3){
    s1->num=0;
    for(int i=0; i<s2->num; i++){
        //IsMember가 not이 아니면,즉. 멤버가 있다면
        if(IsMember(s3,s2->pSet[i]) != NOT){ 
            Add(s1,s2->pSet[i]);
        }
    }
    return s1;
}
//차집합. s2에서 s3를 뺀 차집합을 s1에 대입
IntSet* Difference(IntSet *s1, const IntSet *s2, const  IntSet *s3){
    s1->num=0;
    for(int i=0; i<s2->num; i++){
        if(IsMember(s3,s2->pSet[i]) == NOT){    //s3내에 없는 변수만 s1에 저장
            Add(s1,s2->pSet[i]);    
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
int IsFull(const IntSet *s){
    return s->num >= s->max;
}
void Clear(IntSet *s){
    s->num=0;
}
// 대칭차집합(Symmetric Difference)은 두 집합 A, B에서 교집합(A∩B)을 제외한 합집합(A∪B)
IntSet* symmetircDifference(IntSet *s1, const IntSet *s2, const IntSet *s3){
    IntSet uSet,iSet;
    assert(!Initialize(&uSet,s1->num));
    assert(!Initialize(&iSet,s2->num));

    Union(&uSet,s2,s3); // uSet은 합집합
    Intersection(&iSet,s2,s3);  // iSet은 교집합
    Difference(s1,&uSet,&iSet); // uSet - iSet은 대칭차집합

    Terminate(&uSet);
    Terminate(&iSet);
    return s1;
}
//// s1에 s2의 모든 원소를 추가해서 합집합을 만듬
IntSet* ToUnion(IntSet *s1, const IntSet *s2){
    for(int i=0; i<s2->num; i++){
        if( Add(s1,s2->pSet[i]) == NOT){
            printf("ToUnion 실패. 크기가 부족합니다.");
            return s1;
        }
    }
    return s1;
}
//s1에서 s2에 들어있지않은 모든 원소를 삭제
IntSet* ToIntersection(IntSet *s1, const IntSet *s2){
    for(int i=0; i<s1->num; i++){
        if( IsMember(s1,s2->pSet[i]) == NOT){
            Remove(s1,s2->pSet[i]);
        }
    }
}
//s1에서 s2에 들어있는 모든 원소를 삭제
IntSet* ToDifference(IntSet *s1, const IntSet *s2){
    for(int i=0; i<s1->num; i++){
        if( IsMember(s1,s2->pSet[i]) != NOT){
            Remove(s1,s2->pSet[i]);
        }
    }
}
// s1이 s2의 부분집합이면 1 아니면 0
int IsSubset(const IntSet *s1, const IntSet *s2){
    for(int i=0; i<s1->num; i++){
        if(IsMember(s2,s1->pSet[i]) == NOT){
            return 0;
        }
    }
    return 1;
}
// s1이 s2의 진부분집합이면 1 아니면 0
// 진부분집합이란? a의 모든 요소가 b의 원소이면서 a,b집합이 같지않을경우
int IsProperSubset(const IntSet *s1, const IntSet *s2){
    if(IsSubset(s1,s2) && Equal(s1,s2)){    //부분집합인가?
        return 1;
    }
    return 0;
}

int main(void){
    IntSet s1,s2,s3;
    IntSet *pSet;
    int max=10;

    printf("==== 집합 예제 ====\n");
    printf("s1,s2,s3집합을 생성했습니다...\n");
    srand(time(NULL));

    assert(!Initialize(&s1,(max*2)));
    assert(!Initialize(&s2,max)); 
    assert(!Initialize(&s3,max));

    //assign random number 
    for(int i=0; i<max; i++){
        s2.pSet[i] = 1 + rand() % 20;
        s3.pSet[i] = 1 + rand() % 20;
    }

    while(1){
        int menu, x, data;
        int yesno;
        
        printf("\n================= S E T ====================\n");
        printf("(1)IsMember(2)Add (3)Remove (4)Print (5)Equal \n");
        printf("(6)Assign     (7)Union     (8)Intersection \n");
        printf("(9)Difference (0)Exit \n");
        printf("============================================\n");
        scanf("%d", &menu);

        switch(menu){
            case 1: //IsMember
                printf("Set , data : ");
                scanf("%d %d", &x, &data);
                if(x==2){
                    if(IsMember(&s2,data) == NOT){
                        printf("s2집합에 %d [없다]\n",data);
                    }else{
                        printf("s2집합에 %d [있다]\n",data);
                    }
                }else if(x==3){
                    if(IsMember(&s3,data) == NOT){
                        printf("s3집합에 %d [없다]\n",data);
                    }else{
                        printf("s3집합에 %d [있다]\n",data);
                    }
                }
                break;
            case 2: // Add
                printf("Set , data : ");
                scanf("%d %d", &x, &data);
                if(x==2){
                    if(Add(&s2,data)){
                        printf("s2집합에 %d Add x\n",data);
                    }else{
                        printf("s2집합에 %d Add o\n",data);
                    }
                }else if(x==3){
                    if(Add(&s3,data)){
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
                    if(Remove(&s2,data)){
                        printf("s2집합에 %d Remove x\n",data);
                    }else{
                        printf("s2집합에 %d Remove o\n",data);
                    }
                }else if(x==3){
                    if(Remove(&s3,data)){
                        printf("s3집합에 %d Remove x\n",data);
                    }else{
                        printf("s3집합에 %d Remove o\n",data);
                    }
                }
                break;
            case 4://print
                printf("s1 set : ");
                for(int i=0; i< s1.num;  i++){
                    printf("%d ",s1.pSet[i]);
                }putchar('\n');
                printf("s2 set : ");
                for(int i=0; i<s2.num; i++){
                    printf("%d ",s2.pSet[i]);
                }putchar('\n');
                printf("s1 set : ");
                for(int i=0; i<s3.num; i++){
                    printf("%d ",s3.pSet[i]);
                }putchar('\n');
                break;
            case 5: // Equal
                if(Equal(&s2,&s3)){
                    printf("s2와 s3은 같습니다. equal=0\n");
                }else{
                    printf("s2와 s3은 틀립니다. equal=x\n");
                }
                break;
            case 6: // Assign
                if(Assign(&s2,&s3)){
                    printf("s3가 s2보다 더 큽니다. 대입연산 실패\n");
                }else{
                    printf("대입했습니다...\n");
                }
                break;
            case 7://union
                pSet=Union(&s1,&s2,&s3);
                break;
            case 8://intersection
                pSet=Intersection(&s1,&s2,&s3);
                break;
            case 9://difference
                pSet=Difference(&s1,&s2,&s3);
                break;
            case 0:// Exit
                printf("Program Exit");
                goto EXIT;
        }
        
    }
EXIT:
    Terminate(&s1);Terminate(&s2);Terminate(&s3);
    return 0;
}