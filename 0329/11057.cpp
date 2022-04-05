//
// Created by 고연주 on 2022/04/05.
//

#include <iostream>
#include <vector>

using namespace std;
const int MOD = 10007;                              //답을 구하고 10007로 나눠야함

//길이 N에서 일의 자리 수가 0 ~ 9인 오르막 수 모두 더하는 함수
int sumLastCnt(vector<int> &arr) {                      //함수 작성 시작
    int ans = 0;                                        //오르막수 개수 ans 선언하고 0으로 초기화
    for (int i = 0; i < arr.size(); i++) {              //반복문 작성
        ans += arr[i];                                  //ans=ans+arr[i]
        ans %= MOD;                                     //ans를 10007로 미리미리 나눠서 저장
    }
    return ans;                                         //ans에 저장된 값 리턴
}

int upNumberCnt(int n) {                                //오르막수 구하는 함수 작성
    vector<vector<int>> dp(n + 1, vector<int>(10, 1));  //이차원배열 이용

    for (int i = 2; i <= n; i++) {                      //수의 길이
        for (int j = 1; j < 10; j++) {                  //일의자리수 j
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];     //배열에 저장
            dp[i][j] %= MOD;                            //10007로 나눠서 값 저장
        }
    }
    return sumLastCnt(dp[n]);                       //오르막수 더하는 함수 사용
}

/**
 * dp[i][j] = 수의 길이가 i이고, 일의 자리 수가 j인 오르막 수의 개수
 *
 * -> (j보다 작은 수 or j와 같은 수) + j를 하면 오르막 수가 됨
 * -> j보다 작은 수로 끝나는 길이 i - 1 인 오르막 수 개수 + j로 끝나는 길이 i - 1 인 오르막 수 개수
 * -> j보다 작은 수로 끝나고 길이가 i - 1 인 오르막 수의 접근은 길이 i인 오르막 수에서 마지막 수를 j로 대체하는 것으로 해결 가능
 * => dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
 *
 * dp 배열 채운 후, 길이가 n이고 일의 자리 수가 0 ~ 9인 오르막 수 개수 모두 더하면 됨!
 *
 * ex. 길이가 2인 오르막 수의 개수를 구해야 한다면
 *      0  1  2  3  4  5  6  7  8  9
 *  -------------------------------
 *  1 : 1  1  1  1  1  1  1  1  1  1
 *  2 : 1  2  3  4  5  6  7  8  9  10
 *  -> 2행의 값을 모두 더해서 출력!
 *
 *  해당 풀이는 연산 편하게 하기 위해 미리 dp 값 1로 초기화
 *  !주의! 마지막에 길이 n인 오르막 수 모두 더할 때도 모듈러 연산 해야함
 */

int main() {                                //메인함수 작성
    int n;                                  //정수 n 선언

    //입력
    cin >> n;                               //n입력받기

    //연산 & 출력
    cout << upNumberCnt(n);                 //작성한 함수 이용해서 오르막수 구해서 출력
    return 0;
}