//
// Created by 고연주 on 2022/05/01.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj_list;   //
vector<int> parent;         //부모 저장할 벡터 선언

void dfs_recursion(int prev, int curr) {    //함수 작성
    if (parent[curr]) { //만약 이번 노드면
        return;         //그냥 리턴
    }
    parent[curr] = prev;    //아니면 이전 노드를 저장하고
    for (int i = 0; i < adj_list[curr].size(); i++) {   //반복문을 이용해서
        dfs_recursion(curr, adj_list[curr][i]); //재귀적으로 반복한다
    }
}

/**
 * [트리의 부모 찾기]
 *
 * 1번 노드에서 출발해서 탐색
 * 루트 노드에서 출발 했기 때문에, 현재 노드의 부모는 이전 노드가 된다.
 */

int main() {        //메인함수
    int n, a, b;    //정수 입력받기

    //입력
    cin >> n;       //몇 개인지 입력받을 정수 선언
    adj_list.assign(n + 1, vector<int>(0));         //어떤 숫자가 있는지 저장할 배열 초기화
    parent.assign(n + 1, 0);                            //부모 노트 저장할 배열 초기화
    for (int i = 1; i < n; i++) {                               //반복문 이용해서
        cin >> a >> b;                                          //값을 입력받는데
        adj_list[a].push_back(b);                               //a번째에 b를 넣고
        adj_list[b].push_back(a);                               //b번째에 a를 넣는다
    }

    //연산
    dfs_recursion(1, 1); //1번 노드는 루트노드이므로, 부모를 자기 자신으로 설정

    //출력
    for (int i = 2; i <= n; i++) {      //반복문 이용해서
        cout << parent[i] << '\n';      //부모 배열에 있는 값 출력한다
    }
    return 0;
}