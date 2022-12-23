#DFS function
def DFS(_graph, _v, _visited) :
    # 현재 노드를 방문 처리
    _visited[_v] = True
    print(_v, end = ' -> ')
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in _graph[_v] :
        if not _visited[i] :
            DFS(_graph, i, _visited)


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

DFS(graph, 1, visited)