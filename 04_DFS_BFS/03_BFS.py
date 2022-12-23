from collections import deque

#BFS function
def BFS(_graph, _start, _visited) :
    queue =  deque([_start])
    # 현재 노드를 방문 처리
    _visited[_start] = True

    # 큐가 빌 때까지 반복
    while queue :
        # 큐에서 하나의 원소를 뽑아 출력
        v = queue.popleft()
        print(v, end= ' -> ')
        # 아직 방문하지 않은 인접 정점들 큐에 삽입
        for i in _graph[v] :
            if not _visited[i] :
                queue.append(i)
                _visited[i] = True


# 인접 리스트로 graph 표현
graph = [
    [],        # vertex0 (시작 정점 번호가 1이니까 0번째 index는 비워둔다)
    [2, 3, 8], # vertex1 (1번 노드와 연결된 노드는 2, 3, 8이다)
    [1, 7],    # vertex2
    [1, 4, 5], # vertex3
    [3, 5],    # vertex4
    [3, 4],    # vertex5
    [7],       # vertex6
    [2, 6, 8], # vertex7
    [1, 7],    # vertex8
]

# 방문 처리를 위한 visited list
visited = [False] * 9 

BFS(graph, 1, visited)