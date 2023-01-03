#include <iostream>
#include <vector>
#include <queue>
#define INF 9999999

using namespace std;

// n: 도시 개수, m : 경로 개수, c : 송신하는 도시
int n, m, c;

typedef struct node{
    int dist;
    int prev;
    bool done;
}Dijkstra;

vector<pair<int,int>> graph[200001];
Dijkstra* dtable;

void init_dtable() {
    for (int i = 1; i < n+1; i++)
    {
        dtable[i].dist = INF;
        dtable[i].prev = -1;
        dtable[i].done = false;
    }
    
}
struct cmp {
    bool operator() (pair<int, int>& a, pair<int, int>& b) {
        if(a.second < b.second){
            return false;
        }
        return true;
    }
};
void doDijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> min_heap;
    min_heap.push({c, 0});

    while(!min_heap.empty()) {
        int v  = min_heap.top().first;
        int dist = min_heap.top().second;
        min_heap.pop();

        // 이미 처리된 적이 있으면 pass
        if(dtable[v].done == true) {
            continue;
        }
        dtable[v].done = true;
        for (int i = 0; i < graph[v].size(); i++)
        {
            if(dtable[graph[v][i].first].dist > dist + graph[v][i].second) {
                dtable[graph[v][i].first].dist = dist + graph[v][i].second;
                dtable[graph[v][i].first].prev = v;
                min_heap.push({v, dist + graph[v][i].second});
            }
        }
        
    }
    
}

int main(void){

    cin >> n >> m >> c;

    dtable = new Dijkstra[n+1];
    init_dtable();
    
    // 경로 입력받기
    for (int i = 0; i < m; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back({v2, cost});
    }

    doDijkstra();

    int totalCost = 0;
    for (int i = 0; i < graph[c].size(); i++)
    {
        if(totalCost < dtable[graph[c][i].first].dist) {
            totalCost = dtable[graph[c][i].first].dist;
        }
    }
    cout << graph[c].size() << " " << totalCost;

    return 0;
}

/*

3 2 1
1 2 4
1 3 2

*/