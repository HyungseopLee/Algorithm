#include <iostream>
#include <vector>

#define INF 99999999

using namespace std;

int main(void){

    int n, m;
    cin >> n >> m;

    int graph[101][101];

    // 모두 INF로 초기화
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            graph[i][j] = INF;
        }
        
    }
    for (int i = 0; i < n+1; i++)
    {
        graph[i][i] = 0;
    }
    
    // graph 정보 입력받기 (기존의 간선보다 비용이 적은 간선이 들어올 수 있다)
    for (int i = 0; i < m; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        graph[v1][v2] = min(cost, graph[v1][v2]);
    }
    for (int k = 1; k < n+1; k++)
    {
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
            
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(graph[i][j] >= INF){
                cout << 0 << " ";
            }
            else{
                cout << graph[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
    

    return 0;
}

/*

5
14
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
3 5 10
3 1 8
1 4 2
5 1 7
3 4 2
5 2 4


*/