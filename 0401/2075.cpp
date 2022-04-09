//
// Created by 고연주 on 2022/04/08.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;                                  //정수 선언
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 정렬이랑 반대

    cin >> n;                   //정수 입력받기
    int size = n * n;           //size 값은 n의 제곱으로 설정
    while (size--) {            //size가 n제곱인 경우에 한해서 반복문
        //입력
        cin >> input;           //input 입력받기

        //연산
        pq.push(input);     //pq에 input받은 값 추가
        if (pq.size() > n) { //최소 힙의 크기가 n 이상이라면 가장 작은 값 삭제
            pq.pop();
        }
    }

    //출력
    cout << pq.top();
    return 0;
}