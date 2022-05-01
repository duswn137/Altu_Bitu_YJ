//
// Created by 고연주 on 2022/05/01.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {       //좋은 수 구하는 함수 작성
    while (left < right) {                                          //left가 더 작을때
        if (left == idx) {                                          //left가 idx랑 같으면
            left++;                                                 //left 증가시키고(오른쪽으로 이동하기)
            continue;                                               //반복문 계속
        }
        if (right == idx) {                                         //right가 idx랑 값이 같으면
            right--;                                                //right 왼쪽으로 이동
            continue;                                               //반복문 계속 진행
        }

        if (num[left] + num[right] == num[idx]) {                   //두 값의 합으로 표현할 수 있는 수가 있으면
            return true;                                            //true
        }
        if (num[left] + num[right] > num[idx]) {                    //두 값의 합이 더 크면
            right--;                                                //right 감소 시키기(값 줄여서 확인하려고)
        } else {                                                    //두 값의 합이 더 작으면
            left++;                                                 //값을 증가시켜서 확인해보기
        }
    }
    return false;                                                       //조건 만족하는게 없으면 false 저장
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {                                        //메인함수
    int n, ans = 0;                                 //정수 입력받고 초기화

    //입력
    cin >> n;                                       //정수 개수 입력받기
    vector<int> num(n, 0);                      //벡터 초기화
    for (int i = 0; i < n; i++) {                   //반복문 이용해서
        cin >> num[i];                              //값 저장하기
    }

    //연산
    sort(num.begin(), num.end());           //입력받은 수 크기대로 정렬하기
    for (int i = 0; i < n; i++) {                       //반복문 이용해서
        if (isGood(num, 0, n - 1, i)) {     //함수 이용해서 좋은 수 몇개인지 구하기
            ans++;                                      //좋은 수 개수 증가시키기
        }
    }

    //출력
    cout << ans;                                        //좋은 수 개수 출력
    return 0;
}