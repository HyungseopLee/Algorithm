#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

typedef struct dijkstra {
    int dist;
    int prev;
    bool done;
}Dijkstra;

typedef pair<int, int> pair_ii;

// 노드의 개수(n), 간선의 개수(e), 시작 노드
int n, e, startv;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair_ii> graph[100001];

// 두번째 원소(거리) 기준으로 min heap
struct cmp {
    bool operator() (pair_ii& _a, pair_ii& _b) {
        if(_a.second < _b.second){
            return false;
        }
        return true;
    }
};

void init_dtable(Dijkstra* _dtable){
    // node가 1부터 시작하니까  1~n
    for (int i = 1; i <= n; i++)
    {
        _dtable[i].dist = INF;
        _dtable[i].prev = -1;
        _dtable[i].done = false;
    }
}

void doDijkstra(Dijkstra* _dtable) {
    // <노드, 거리> 쌍을 값으로 갖는 priorityQ 생성
    // 두번째 인자(거리정보) 기준으로 min heap(오름차순)
    priority_queue<pair_ii, vector<pair_ii>, cmp> pq;

    // 시작 노드로 가기 위한 최단 경로 0을 priortyQ에 push
    pq.push({startv, 0});
    _dtable[startv].dist = 0;

    // cout << "test" << endl;

    // pq가 빌 때까지 실행
    while(!pq.empty()){
        // 가장 최단 거리가 짧은 노드에 대한 <노드, 거리> 정보 pop
        int node = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        // pop한 node가 이미 처리된 적이 있다면 무시
        if(_dtable[node].done == true) {
            continue;
        }
        // 현재 노드와 연결된 다른 인접한 노드들 확인
        _dtable[node].done = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            int cost = distance + graph[node][i].second;
            // 현재 노드를 거쳐서, 다른 노드로 이동하는 거리가 더 짧은 경우 update
            if(cost < _dtable[graph[node][i].first].dist) {
                _dtable[graph[node][i].first].dist = cost;
                _dtable[graph[node][i].first].prev = node;
                pq.push(make_pair(graph[node][i].first, cost));
            }
        }
        
    }
}

void showMap(Dijkstra* _dtable, int _startv, int _endv){
    int current = _endv;

    while(current != _startv){
        cout << current << " <- ";
        current = _dtable[current].prev;
    }
    cout << current;
}

int main(void){

    cin >> n >> e >> startv;

    Dijkstra* dtable = new Dijkstra[n+1];
    init_dtable(dtable);

    // 모든 간선 정보를 입력받기
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미
        graph[a].push_back({b, c});
    }

    doDijkstra(dtable);

    // 모든 노드로 가기 위한 최단 거리 출력
    for (int i = 1; i <= n; i++)
    {
        if(dtable[i].dist == INF){
            cout << "INF" << endl;
        }
        else {
            cout << dtable[i].dist << " ";
        }
    }
    cout << endl;

    // node1에서 node6까지 가는 최단 경로
    showMap(dtable, startv, 6); 

    return 0;
}

/*

6 11
1
1 2 2
1 3 5
1 4 1
2 3 3
2 4 2
3 2 3
3 6 4
4 3 3
4 5 1
5 3 1
5 6 2

*/