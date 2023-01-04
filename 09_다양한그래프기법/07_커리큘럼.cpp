#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

void topologySort(int* _indegree, int* _time, int* _result, vector<int>* _graph) {

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if(_indegree[i] == 0) {
            cout << i << " ";
            q.push(i);
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < _graph[node].size(); i++)
        {
            // 연결되어 있는 node들의 진입차수를 빼고, 0이 되면 큐에 push
            _indegree[_graph[node][i]] -= 1;
            if(_indegree[_graph[node][i]] == 0) {
                q.push(_graph[node][i]);
            }
            // result 해당 노드를 수강하기까지 최소 시간으로 updtae
            _result[_graph[node][i]] = max(_result[_graph[node][i]], _result[node] + _time[_graph[node][i]]);

        }
    }

}

int main(void){

    cin >> n;

    vector<int>* graph = new vector<int>[n+1];
    int* indegree = new int[n+1];
    int* time = new int[n+1];
    int* result = new int[n+1];

    for (int i = 1; i <= n; i++)
    {   
        // 수강에 걸리는 시간 입력받기
        int time_temp;
        cin >> time_temp;
        time[i] = time_temp;
        result[i] = time_temp;
        indegree[i] = 0;

        // 선수 과목 입력받기, 그래프 입력받기
        while(1){
            int indegree_temp;
            cin >> indegree_temp;
            if(indegree_temp == -1){
                break;
            }
            indegree[i]++; // 진입차수 하나 증가
            graph[indegree_temp].push_back(i);
            // graph[i].push_back(indegree_temp); 이렇게 하면 안된다. 
        }
    }
    
    topologySort(indegree, time, result, graph);

    for (int i = 1; i <= n; i++)
    {
        cout << result[i] << endl;
    }
    
    return 0;
}

/*

5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

*/