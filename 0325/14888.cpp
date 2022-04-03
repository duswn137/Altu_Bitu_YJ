//
// Created by 고연주 on 2022/04/01.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;            //10억
const int SIZE = 11;                //수의 개수

int n;
vector<int> num(SIZE + 1);          //배열 인덱스를 1번부터 해주려고 +1해준다
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;      //최소 최대 -10억부터 10억까지

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum);            //최댓값
        min_value = min(min_value, sum);            //최솟값
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {
            expression[i]--;
            int new_sum = 0;
            switch (i) { //연산자 종류에 따라
                case 0:
                    new_sum = sum + num[cnt + 1];   //더하기
                    break;
                case 1:
                    new_sum = sum - num[cnt + 1];   //빼기
                    break;
                case 2:
                    new_sum = sum * num[cnt + 1];   //곱하기
                    break;
                case 3:
                    new_sum = sum / num[cnt + 1];   //나누기
                    break;
            }
            backtracking(cnt + 1, new_sum);     //함수 실행
            expression[i]++;
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {                            //메인함수
    //입력
    cin >> n;                           //n입력받기
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> expression[i];
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}