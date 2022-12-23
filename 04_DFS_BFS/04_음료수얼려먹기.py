n, m = map(int, input().split()) 

# 2차원 리스트의 맵 정보 입력 받기
graph = []
for i in range(n) :
    graph.append(list(map(int, input())))

def DFS(x, y) :
    # 주어진 범위를 벗어나는 경우에는 즉시 종료
    if x <= -1 or x >= n or y <= -1 or y >= m :
        return
    # 현재 노드를 아직 방문하지 않았다면
    if graph[x][y] == 0 :
        # 해당 노드 방문 처리
        graph[x][y] = 2
        # 상, 하, 좌, 우 모두 재귀적으로 호출
        DFS(x-1, y)
        DFS(x+1, y)
        DFS(x, y-1)
        DFS(x, y+1)
    else :
        return 

def showMap() :
    print("\n")
    for i in range(n) :
        for j in range(m) :
            print(graph[i][j], end=' ')
        print('\n')
    print("\n")


# 모든 노드에 대하여 음료수 채우기
result = 0
for i in range(n) :
    for j in range(m) :
        # 현재 위치에서 DFS 수행
        if graph[i][j] == 0 :
            result += 1
            DFS(i, j)
            showMap()

print(result)

'''

4 5
00110
00011
11111
00000

15 14
00000111100000
11111101111110
11011101101110
11011101100000
11011111111111
11011111111100
11000000011111
01111111111111
00000000011111
01111111111000
00011111111000
00000001111000
11111111110011
11100011111111
11100011111111


'''