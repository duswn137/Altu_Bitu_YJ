//
// Created by 고연주 on 2022/04/08.
//

#include <iostream>
#include <deque>

using namespace std;

string dqToString(deque<char> &dq) {        //함수 작성
    string ans = "";                        //string 선언하고 초기화
    while (!dq.empty()) {                   //dp가 비어있는 경우에 한해서
        ans += dq.front();                  //선언한 string에 추가
        dq.pop_front();                     //dp 가장 앞 원소 삭제
    }
    return ans;                                 //저장된 string 출력
}

string findPass(string s) {
    deque<char> dq_left;  //커서 이전 내용을 저장
    deque<char> dq_right; //커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) {      //s의 길이보다 짧은 횟수만큼 반복문 실행
        switch (s[i]) {                         //switch 조건문 사용, s[i]일때
            case '-': //현재 커서 앞에 있는 글자를 지운다.
                if (!dq_left.empty()) {         //dq_left 비어있지 않으면
                    dq_left.pop_back();         //가장 뒤의 원속 삭제
                }
                break;
            case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
                if (!dq_left.empty()) {     //dq_left 비어있지 않으면
                    dq_right.push_front(dq_left.back());        //dq_left의 마지막원소를 dq_right에 삽입
                    dq_left.pop_back();                             //추가된 원소는 기존deque에서 삭제
                }
                break;                                              //break
            case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
                if (!dq_right.empty()) {                            //dq_rigth가 비어있지 않을때
                    dq_left.push_back(dq_right.front());            //dq_right의 마지막 원소를 dq_left에 삽입
                    dq_right.pop_front();                           //추가된 원소는 기존 deque에서 삭제
                }
                break;
            default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
                dq_left.push_back(s[i]);                //기본적으로는 문자가 들어오면 dq_left에 추가한다
                break;
        }
    }

    string pass = dqToString(dq_left);                  //이전에 작성한 함수 이용해서 dqleft와
    pass += dqToString(dq_right);                       //dq_right에 저장
    return pass;                                            //pass 리턴한다
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {                    //메인함수
    int t;                      //정수 선언
    string s;                   //string 선언

    //입력
    cin >> t;                   //t 입력받기
    while (t--) {               //반복문 통해서
        cin >> s;               //s 입력받기

        //연산 & 출력
        cout << findPass(s) << '\n';        //작성한 함수 이용해서 출력
    }
    return 0;
}