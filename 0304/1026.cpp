//
// Created by 고연주 on 2022/03/10.
//

#include <iostream>     //기본적으로 필요
#include <vector>       //
#include <algorithm>    //sort 함수 사용하기 위해서 필요

using namespace std;    //std 클래스 사용하겠다는 선언

//함수 S의 계산
int calS(int n, vector<int> a, vector<int> b)   //calS라는 함수를 생성
{
    int s=0;        //s값을 0으로 할당
    for (int i = 0; i < n; i++) {   // 반복문을 이용
        s+=(a[i]*b[i]);             //a와 b의 i번째 인덱스 값끼리 곱해서 s에 더해준다
    }
    return s;                       //계산값 리턴
}

int main(){                         // 메인함수
    int n;                          // n 선언
    vector<int> a, b;               // 배열 a, b

    //입력
    cin>>n;                         //n 입력받기
    a.assign(n,0);              //a의 n개 배열을 0으로 초기화
    b.assign(n,0);              //b의 n개 배열을 0으로 초기화

    for (int i = 0; i < n; i++) {   // 반복문 이용
        cin >> a[i];                  // 숫자를 입력받아서 차례대로 a에 저장
    }
    for (int i = 0; i < n; i++) {   // 반복문 이용
        cin >> b[i];                 //숫자를 입력받아서 차례대로 b에 저장
    }

    sort(a.begin(),a.end());    //a 오름차순으로 정렬
    sort(b.begin(),b.end(),greater<>());    //b 내림차순으로 정렬
    int result= calS(n,a,b);        //result에 함수 calS 이용해서 s값 저장

    //출력
    cout<<result;                   //result값 출력
    return 0;                       //리턴
}