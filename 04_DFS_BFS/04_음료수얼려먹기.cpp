#include <iostream>
#include <vector>

using namespace std;

void showGraph(vector<vector<int>> _graph) {
    cout << endl;
    for (auto& i : _graph)
    {
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    
}

void DFS(vector<vector<int>>& _graph, int _i, int _j){

    // graph가 아닌 곳을 탐색하면 return
    // i(행)을 가리키는 index가 0 미만이거나 n 이상이면 graph 밖을 참조 (_graph.size() --> n)
    // j(열)을 가리키는 index가 0 미만이거나 m 이상이면 잘못된 곳 참조   (_graph[0].size() --> m)
    if(_i < 0 || _i >= _graph.size() || _j <0 || _j >= _graph[0].size()){
        return;
    } 
    
    // 지금 이곳이 0(뚫린 부분)라면 방문 처리
    if(_graph[_i][_j] == 0){
        _graph[_i][_j] = 2;
    }
    else {
        return;
    }

    // 상 방향 탐색
    DFS(_graph, _i - 1, _j);

    // 하 방향 탐색
    DFS(_graph, _i + 1, _j);

    // 좌 방향 탐색
    DFS(_graph, _i , _j - 1);

    // 우 방향 탐색
    DFS(_graph, _i, _j + 1);

}

int main(void){

    int n,m;
    int cnt = 0;
    cin >> n >> m;
    getchar();

    vector<vector<int>> graph;

    // graph를 입력 받는다
    for (int i = 0; i < n; i++)
    {
        vector <int> temp;
        string user_input;
        getline(cin, user_input);
        for (int j = 0; j < m; j++)
        {
            temp.push_back(user_input[j] - '0');
        }
        graph.push_back(temp);
    }
    
    // graph 에서 0인 곳을 찾는다
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // graph에서 0인 부분이 있는데 아지 방문하지 않았다면 그곳에 가서 주변을 DFS
            if(graph[i][j] == 0) { 
                cnt++;
                // 해당 vertex에서 DFS를 진행하여 서로 연결되어 있는 부분 graph를 모두 방문 처리
                DFS(graph, i, j);
                showGraph(graph);
            }
        }
    }
    
    cout << cnt << endl;

    return 0;
}

/*

4 5
00110
00011
11111
00000

15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111

*/