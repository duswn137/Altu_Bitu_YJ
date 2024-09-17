//
// Created by 고연주 on 2022/05/01.
//

#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int> &belt) {    //함수 작성
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;              //쿠폰으로 먹는 초밥 1개 먼저 저장
    sushi[c]++;                         //스시 개수 추가

    //윈도우 초기화
    for (int i = 0; i < k; i++) {   //반복문
        if (!sushi[belt[i]]) {  //입력받는 k 이전까지
            section_sushi++;    //스시 개수 증가시키기
        }
        sushi[belt[i]]++;       //스시벨트 인덱스 하나 증가
    }

    int ans = section_sushi;            //ans에 section_sushi 넣고 반복문에 넣어서 비교
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--;           //스시 벨트 인덱스 줄여서 시작
        if (!sushi[belt[i - k]]) {
            section_sushi--;            //스시 개수 줄이기
        }
        if (!sushi[belt[i % n]]) {      /
            section_sushi++;            //스시 개수 증가
        }
        sushi[belt[i % n]]++;                   //나머지 이용해서 초밥 개수 증가
        ans = max(ans, section_sushi);          //더 큰 값을 저장
    }
    return ans;                                 //ans에 저장된 값 리턴
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {            //메인 함수
    int n, d, k, c;     //정수 선언

    //입력
    cin >> n >> d >> k >> c;    //정수 입력받기
    vector<int> belt(n, 0);     //벡터 선언하고 0으로 초기화
    for (int i = 0; i < n; i++) {   //초밥 종류 입력받아서
        cin >> belt[i];             //belt에 저장
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);      //함수 이용해서 결과 출력하기
    return 0;
}