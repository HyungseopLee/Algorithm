n, m = map(int, input().split())

# 방문 위치를 저장하기 위한 맵을 생성하여 0으로 초기화
d = [[0] * m for _ in range(n)]

x, y, direction = map(int, input().split()) 
d[x][y] = 2 # 현재 좌표 방문 처리

# 전체 맴 정보를 입력받기
array = []
for i in range(n) :
    array.append(list(map(int, input().split())))

# 북, 동, 남, 서 방향 정의
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 왼쪽으로 

