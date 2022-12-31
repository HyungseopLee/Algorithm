#include <iostream>
#include <iomanip> 
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(E)
int n, e;

int main(void) {
    cin >> n >> e;

    // 2차원 배열(그래프 표현)를 만들기
    int** graph = new int*[n+1];

    // 최단 거리 테이블을 모두 무한으로 초기화
    for (int i = 0; i < n+1; i++) {
        graph[i] = new int[n+1];
        fill(graph[i], graph[i] + (n+1), INF);
    }

    // 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == b) graph[a][b] = 0;
        }
    }

    // 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    for (int i = 0; i < e; i++) {
        // A에서 B로 가는 비용은 C라고 설정
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    
    // 점화식에 따라 플로이드 워셜 알고리즘을 수행
    for (int k = 1; k <= n; k++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }

    cout << "-----------\n";
    // 수행된 결과를 출력
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= n; b++) {
            if (graph[a][b] == INF) {
                cout << "INF" << ' ';
            }
            else {
                cout << setw(3) << graph[a][b] << ' '; // 3칸 확보 후 출력
            }
        }
        cout << '\n';
    }

    for (int i = 0; i < n+1; i++) {
        delete[] graph[i];
    }
    delete[] graph;
}

/*

4 7
1 2 4
1 4 6
2 1 3
2 3 7
3 1 5
3 4 4
4 3 2

*/