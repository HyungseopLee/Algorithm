#include <iostream>
#include <vector>

#define INF 1000000

using namespace std;

int main(void){

    int n, m;

    cin >> n >> m;

    int graph[501][501]= {INF};
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            graph[i][j] = INF;
            if(i==j) {
                graph[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int stu1, stu2;
        cin >> stu1 >> stu2;
        graph[stu1][stu2] = 1;
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

    int result = 0;
    for (int i = 1; i < n+1; i++)
    {
        int cnt = 0;
        for (int j = 1; j < n+1; j++)
        {
            if(j == i){
                continue;
            }
            // i에서 j로 도달 가능하거나 j에서 i로 도달 가능한 경우 --> 이것이 n-1만큼 (자신 제외)
            if(graph[i][j] != INF || graph[j][i] != INF){
                cnt += 1;
            }
        }
        // 자기 자신을 제외하고 나머지에 모두 도달 가능하다면
        if(cnt == n-1){
            result += 1;
        }
    }
    cout << result;

    return 0;
}

/*

6 6
1 5
3 4
4 2
4 6
5 2
5 4
-> 1 (4번 학생만 자신의 등수를 알 수 있다)
*/