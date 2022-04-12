//
// Created by 고연주 on 2022/04/12.
//

#include <iostream>
#include <vector>

using namespace std;

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) {           //i에는 row 값을
        for (int j = col; j < col + 3; j++) {       //j에는 column값을 넣어서
            if (matrix_a[i][j] == '1') {            //그 값이 1이면
                matrix_a[i][j] = '0';               //0으로 바꾸고
            }
            else {                                  //그 값이 0이면
                matrix_a[i][j] = '1';               //1로 바꿔준다
            }
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) {               //행렬의 값을 바꿀 수 있는지 확인
        for (int j = 0; j < m; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) {     //행렬 값이 맞지 않는 경우에는
                return false;                           //false를 리턴한다
            }
        }
    }
    return true;                                            //그 외의 경우에는 true 리턴
}

/**
 * [행렬]
 *
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {                                                    //메인함수
    int n, m;                                                   //정수 선언

    //입력
    cin >> n >> m;                                              //정수 입력받기
    vector<string> matrix_a(n);                                 //행렬 a 선언
    vector<string> matrix_b(n);                                 //행렬 b 선언
    for (int i = 0; i < n; i++) {                               //반복문 이용해서
        cin >> matrix_a[i];                                     //행렬 a에 값 넣기
    }

    for (int i = 0; i < n; i++) {                               //반복문 이용해서
        cin >> matrix_b[i];                                     //행렬 b에 값 넣기
    }

    //연산
    int ans = 0;                                                    //몇 번 바꿔야하는지 저장하는 변수
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a);         //작성한 함수 이용해서 행렬 뒤집어주기
                ans++;                                              //바꾸는 횟수 더해주기
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) {        //바꾸는 것이 가능한지 확인하고 불가능할경우
        ans = -1;                                       //-1 출력
    }
    cout << ans;
    return 0;
}