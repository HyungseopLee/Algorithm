#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

int n; // map 크기
int k; // 사과 개수
int l; // 뱀의 방향 변환 정보

int head_x = 1, head_y = 1; // head 위치
int map[101][101] = {0}; // map의 뱀 위치 정보, 사과 정보 (뱀은 1, 사과는 2)
char directions[10001] = {0,};
int sec = 0;

// 동, 남, 서, 북 
int dx[4] = {0, 1, 0 , -1};
int dy[4] = {1, 0, -1 , 0};
// 동, 서, 남, 북 에 대한 정보
int dir = 0; 

void turn(char c) {
    // 동 -> 남 -> 서 -> 북
    if (c == 'D'){
        dir = (dir+1) % 4;
    }
    // 동 -> 북 -> 서-> 남 (거꾸로 돈다)
    else{
        dir -= 1;
        if(dir == -1){
            dir = 3;
        }
    }  
}

void solution(){

    queue<pair<int, int>> tail; // 꼬리 정보
    tail.push(make_pair(head_x, head_y));

    while(1) {
        head_x += dx[dir];
        head_y += dy[dir];
        
        sec += 1;
        // 지금 시간에 방향전환 정보가 있다면, 방향을 전환한다
        if(directions[sec] == 'D' || directions[sec] == 'L'){
            turn(directions[sec]);
        }
        // 이동한 곳이 map을 벗어나거나 뱀의 머리가 자신의 몸통에 부딪힌 경우 return
        if(head_x < 1 || head_x > n || head_y < 1 || head_y > n){
            cout << sec;
            break;
        }
        if(map[head_x][head_y] == 1){
            cout << sec;
            break;
        }
        // 이동한 곳에 사과가 있다면
        if(map[head_x][head_y] == 2){
            tail.push(make_pair(head_x, head_y)); // tail queue에 담아둔다. (나중에 tail이 무조건 거쳐야 할 곳이므로)
        }
        // 이동한 곳에 사과가 없다면
        else {
            int last_tail_x = tail.front().first;
            int last_tail_y = tail.front().second;
            tail.pop();
            map[last_tail_x][last_tail_y] = 0; // tail이 있는 곳을 비운다 (뱀이 더이상 위치하는 곳이 아니다)
        }
        map[head_x][head_y] = 1; // 이동한 곳을 뱀이 위치한 곳이란 표시(1)를 해둔다
    }
}

int main(void){
    cin >> n >> k;
    // 뱀 처음 위치 세팅
    map[1][1] = 1;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = 2;
    }
    
    cin >> l;
    // 방향 변환 정보 입력
    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        directions[x] = c;
    }
    solution();

}

/*

6
3
3 4
2 5
5 3
3
3 D
15 L
17 D

*/