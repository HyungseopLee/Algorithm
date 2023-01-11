#include <iostream>
#include <vector>
#define INF 10000001

using namespace std;

typedef struct ford { 
    long long dist;
    int prev;
}FORD;

int n, m, startv = 1;

void init_dtable(FORD* dtable){
    for (int i = 0; i < n+1; i++)
    {
        dtable[i].dist = INF;
        dtable[i].prev = -1;
    }
    
}

bool doFord(vector<pair<pair<long, long>, int>> edges ,FORD* dtable) {

    dtable[startv].dist = 0; 
    
    for (int i = 1; i <= n+1; i++)
    {
        // 모든 간선을 각각 확인하며 dtable update
        for (int j = 0; j < m; j++)
        {
            int current_node = edges[j].first.first;
            int next_node = edges[j].first.second;
            int cost = edges[j].second;

            if(dtable[current_node].dist != INF && dtable[next_node].dist > dtable[current_node].dist + cost) {
                dtable[next_node].dist = dtable[current_node].dist + cost;
                dtable[next_node].prev = current_node;
                // n+1번째 수행했을 때, update가 발생했다면 음수 사이클이 존재한다
                if(i == n+1){
                    return true;
                }
            }
        }
    }
    // 음수 사이클이 존재하지 않는다
    return false;
    
}

int main(void){

    cin >> n >> m;
    
    // 사이클로 인하여 int형을 벗어날 수 있기 떄문에 long long형으로 선언한다
    // int로 선언하면 출력초과 판정
    vector<pair<pair<long, long>, int>> edges;
    FORD* dtable = new FORD[n+1];

    init_dtable(dtable);    

    // 간선 m개 입력받기
    for (int i = 0; i < m; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        // v1 -> v2  cost비용
        edges.push_back({{v1, v2},cost});
    }
    
    bool negative_cycle = doFord(edges, dtable);
    if(negative_cycle){
        cout << "-1\n";
    }
    else {
        for (int i = 2; i <= n; i++)
        {
            if(dtable[i].dist >= INF){
                cout << "-1\n";
            }
            else {
                cout << dtable[i].dist << '\n';
            }
        }
        
    }

    return 0;
}

/*

(1)
3 4
1 2 4
1 3 3
2 3 -1
3 1 -2

(2)
3 4
1 2 4
1 3 3
2 3 -4
3 1 -2

(3)
3 2
1 2 4
1 2 3

*/