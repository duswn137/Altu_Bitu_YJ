//
// Created by 고연주 on 2022/04/15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {         //나무 세는 함수
    ll sum = 0;                                     //초기화
    for (int i = 0; i < tree.size(); i++) {         //반복문 이용해서
        if (height >= tree[i]) {                    //높이가 저장된 나무 값보다 큰 경우
            return sum;                             //sum 리턴
        }
        sum += (tree[i] - height);                  //sum=sum+(tree[i]-height)
    }
    return sum;                                     //sum 리턴
}

int upperSearch(int left, int right, int target, vector<int> &tree) {   //높이 최댓값 구하는 함수
    while (left <= right) {                                             //절단기 최소 높이가 가장 큰 나무보다 작을때
        int mid = (left + right) / 2;                                   //mid에 중간값 저장
        ll tree_cnt = cntTree(mid, tree);                        //함수 이용해서 가져갈 수 있는 나무 길이 구하기

        if (tree_cnt >= target) {                                       //만약 가져갈 수 있는 나무 길이가 목표보다 크면
            left = mid + 1;                                             //mid값을 하나 늘려서 저장
        } else {
            right = mid - 1;                                            //반대면 최대 높이 줄이기
        }
    }
    return left - 1;                                                    //저장된 left 값에서 1빼서 리턴
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {                                        //메인함수
    int n, m;                                       //정수선언

    //입력
    cin >> n >> m;                                  //나무 수 ,필요한 나무 길이 입력받기
    vector<int> tree(n, 0);                     //나무 길이 저장할 배열 선언
    for (int i = 0; i < n; i++) {                   //반복문 이용해서
        cin >> tree[i];                             //나무 길이 저장
    }

    sort(tree.begin(), tree.end(), greater<>());    //정렬

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);   //함수 이용해서 최대값 출력
    return 0;
}