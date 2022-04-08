//
// Created by 고연주 on 2022/04/08.
//

#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input;                //정수 선언
    priority_queue<int> pq; //최대 힙

    //입력
    cin >> n;
    while (n--) {                   //반복문
        cin >> a;                   //a 입력받기
        if (!a) { //아이들을 만난 경우
            if (pq.empty()) {       //pq가 비어있다면 -1을 출력
                cout << "-1\n";
            } else {                //아닐 경우 queue의 가장 위 값을 출력
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else { //선물을 충전하는 경우
            while (a--) {       //반복문
                cin >> input;   //input 입력받기
                pq.push(input); //input값 pq에 추가
            }
        }
    }
    return 0;
}