//
// Created by 고연주 on 2022/05/01.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> possibleWeight(int left, int right, int g) {    //함수 작성
    vector<int> ans;                                        //벡터 선언
    while (left < right) {                                  //right가 더 큰 경우
        int diff = right * right - left * left;             //diff에 제곱수 차이 저장

        if (diff <= g) {                                    //diff값이 g보다 작거나 같으면
            if (diff == g) {                                //같으면
                ans.push_back(right);                       //벡터에 저장
            }
            right++;                                        //right 값 증가
        } else {                                            //반대의 경우
            left++;                                         //left값을 증가시킨다
        }
    }
    return ans;                                             //ans 값 리턴
}

/**
 * [다이어트]
 *
 * left: 성원이가 기억하고 있던 몸무게
 * right: 성원이의 현재 몸무게
 *
 * 같은 위치에서 시작해서 점점 증가하는 투 포인터로 풀이
 * 대신, left ~ right를 모두 고려하는 것이 아니라 left, right 포인터 값 자체만 고려
 *
 * !주의! 몸무게의 범위가 딱히 정해져 있지 않으므로, 종료 조건을 잘 세우는 것이 중요!
 *       -> 두 몸무게가 같아지는 순간 종료!
 *       -> left가 right와 같은 값을 가진다면, 직전 상황은 두 몸무게가 1차이 나는 상황
 *       -> 이때 몸무게 차이가 g 이상이었다는 것은 이후로 나올 수 있는 차이는 무조건 g이상이 된다. (제곱수의 간격은 수가 커질수록 늘어나기 때문)
 */

int main() {                                    //메인함수
    int g;                                      //g 선언

    //입력
    cin >> g;                                   //g입력받기

    //연산
    vector<int> ans = possibleWeight(1, 2, g);      //함수 이용해서 벡터에 저장

    //출력
    if (!ans.size()) {                      //만약 값이 존재하지 않으면
        cout << "-1";                       //-1 출력
        return 0;
    }
    for (int i = 0; i < ans.size(); i++) {      //값이 존재하면
        cout << ans[i] << '\n';                 //배열에 있는 값 출력
    }
    return 0;
}