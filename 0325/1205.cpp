//
// Created by 고연주 on 2022/04/01.
//

#include <iostream>
#include <vector>

using namespace std;

int findRanking(int n, int new_score, int p, vector<int> &ranking) {        //등수 구하는 함수 작성
    int idx = 1;                                        //
    int ans = 1;                                        //등수 출력할 변수 1로 초기화하며 선언
    //새로운 점수를 어느 위치에 넣을지 탐색
    while (idx <= n) {                                  //idx가 입력되는 점수 N개보다 작을때 반복문
        if (new_score > ranking[idx]) {                 //새로 입력되는 점수가 더 큰 경우에는
            break;                                      //반복문 멈추기
        }
        if (new_score < ranking[idx]) {                 //새로 입력되는 점수가 더 작은 경우
            ans = idx + 1;                              //랭킹을 하나 증가시켜준다
        }
        idx++;                                          //인덱스 증가시켜주기
    }
    if (idx == p + 1) { //랭킹 리스트에 들어가지 못하는 경우
        return -1;
    }
    return ans;                                         //  등수 리턴
}

/**
 * [등수 구하기]
 *
 * 1. n = 0일 때, 고려
 * 2. 등수는 p보다 작지만, 점수가 더 좋을 때만 랭킹이 갱신되므로 랭킹 리스트에 들어가지 못하는 경우 고려 (동점)
 *
 * 현재 랭킹에 올라간 n까지 등수와 새로운 점수를 비교하며 새로운 점수 몇 등인지 계산
 * 새로운 점수가 현재 탐색 등수의 점수보다 작다면 -> 현재 탐색 등수 + 1
 * 동점일 경우 -> 그 전 등수 그대로 사용 -> 아무 처리도 하지 않음!
 */

int main() {                                        //메인함수
    int n, new_score, p;

    //입력
    cin >> n >> new_score >> p;                     //점수 개수, 점수, 리스트에 올라갈 점수 입력받기
    vector<int> ranking(p + 1, 0);            //랭킹 저장할 배열 1부터 넣으려고 p+1개, 0으로 초기화
    for (int i = 1; i <= n; i++) {                  //반복문 이용해서 
        cin >> ranking[i];                          //랭킹 i번째 인덱스에 값 저장
    }

    //연산 & 출력
    cout << findRanking(n, new_score, p, ranking);              //등수 구하는 함수 이용해서 출력하기
    return 0;
}