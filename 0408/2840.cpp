//
// Created by 고연주 on 2022/04/15.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci;

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {//함수 작성
    string ans = "";                                                 //선언하고 초기화
    int start = arrow_point;                                         //start에 입력받은 arrow_point를 저장한다
    do {                                                            //do-while문 이용
        ans += wheel[arrow_point];                                  //ans에 가리키는 값을 추가한다
        arrow_point = (arrow_point + 1) % n;                        //회전하는거니까 n으로 나눈 나머지 저장
    } while (arrow_point != start);                                 //arrow_point 값과 start값 다를때만 반복문 실행
    return ans;                                                     //ans에 저장된 값 리턴
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) {               //  반복문 이용
        int rot = record[i].first;                          //화살표가 가리키는 문자가 바뀐 숫자를 rot에
        char alpha = record[i].second;                      //화살표가 가리키는 문자를 alpha에 저장
        idx = (idx - rot % n + n) % n;                      //idx에 rot값 이용해서 나머지 계산하여 저장
        if (wheel[idx] == alpha) {                          //값이 같으면
            continue;                                       //계속 반복문 실행
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) {       //값이 존재하지않으면
            return "!";                                             //느낌표 출력
        }
        wheel[idx] = alpha;                                         //wheel[idx]에 alpha 저장하여 다음 반복문 실행
        is_available[alpha - 'A'] = true;                           //기본적으로 true 저장
    }
    return arrowStartWheel(idx, n, wheel);
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {                                                   //메인함수
    int n, k;                                                   //정수 선언

    //입력
    cin >> n >> k;                                              //바퀴 칸수, 돌리는 횟수 입력받기
    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) {                               //반복문 이용해서
        cin >> record[i].first >> record[i].second;             //화살표가 가리키는 글자, 문자 입력받기
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0;
}
