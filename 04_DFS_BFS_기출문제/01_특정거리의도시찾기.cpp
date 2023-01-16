#include <iostream>
#include <vector>  
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k, x;
vector<int> graph[300001];
int node[300001] = {0};
vector<bool> visited(300001, false);
vector<int> result;

bool BFS() {
    // x노드에서 k번만 BFS 탐색을 수행
    queue<int> q;
    q.push(x);
    visited[x] = true;
    // x에서 x까지 0번 탐색
    node[x] = 0;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        // 탐색이 오래걸리니까 개수 정렬 기법처럼 사용
        int now_cost = node[v];
        
        for (int j = 0; j < graph[v].size(); j++)
        {
            if(visited[graph[v][j]] == true){
                continue;
            }
            q.push(graph[v][j]);
            visited[graph[v][j]] = true;
            // 이번에 q에 추가하는 도시의 번호를 graph[v][j]라 하고, node[graph[v][j]]는 현재 도시에 오는 cost + 1이다. 
            node[graph[v][j]] = now_cost+1;
        }
    }
    for (int i = 0; i < 300001; i++)
    {
        if(node[i] == k){
            result.push_back(i);
        }
    }
    
    return true;    
}

int main(void){

    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }

    if(BFS()){
        if(result.empty()){
            cout << "-1" << "\n";
        }
        else{
            sort(result.begin(), result.end());
            for(auto i : result){
                cout << i << "\n";
            }
        }
    }
    else{
        cout << "-1\n";
    }

    return 0;
}
/*

4 4 2 1
1 2
1 3
2 3
2 4
-> 4

4 3 2 1
1 2
1 3
1 4
-> -1

4 4 1 1
1 2
1 3
2 3
2 4
-> 2, 3

*/