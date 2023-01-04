#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;

void topologySort(vector<int>* _graph, int* _indegree) {
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= v; i++)
    {
        if(_indegree[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int i = 0; i < _graph[node].size(); i++)
        {
            _indegree[_graph[node][i]] -= 1;
            if(_indegree[_graph[node][i]] == 0) {
                q.push(_graph[node][i]);
            }
        }
    }

    for(auto i : result) {
        cout << i << " -> ";
    }
    
}

int main(void){

    cin >> v >> e;

    int* indegree = new int[v+1];
    vector<int>* graph = new vector<int>[v+1];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        indegree[v2] += 1;
    }
    
    topologySort(graph, indegree);

    return 0;
}

/*

7 8
1 2
1 5
2 3
2 6
3 4
4 7
5 6
6 4

*/