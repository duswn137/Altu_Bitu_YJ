//
// Created by 고연주 on 2022/04/08.
//

#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

ll getCost(priority_queue<ll, vector<ll>, greater<>> &pq) { //함수 정의
    ll ans = 0;                                             //초기화

    while (pq.size() > 1) {         //pq에 값이 존재하는 경우에 한해서
        ll card1 = pq.top();        //card1에 pq 맨 위의 값 대입하기
        pq.pop();                   //pq 맨 위의 값 삭제
        ll card2 = pq.top();        //card2에 pq의 맨 위의 값 대입
        pq.pop();                   //pq 맨 위의 값 삭제
        ans += card1 + card2;       //card1과 card2에 입력된 값 더해서 ans에 저장
        pq.push(card1 + card2); //그 값을 다시 pq에 저장
    }
    return ans;                     //ans 출력
}

/**
 * [파일 합치기 3]
 *
 * - 파일을 전부 합치기 위해서는 어차피 하나로 만들어야 한다!
 * - 이 때, 여러번 더해지는 값은 작을 수록 좋다
 * - 따라서, 현재 가장 작은 파일 2개를 합쳐야 비용을 최소화 할 수 있다.
 * -> 최소 힙으로 구현
 *
 * !주의! 파일의 개수는 최대 1,000,000 이고 각 크기의 최대는 10,000이므로
 *       정답의 최댓값이 10^10으로 int 범위를 넘기 때문에 long long 써야 함
 */

int main() {                                //메인함수
    int t, k, file;                         //정수 선언

    //입력
    cin >> t;                               //t 입력받기
    while (t--) {                           //반복문
        priority_queue<ll, vector<ll>, greater<>> pq; //최소합

        //입력
        cin >> k;                           //k 입력받기
        for (int i = 0; i < k; i++) {       //k보다 작은 값에서 반복문
            cin >> file;                    //file 값 입력받기
            pq.push(file);              //pq에 입력받은 file 값 추가
        }

        //연산 & 출력
        cout << getCost(pq) << '\n';            //출력
    }
    return 0;
}