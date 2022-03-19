//
// Created by 고연주 on 2022/03/19.
//

#include <iostream>
#include <algorithm>
#include <vector>               //리스트 이용하기 위해서
#include <cmath>                //연산 이용하기 위해서

using namespace std;

const int SIZE = 4000; //양수의 최댓값

int findMode(vector<int> &frequency) {      //최빈값 구하는 함수 작성
    int max_value = 0;  //최빈값의 빈도수
    for (int i = 0; i <= SIZE * 2; i++) { //최빈값의 빈도수 구하기
        if (frequency[i] > max_value)       //조건문 이용해서
            max_value = frequency[i];       //max_value보다 더 많이 등장하는 값이 나오면 다시 저장해주기
    }
    //두 번째로 작은 최빈값 구하기
    int cnt = 0;  //최빈값 개수
    int mode = 0; //최빈값
    for (int i = 0; i <= SIZE * 2; i++) {       //조건문 이용해서
        if (frequency[i] == max_value) {        //max_value에 저장된 값과 frequency[i]의 값이 같으면
            mode = i - SIZE; //SIZE를 더한 값으로 인덱스에 저장했었으므로 실제 값은 SIZE를 빼주어야 함
            cnt++;                                  //cnt는 1 증가시켜준다
            if (cnt == 2) //두 번째로 작은 최빈값
                break;
        }
    }

    return mode;                                //최빈값 리턴
}

/**
 * [통계학]
 * 1. 산술 평균 계산 시 실수 자료형 사용, 반올림에 주의
 * 2. n은 홀수 이므로 중앙값은 항상 (n/2)번째 인덱스
 * 3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값
 * 4. 최빈값이 유일한 경우 고려
 */

int main() {                            //메인함수
    int n; //n은 홀수

    //입력
    cin >> n;                               //n 입력받기

    vector<int> num(n);                     //n개의 수가 저장된 num 리스트 생성
    vector<int> frequency(SIZE * 2 + 1, 0); //인덱스는 입력 수 + 4000의 값. 따라서 0 ~ 8000. 각 인덱스에 해당 수가 얼마나 나왔는지 저장

    int sum = 0; //평균 구하기 위한 합 변수
    for (int i = 0; i < n; i++) {               //반복문을 이용해서
        cin >> num[i];                          //num에 입력받은 수 저장하기
        sum += num[i];                          //sum에 입력받은 수를 더해주고 합을 구한다.
        frequency[num[i] + SIZE]++;             //빈도 저장
    }

    //연산
    sort(num.begin(), num.end());       //내장함수 이용해서 정렬

    //출력
    //산술평균
    if (round((double)sum / n) == -0)           //-0이 나오는 경우 제외해주기 위해서
        cout << "0\n";                          //이 경우는 0이 출력되도록 한다
    else                                        //다른 경우는
        cout << round((double)sum / n) << '\n'; //나누어서 계산되는 값을 출력
    cout << num[n / 2] << '\n';               //중앙값
    cout << findMode(frequency) << '\n';      //최빈값
    cout << num[n - 1] - num[0] << '\n';      //범위

    return 0;
}