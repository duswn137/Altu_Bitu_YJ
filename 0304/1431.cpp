//
// Created by 고연주 on 2022/03/11.
//

#include <iostream>     //  기본적으로 필요함
#include <vector>       //  배열 사용하려고
#include <algorithm>    //sort 함수 사용하려고

using namespace std;    //std 클래스 사용 선언

//문자열의 모든 자릿수 합을 구하는 함수
int sumNum(string str) {                        // 함수 작성
    int sum = 0;                                //  문자열 자릿수의 합을 sum으로 받고, 초기화
    for (int i = 0; i < str.size(); i++) {      //  반복문
        if (isdigit(str[i])) { //문자(char)에 대해 숫자인지 판별하는 함수
            sum += str[i] - '0'; //char -> int로 바꾸는 방법 (아스키 코드에 대해 알아보세요)
        }
    }
    return sum;                                 //  sum 리턴
}

//비교함수
bool cmp(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) { //두 문자열의 길이가 다르다면 짧은 문자열이 먼저 오도록
        return s1.size() < s2.size();
    }
    if (sumNum(s1) != sumNum(s2)) { //두 문자열의 숫자 합이 다르다면 합이 작은 문자열이 먼저 오도록
        return sumNum(s1) < sumNum(s2);
    }
    return s1 < s2; //사전순
}

int main() {                            //메인함수
    int n;                              //입력받을 n 선언
    vector<string> serial_num;          //시리얼넘버 받을 배열 선언

    //입력
    cin >> n;                           //  n입력받기
    serial_num.assign(n, "");       // 배열 초기화
    for (int i = 0; i < n; i++) {       //반복문
        cin >> serial_num[i];           //입력받기
    }

    //연산
    sort(serial_num.begin(), serial_num.end(), cmp);        //sort 함수로 배열 정렬

    //출력
    for (int i = 0; i < n; i++) {               //반복문
        cout << serial_num[i] << '\n';          //배열 출력
    }
    return 0;                                   //리턴값
}