//
// Created by 고연주 on 2022/03/29.
//


#include <iostream>


#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    ios::sync_with_stdio(false);        //시간 단축
    cin.tie(NULL);

    int m, num;                               //연산의 수, x값
    string cmd;                              //입력받을 연산
    vector<bool> s(SIZE, false);        //벡터  s선언

    cin >> m;                               //수행해야하는 연산 개수 입력받기
    while (m--) {                           //반복문 이용해서 수행할 연산 작성
        cin >> cmd;                         //수행할 연산 입력받기
        if (cmd == "all") {                 //all이 입력될 경우
            s.assign(SIZE, true);     //size만큼 true로 바꿔서 전부 수행
            continue;                       //계속
        }
        if (cmd == "empty") {               //empty가 입력될 경우
            s.assign(SIZE, false);  //size만큼 false로 바꿔서 공집합으로 바꾸기
            continue;
        }

        cin >> num;                         // x입력받기
        if (cmd == "add") {                 //add가 입력될 경우
            s[num] = true;                  //s[num]을 true로 바꿈
            continue;
        }
        if (cmd == "remove") {              //remove 가 입력될 경우
            s[num] = false;                 //s[num]을 false로 바꿈
            continue;
        }
        if (cmd == "check") {               //check가 입력될 경우

            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        if (cmd == "toggle") {              //toggle 입력될 경우
            s[num] = !s[num];               //있으면 없다고 바꾸고 없으면 있다고 바꾸기
            continue;
        }
    }
    return 0;
}