//
// Created by 고연주 on 2022/03/11.
//

#include <iostream>     //  기본적으로 필요
#include <vector>       //  배열 사용하려고
#include <algorithm>    //  sort 함수 사용하려고

using namespace std;    //  std 클래스 사용 선언

long long calTip(int n, vector<int> &tips) {     //  팁 계산 함수
    long long ans = 0;                          // 팁 최댓값이 int 범위를 넘어서 long long 사용
    for (int i = 0; i < n; i++) {               //반복문
        int cur_tip = tips[i] - i;              // 현재 팁 계산
        if (cur_tip < 0) //음수면 팁에 더하지 않는데 처음에 내림차순 정렬했으므로 아예 break
            break;
        ans += cur_tip;                         //ans에 각각의 팁 더해준다
    }
    return ans;                                 //ans 리턴
}

/**
 * 강호가 받을 수 있는 팁이 최댓값이 되려면 팁이 많은 사람의 순위가 높아야함
 * !주의! 주어지는 N의 최대 크기가 100,000이고 팁의 최대 크기가 100,000이므로
 *       정답의 최댓값은 10^5 * (10^5+1) / 2로 int 범위를 넘기 때문에 long long 을 써야 함
 */

int main() {                        //  메인함수
    int n;                          //  n선언

    //입력
    cin >> n;                       //n 입력받기
    vector<int> tips(n, 0);      // tips 배열
    for (int i = 0; i < n; i++) {   //  반복문
        cin >> tips[i];             //입력받은 값을 tips에 순차적으로 저장
    }
    //연산
    sort(tips.begin(), tips.end(), greater<>()); //내림차순 정렬
    //출력
    cout << calTip(n, tips) << '\n';        //  calTip 함수 이용해서 tips 출력
    return 0;
}