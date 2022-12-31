import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(startv) :
    q = []
    # 시작 노드로 가기 위한 최단 경로는 0으로 설정, 큐에 삽입
    heapq.heappush(q, (0, startv))
    dist_table[startv] = 0

    while q :
        # 최단 거리가 짧은 노드 꺼내기
        dist, node = heapq.heappop(q)
        # 현재 노드가 이미 처리된 적이 있는 노드라면 무시
        if dist_table[node] < dist :
            continue
            
        # 현재 노드와 연결된 다른 인접한 노드들을 확인
        for i in graph[node] :
            cost = dist + i[1]
            if cost < dist_table[i[0]] :
                dist_table[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


# 노드의 개수(n), 간선의 개수(e)를 입력받기
n, e = map(int,input().split())
# 시작 노드 번호를 입력받기
startv = int(input())
# 각 노드에 연결되어 있는 노드에 대한 정보를 담는 리스트
graph = [[] for i in range(n+1)]
# 최단 거리 테이블을 모두 무한으로 초기화
dist_table = [INF] * (n+1)

# 모든 간선 정보를 입력받기
for _ in range(e) :
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

dijkstra(startv)

# 모든 노드로 가기 위한 최단 거리 출력
for i in range(1, n+1) :
    if dist_table[i] == INF:
        print("INF")
    else :
        print(dist_table[i], end=" ")



'''

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

'''