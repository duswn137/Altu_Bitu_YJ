//
// Created by 고연주 on 2022/05/01.
//

#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 1e5;

int bfs(int n, int k) {                 //함수작성
    vector<int> check(SIZE + 1, 0); //위치 체크 배열
    queue<int> q; //큐에 좌표값 저장
    int ans = 0;    //수빈이가 동생을 찾는데 걸리는 가장 빠른 시간 저장할 정수 선언 및 초기화

    check[n] = 1; //시작 노드 방문체크 + 시간 초기화
    q.push(n);  //q에 n 넣어둔다
    while (!q.empty()) {    //q에 값이 있는 경우에는
        int x = q.front();  //q의 첫번째 값을 x에 저장하고
        q.pop();            //q에서 값을 꺼sosek

        if (x == k) {       //x값이 k랑 같으면(수빈이가 동생을 찾으면)
            ans = check[x] - 1; //반복한 횟수에서 하나 빼고 ans에 저장
            break;
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //자식 노드
        for (int i = 0; i < 3; i++) {           //자식노드로 가능한 경우에 대해서 반복문
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) {    //0보다 크고 1e5보다 작은 수이면서 check에 걸리지 않는 값인 경우에
                check[child[i]] = check[x] + 1; //check[child[i]]에 새로운 값 저장
                q.push(child[i]);           //  q에 child[i]값을 넣는다
            }
        }
    }
    return ans;     //ans값 리턴
}

/**
 * [숨바꼭질]
 *
 * x좌표 위에서 x-1, x+1, 2*x의 위치로 계속 이동하며 탐색
 * 가장 빠른 시간을 찾아야 하므로 주변 노드부터 탐색하는 풀이로 풀어서 k에 도달하면 바로 탐색 종료 (bfs)
 */

int main() {
    int n, k;       //정수 선언

    //입력
    cin >> n >> k;      //수빈이 위치와 동생 위치 입력받기

    //연산 & 출력
    cout << bfs(n, k);  //함수 이용해서 답 출력한다
    return 0;
}