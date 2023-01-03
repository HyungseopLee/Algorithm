import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

def doDijkstra(startv) :
    q = []
    heapq.heappush(q, (startv, 0))
    dtable[startv] = 0

    while q :
        v, d = heapq.heappop(q)
        if dtable[v] < d :
            continue
        for i in graph[v] :
            cost = d + i[1]
            if cost < dtable[i[0]] :
                dtable[i[0]] = cost
                heapq.heappush(q, (i[0], cost))


n, m, c = map(int, input().split())
graph = [[] for i in range (n+1)]
dtable = [INF] * (n+1)

for _ in range(m) :
    v1, v2, cost = map(int, input().split())
    graph[v1].append((v2, cost))

doDijkstra(c)

count, total_cost = 0, 0
for i in dtable :
    if i != INF :
        count += 1
        total_cost = max(total_cost, i)

print(count-1, end=" ") # 시작 노드 제외 -1
print(total_cost)

'''

3 2 1
1 2 4
1 3 2

'''