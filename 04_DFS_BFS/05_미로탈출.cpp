#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> graph;
deque<pair<int, int>> visited;
int min_move = 1;

void showGraph() {
    cout << endl;
    for(auto i : graph) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void BFS(int x, int y, int n, int m) {

    int nx, ny;

    // 동 서 남 북
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    visited.push_back({x,y}); // 방문 처리

    while(1) { // 목표지점 도달할 때까지 BFS
        x = visited.front().first;
        y = visited.front().second;
        visited.pop_front();

        if(x == n-1 && y == m - 1){
            return;
        } 

        // 동서남북 탐색
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            
            // graph 범위를 벗어나면 continue
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            else {
                // 갈 수 있는 길이라면 (괴물이 없는 부분)
                if(graph[nx][ny] == 1) {
                    cout << "[nx, ny, min_move] : " << nx << " " << ny << " " << graph[x][y] << endl;
                    visited.push_back({nx, ny});
                    graph[nx][ny] = graph[x][y] + 1; // 하나씩 증가
                }
            }
        }
        showGraph(); 
    }
}

int main(void){

    int n, m;
    cin >> n >> m;
    getchar();

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        string user_input;
        getline(cin, user_input);
        for (int j = 0; j < m; j++)
        {
            temp.push_back(user_input[j] - '0');
        }
        graph.push_back(temp);
    }

    BFS(0,0,n,m);
    cout << graph[n-1][m-1]<< endl;


    return 0;
}

/*

5 6
101010
111111
000001
111111
111111

*/