//
// Created by 고연주 on 2022/04/12.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findUnmeasurable(vector<int> &weight) {         //측정할 수 없는 무게 구하는 함수 작성
    int sum = 0;                                    //정수 선언 및 초기화

    for (int i = 0; i < weight.size(); i++) {       //무게 배열에 들어있는 사이즈보다 작은 경우 반복문
        if (sum + 1 < weight[i]) {                  //sum+1이 배열에 들어있는 값보다 작을때
            return sum + 1;                         //sum+1 값 리턴
        }
        sum += weight[i];                           //sum에 weight[i]값 더해준다
    }
    return sum + 1;                                 //마지막에 sum+1 리턴
}

/**
 * [저울]
 *
 * 작은 값부터 측정 가능한지 파악해야 하므로, 오름차순으로 정렬한다.
 * 현재 0부터 scope까지 모든 무게를 빠짐없이 측정가능하다고 했을 때, 새로운 무게는 scope + 1보다 작거나 같아야 한다.
 * ex) 현재 1~5까지 측정 가능한데, 다음 값이 7인 경우 -> 6은 측정 불가
 *
 * 만약 이 조건을 만족할 경우, 측정 가능한 범위는 [1, scope + 새로운 무게]로 갱신된다.
 * 모든 저울을 살펴봤는데도 비어있는 값이 없으면, scope + 1 리턴
 */

int main() {                                    //메인함수
    int n;                                      //저울추 개수 입력받을 정수 선언

    //입력
    cin >> n;                                   //정수 입력받기
    vector<int> weight(n, 0);               //배열 선언
    for (int i = 0; i < n; i++) {               //반복문
        cin >> weight[i];                       //값 입력받아서 배열에 저장
    }

    //정렬
    sort(weight.begin(), weight.end());

    //연산 & 출력
    cout << findUnmeasurable(weight);                   //함수 사용해서 값 출력
    return 0;
}