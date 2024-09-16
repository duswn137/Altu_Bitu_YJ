//
// Created by 고연주 on 2022/04/15.
//

#include <iostream>
#include <map>

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
    ios::sync_with_stdio(false);                    //속도향상
    cin.tie(NULL);

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power;                                    //정수 선언
    string name;                                        //스트링 선언

    //입력
    cin >> n >> m;                                      //값 입력받기
    while (n--) {                                       //반복문 통해서
        cin >> name >> power;                           //입력받기
        if (title[power].empty()) {                     //title[power] 비어있으면
            title[power] = name;                        //거기에 입력받은 name 넣기
        }
    }

    //출력
    while (m--) {                                               //출력 반복문
        cin >> power;                                           //power 입력받아서
        cout << title.lower_bound(power)->second << '\n';    //거기에 들어있는 칭호중 가장 먼저 입력된 값 출력하기
    }
}