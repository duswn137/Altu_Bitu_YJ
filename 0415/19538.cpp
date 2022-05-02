//
// Created by 고연주 on 2022/05/01.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {
    vector<int> rest(n + 1, 0); //각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q;  //사람 저장

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) { //반복문 이용해서
        ans[init[i]] = 0;   //시작 초기화
        q.push(init[i]);    //q에 넣어주기
    }

    //루머 믿어야 하는 주변인 수 초기화
    for (int i = 1; i <= n; i++) { //반복문 이용해서
        rest[i] = (people[i].size() + 1) / 2;   //주변인수 값 저장
    }

    while (!q.empty()) {        //q가 비어있지 않은 경우에 대해서
        int curr = q.front(); //현재 사람
        int t = ans[curr]; //루머 믿은 시간
        q.pop();    //q 앞의 값 삭제

        for (int i = 0; i < people[curr].size(); i++) { //반복문 이용해서
            int next = people[curr][i]; //next에 믿는 사람 넣기
            if (ans[next] > -1) { //이미 루머를 믿는 다면
                continue;   //반복문 계속 진행
            }
            rest[next]--;   //값 줄이기
            if (!rest[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1; //시간 +1 해서 저장
                q.push(next);   //q에 next를 저장한다
            }
        }
    }
    return ans;         //ans 저장
}

/**
 * [루머]
 *
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크 배열을 루머를 믿는 시간을 저장하는 배열로 대체함
 *    ans[i] = -1 일 경우, i는 루머를 믿지 않는다
 *    ans[i] = t인 경우, i는 t분 부터 루머를 믿기 시작함
 * 각자가 루머를 믿기 위해 주변인의 절반 이상이 루머를 믿어야 하므로, 각 사람이 루머를 믿기까지 루머를 믿는 주변인 몇명이 남았는지를 리스트에 기록한다.
 * 남은 사람이 0인 순간, 해당 사람은 루머를 믿기 시작
 */

int main() {        //메인함수
    int n, m, input;    //정수 선언

    //루머 퍼뜨리는 관계 입력
    cin >> n;   //n입력받기
    vector<vector<int>> people(n + 1, vector<int>());   //사람 저장할 벡터 선언
    for (int i = 1; i <= n; i++) {  //반복문 이용해서 n번 값 입력받기
        while (true) {
            cin >> input;
            if (!input) {
                break;
            }
            people[i].push_back(input);     //입력받은 값 배열에 저장
        }
    }

    //최초 유포자 입력
    cin >> m;           //최초유포자수 입력받기
    vector<int> init(m, 0); //유포자 저장할 배열 선언
    for (int i = 0; i < m; i++) {   //반복문 이용해서
        cin >> init[i]; //그 값 배열에 저장
    }

    //연산
    vector<int> ans = bfs(people, init, n); //함수 이용해서 계산한 값 배열에 저장

    //출력
    for (int i = 1; i <= n; i++) {  //반복문 이용해서 정답 출력
        cout << ans[i] << ' ';  //루머 믿기 시작한 시간 출력, 공백으로 구분
    }
    return 0;
}