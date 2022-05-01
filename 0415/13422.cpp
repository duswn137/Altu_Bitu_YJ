//
// Created by 고연주 on 2022/05/01.
//

#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {        //훔치는 함수 작성
    //윈도우 초기화
    int money = 0;                                          //훔친 돈 저장할 변수 저장
    for (int i = 0; i < m; i++) {                           //반복문 이용해서
        money += house[i];                                  //i번째 집에 있는 돈을 더해준다
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans;                                     //ans 값 리턴
    }
    for (int i = m; i < n + m - 1; i++) {               //반복문 이용해서
        money -= house[i - m];                          //시계방향이므로 i-m값과
        money += house[i % n];                          //나머지 값을 이용해준다
        if (money < k) {                                //훔친 돈의 합이 k보다 작으면
            ans++;                                      //ans추가해준다
        }
    }
    return ans;                                         //ans 리턴
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {                                                //메인함수
    int t, n, m, k;                                         //정수 선언

    cin >> t;                                               //테스트케이스 개수 입력받기
    while (t--) {                                           //반복문
        //입력
        cin >> n >> m >> k;                                     //입력받기
        vector<int> house(n, 0);                            //집에 있는 돈 저장할 벡터 설정 및 0으로 초기화
        for (int i = 0; i < n; i++) {                           //반복문 이용해서
            cin >> house[i];                                    //입력받은 값을 벡터에 저장해준다
        }

        //연산 & 출력기
    }
    return 0;
}