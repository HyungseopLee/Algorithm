INF = int(1e9)

# n : 회사 개수, m : 경로 개수
n, m = map(int, input().split())

graph = [[INF] * (n+1) for _ in range(n+1)]

# 자기 자신으로 가는 비용은 0으로 초기화
for i in range(n+1) :
    graph[i][i] = 0

for _ in range(m) :
    v1, v2 = map(int, input().split())
    graph[v1][v2] = 1
    graph[v2][v1] = 1


# x : 물건 판매할 회사, k : 미팅 상대의 회사
x, k = map(int, input().split())

for _k in range(1, k+1) :
    for i in range(1, n+1) :
        for j in range(1, n+1) :
            graph[i][j] = min(graph[i][j], graph[i][_k] + graph[_k][j])

min_cost = graph[1][k] + graph[k][x]
if min_cost >= INF :
    print(-1)
else :
    print(min_cost)



'''

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

'''