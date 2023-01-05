#include <iostream>
#include <vector>
#define INF 1e9 // 10^9 == 10억 == 무한을 의미

using namespace std;

typedef struct dijkstra{
    // 최단 거리 table 
    int dist;
    // 거쳐온 직전 노드를 저장
    int prev;
    // 방문한 적이 있는지 체크
    bool visited;

}Dijkstra;

// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int>> graph[100001];

// 노드 개수(n), 간선 개수(m), 시작 노드 번호(startv)
// 노드의 최대 개수는 최대 100,000라고 가정
int n, m, startv;

void init_dtable(Dijkstra* _dtable){
    for (int i = 1; i <= n; i++)
    {
        _dtable[i].dist = 99;
        _dtable[i].prev = -1;
        _dtable[i].visited = false;
    }
}


int getSmallestNode(Dijkstra* _dtable) {
    int min = INF;
    int ret = -1;
    for (int i = 1; i <= n; i++)
    {
        if(_dtable[i].dist < min && _dtable[i].visited == false){
            min = _dtable[i].dist;
            ret = i; // 최단 거리가 가장 짧은 노드의 인덱스 반환
        }
    }
    return ret;
}

void dijkstra(Dijkstra* _dtable) {
    // 시작 노드 초기화
    _dtable[startv].dist = 0;
    _dtable[startv].prev = startv;
    _dtable[startv].visited = true;

    // 시작 노드와 연결된 노드들을 최단 거리 테이블에 update
    for (int i = 0; i < graph[startv].size(); i++)
    {
        // graph[startv][i].first : startv와 연결된 노드
        // graph[startv][i].second : startv와 연결된 노드까지 cost
        _dtable[graph[startv][i].first].dist = graph[startv][i].second;
        _dtable[graph[startv][i].first].prev = startv;
    }

    while(1){
        // 현재 최단 거리가 가장 짧은 노드를 꺼내옴.
        int now = getSmallestNode(_dtable);
        // 최단 거리를 다 구했으면 종료
        if(now == -1){
            break;
        }
        _dtable[now].visited = true;

        // 현재 노드와 연결된 다른 노드들 update
        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = _dtable[now].dist + graph[now][i].second;
            if(cost < _dtable[graph[now][i].first].dist) {
                _dtable[graph[now][i].first].dist = cost;
                _dtable[graph[now][i].first].prev = now;
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

    cin >> n >> m >> startv;

    Dijkstra* dtable = new Dijkstra[n+1];
    init_dtable(dtable);

    // 모든 간선 정보 입력받기
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // nodeA에서 nodeB로 가는 비용 C
        graph[a].push_back({b,c});
    }

    dijkstra(dtable);

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