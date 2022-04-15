//
// Created by 고연주 on 2022/04/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int childNum(int len, vector<int> &snacks) {
    int cnt = 0;                //정수 선언 및 초기화
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) { //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break;              //반복문 중단
        }
        cnt += (snacks[i] / len);       //cnt=cnt+(snacks[i]/len)
    }

    return cnt;                         //cnt값 리턴
}

int upperSearch(int left, int right, int target, vector<int> &snacks) {
    while (left <= right) {
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(mid, snacks); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1;
        } else {
            right = mid - 1;    //아닌 경우 mid-1을 right에 저장
        }
    }
    return left - 1;                //계산한 이후 전 단계인 left-1 리턴
}

/**
 * [과자 나눠주기]
 *
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {                        //메인함수
    int m, n, left = 1, right = 0;  //정수 선언 및 초기화

    //입력
    cin >> m >> n;              //조카 수 입력받기, 과자 길이 개수 입력받기
    vector<int> snacks(n, 0);   //과자 길이 저장할 배열 선언
    for (int i = 0; i < n; i++) {   //반복문 이용해서
        cin >> snacks[i];           //과자길이 저장
    }

    //연산
    sort(snacks.begin(), snacks.end()); //배열 정렬
    right = snacks[n - 1];                        //과자길이 최댓값 저장

    //연산 & 출력
    cout << upperSearch(left, right, m, snacks);
    return 0;
}