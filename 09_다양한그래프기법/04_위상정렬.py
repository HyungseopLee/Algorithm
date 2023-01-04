from collections import deque

def topologySort() :
    result = []
    q = deque()
    for i in range(1, v+1) :
        if indegree[i] == 0 :
            q.append(i)
    while q :
        node = q.popleft()
        result.append(node)
        # pop한 node와 연결된 노드의 indegree -1
        for i in graph[node] :
            indegree[i] -= 1
            if indegree[i] == 0 :
                q.append(i)
    for i in result :
        print(i, end=' -> ')

v, e = map(int, input().split())
indegree = [0] * (v + 1)
graph = [[] for i in range(0, v+1)]

for _ in range(e) :
    v1, v2 = map(int, input().split())
    graph[v1].append(v2)
    indegree[v2] += 1

topologySort()

'''

7 8
1 2
1 5
2 3
2 6
3 4
4 7
5 6
6 4

'''
