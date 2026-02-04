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

#endif