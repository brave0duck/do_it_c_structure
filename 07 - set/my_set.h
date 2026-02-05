#ifndef __MYSET__
#define __MYSET__

typedef struct{
    int max;
    int num;
    int * pSet;
}IntSet;

int Initialize(IntSet *s, int max); //집합 초기화
int IsMember(const IntSet *s, int n);   // 집합s에 n이 포함되어있는지 확인. 멤버맞음=index, 아님=0
int Add(IntSet *s, int n); //집합s에 원소n 추가. 추가불가 = -1, 추가했음 =0
int Remove(IntSet *s, int n);  //집합s에 원소n삭제. 삭제불가 -1, 삭제했음 0
int Capacity(const IntSet *s);  //집합s에 넣을수있는 최대원소 개수를 반환
int Size(const IntSet *s);  //집합s의 원소개수
int Assign(IntSet *s1,const IntSet *s2);   //집합s2를 집합s1에 대입
int Equal(const IntSet *s1,const IntSet *s2);   //집합s1과 집합s2가 같은지 확인

IntSet* Union(IntSet * s1,const IntSet *s2, const IntSet *s3);  //합집합. s2와 s3의 합집합을 s1에 대입
IntSet* Intersection(IntSet *s1,const IntSet *s2, const IntSet *s3);    //교집합. s2와 s3의 교집합을 s1에 대입
IntSet* Difference(IntSet *s1, const IntSet *s2, const  IntSet *s3);    //차집합. s2에서 s3를 뺀 차집합을 s1에 대입

void Print(const IntSet * s);   // 집합s의 모든 원소를 출력한다
void Println(const IntSet *s);  //집합s의 모든 원소를 출력 줄바꿈포함
void Terminate(IntSet *s);  //집합종료
int IsFull(const IntSet *s);    //가득찼나? y=1,no=0
void Clear(IntSet *s);  //클리어

// 대칭차집합(Symmetric Difference)은 두 집합 A, B에서 교집합(A∩B)을 제외한 합집합(A∪B)으로
// 양쪽 집합 중 어느 한쪽에만 속하는 원소들의 집합입니다. 
// 기호로는 (A∪B)-(A∩B)
IntSet* symmetricDifference(IntSet *s1, const IntSet *s2,const IntSet *s3);
// s1에 s2의 모든 원소를 추가해서 합집합을 만듬
IntSet* ToUnion(IntSet *s1, const IntSet *s2);
//s1에서 s2에 들어있지않은 모든 원소를 삭제
IntSet* ToIntersection(IntSet *s1, const IntSet *s2);
//s1에서 s2에 들어있는 모든 원소를 삭제
IntSet* ToDifference(IntSet *s1,const IntSet *s2);
// s1이 s2의 부분집합이면 1 아니면 0
int IsSubset(const IntSet *s1, const IntSet *s2);
// s1이 s2의 진부분집합. 진부분집합이면 1 아니면 0
int IsProperSubset(const IntSet *s1, const IntSet *s2);
// 진부분집합이란? a의 모든 요소가 b의 원소이면서 a,b집합이 같지않을경우

#endif