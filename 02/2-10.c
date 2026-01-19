//1,000이하의 소수를 나열합니다 ver.2
// 소수배열을 만든후 숫자와 배열을 비교한다. 
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i,n;
    unsigned long counter=0;
    int prime_index=0;
    int primes[500];

    primes[prime_index++] = 2;  //처음엔 아예 배열 0번째에 2를 지정해준다

    for(n=3; n <= 1000; n+=2){  // 3부터 시작해서 2씩 이동 (짝수는 2로 무조건 나누어지므로 홀수만 판단)
        for(i=1; i< prime_index ; i++ ){    // 프라임배열의 원소갯수만큼 순회
            counter++;                      // 연산이 몇번 일어났는가 계산위한 변수
            if(n%primes[i] == 0){           //n이 프라임배열 내에 나누어 떨어지는 수를 발견하면 나간다
                break;
            }
        }
        if(prime_index == i){               // 이 문장은 이런뜻. 안쪽 for문을 다돌고왔다면 i와 prime_index값이 같을것이고 , 중간에 break걸렸으면 틀릴것
            primes[prime_index++] = n;      // 어떤 소수배열의 멤버와도 나누어 떨어지지 않았으므로 이건 소수다. 그러니 배열에 추가한다
        }
    }
    for(int i=0; i < prime_index; i++){
        printf("%d : %d\n", i+1, primes[i]);
    }
    printf("나눗셈을 실행한 횟수 : %lu\n", counter);
    return 0;
}