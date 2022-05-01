#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

vector<vector<int>> board, visited;     //이차원배열 선언
queue<ci> countries;


//각 연합의 인구 수만큼 인구 이동하는 함수
void movePeople(int population, vector<ci> &union_cord) {
    for (int i = 0; i < union_cord.size(); i++) {   //연합 개수보다 작은 i에 대해 반복문
        int row = union_cord[i].first, col = union_cord[i].second;  //행과 열의 값 저장
        board[row][col] = population;   //위치마다 인구 수 저장
        countries.push({row, col}); //인구 이동이 있는 나라는 다음에도 인구 이동 가능성 있음
    }
}

bool bfs(int n, int l, int r, int cr, int cc, int day) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<ci> union_cord; //연합 저장할 벡터
    union_cord.push_back({cr, cc}); //벡터에 값 추가
    queue<ci> q;    //큐 선언
    q.push({cr, cc});   //큐에 값 추가
    int sum = board[cr][cc], cnt = 1;   //sum에 값 저장하고 cnt는 1로 초기화
    while (!q.empty()) {    //q에 값이 있으면
        cr = q.front().first;   //q의 첫 번째 값을 cr에 저장
        cc = q.front().second;  //q의 두 번째 값은 cc에 저장
        q.pop();    //q의 앞의 값 삭제

        for (int i = 0; i < 4; i++) {   //반복문 사용해서
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] == day) {
                continue;
            }
            int diff = abs(board[nr][nc] - board[cr][cc]);  //차 구해서 저장
            if (diff >= l && diff <= r) { //국경선 열림
                q.push({nr, nc});   //q에 값 저장
                visited[nr][nc] = day;  
                union_cord.push_back({nr, nc}); //연합에 추가
                sum += board[nr][nc];   //sum=sum+board[nr][nc]
                cnt++;      //cnt 증가시킨다
            }
        }
    }
    if (cnt > 1) { //연합이 생겼다면
        movePeople(sum / cnt, union_cord); //인구 이동
        return true;    //boolean 값 true
    }
    return false;       //boolean 값 false
}

int simulation(int n, int l, int r) {   //정답 구할 함수 작성
    int day = 0; //방문 체크로도 사용
    while (true) {  //반복문
        day++;  //인구이동하는 일수 증가시키기
        bool is_move = false; //인구 이동 했는지 체크
        int size = countries.size(); //이번 시간에 탐색할 수 있는 나라의 수
        while (size--) {
            int row = countries.front().first;
            int col = countries.front().second;
            countries.pop();
            if (visited[row][col] == day) { //이미 탐색한 나라라면
                continue;
            }
            visited[row][col] = day;
            if (bfs(n, l, r, row, col, day)) {
                is_move = true;
            }
        }
        if (!is_move) { //불가능한 경우에는
            return day - 1; //-1을 출력한다
        }
    }
}

/**
 * [인구 이동]
 *
 * 0. 인구이동이 일어날 수 있는 나라(처음에는 모든 나라)의 좌표를 좌표 큐에 저장
 * 1. bfs 탐색을 통해 연합을 확인하고, 연합에 포함된 나라의 인구이동을 진행한다.
 * 2. 인구 이동이 있었던 나라는 다음 날에도 인구이동이 시작될 수 있으므로 좌표 큐에 다시 넣어준다.
 *    -> 직전 이동이 있었던 나라에 대해서만 bfs 탐색 진행
 *    - 인구 이동이 일어나지 않은 두 나라 사이에서는 다음 날에도 인구이동이 일어날 수 없음
 * 3. 인구이동이 전혀 일어나지 않을 때까지 반복
 */

int main() {    //메인함수
    int n, l, r;        //정수 선언

    //입력
    cin >> n >> l >> r; //값 입력받기
    board.assign(n, vector<int>(n, 0));         //배열 선언
    visited.assign(n, vector<int>(n, 0));       //방문한
    for (int i = 0; i < n; i++) {       //반복문 이용해서 인구수 입력받기
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];         // 각 나라의 인구수 입력받기
            countries.push({i, j});     //countries에 값 저장하기
        }
    }

    //연산 & 출력
    cout << simulation(n, l, r);        //함수 이용해서 인구이동에 걸리는 일수 출력
    return 0;
}
