#include <iostream>
#define INF 9999999

using namespace std;

int minCost(int** _graph, int _n, int _m, int _x, int _k){

    // 1에서 _k 들렸다가 _x로 가는 최소 비용 구하기
    for (int k = 0; k < _k; k++)
    {
        for (int i = 1; i <= _n; i++)
        {
            for (int j = 1; j <= _n; j++)
            {
                if(_graph[i][j] > _graph[i][k] + _graph[k][j]){
                    _graph[i][j] = _graph[i][k] + _graph[k][j];
                }
            }
        }
    }
    
    if(_graph[1][_k] + _graph[_k][_x] >= INF){
        return -1;
    }
    else {
        return _graph[1][_k] + _graph[_k][_x];
    }

}

int main(void){

    // n : 회사 개수, m : 경로 개수
    int n, m;
    cin >> n >> m;

    int** graph = new int*[n+1];
    for (int i = 0; i < n+1; i++)
    {
        graph[i] = new int[n+1];
        fill(graph[i], graph[i] + (n+1), INF);
    }
    for (int i = 0; i <= n; i++)
    {
        graph[i][i] = 0;
    }
    // 경로 개수만큼 입력받고 graph에 정보 저장하기
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    // x : 물건 판매할 회사, k : 미팅 상대의 회사
    int x, k;
    cin >> x >> k;
    
    // k들렸다가 x로 가는 최소 경로 비용 구하기 (floyd-warshall)
    cout << minCost(graph, n, m, x, k) << endl;

    for (int i = 0; i < n+1; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}

/*

(1)
5 7
1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 5

(2)
4 2
1 3
2 4
3 4

*/