//
// Created by 고연주 on 2022/04/08.
//

#include <iostream>
#include <set>

using namespace std;

/**
 * set 풀이
 *
 * set은 중복값이 제거되기 때문에 multiset을 이용하여 저장해야 함
 * multiset 또한 값을 넣으면 정렬이 바로 되기 때문에 이후의 정렬 과정이 따로 필요 없음
 */
int main() {                                //메인함수
    ios::sync_with_stdio(false);        //속도 향상
    cin.tie(NULL);

    int t, k, n;                        //입력받을 정수 선언
    char cmd;                           //입력받을 char 선언

    cin >> t;                               //t 입력받기
    while (t--) {                           //반복문 시작
        multiset<int> ms; //중복 저장
        cin >> k;                               //k 입력받기
        while (k--) {                           //반복문
            //입력
            cin >> cmd >> n;                    //입력받기

            //연산
            switch (cmd) {                      //switch조건문
                case 'I': //I 연산
                    ms.insert(n);           //n 저장
                    break;
                case 'D': //D 연산
                    if (ms.empty()) { //ms가 비어있다면 연산 무시
                        break;
                    }
                    if (n == 1) { //최댓값 삭제
                        ms.erase(--ms.end());
                    }
                    if (n == -1) { //최솟값 삭제
                        ms.erase(ms.begin());
                    }
                    break;
            }
        }

        //출력
        if (ms.empty())                             //비어있다면
            cout << "EMPTY\n";                      //EMPTY 출력
        else
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
    }
}