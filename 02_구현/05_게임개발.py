n, m = map(int, input().split())
x, y, direction = map(int, input().split()) 

# 전체 맵 정보를 입력받기
array = []
for i in range(n) :
    array.append(list(map(int, input().split())))

array[x][y] = 2 # 현재 좌표 방문 처리

# 북, 동, 남, 서 방향 정의
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 왼쪽으로 회전 
def turn_left() :
    global direction
    direction -= 1
    if direction == -1 : # 북쪽이었으면 -1이 될 테니까 3으로(서쪽으로)
        direction = 3

# 시뮬레이션 시작
cnt = 1
turn_time = 0

while True :
    turn_left()
    nx = x + dx[direction]
    ny = y + dy[direction]
    
    # 회전 이후 정면에 가보지 않은 칸이 존재한다면, 이동
    if array[nx][ny] == 0 : 
        array[nx][ny] = 2
        x = nx
        y = ny
        cnt += 1
        turn_time = 0
        continue

    # 회전한 이후에 정면이 가보지 않은 칸이 없거나 바다인 경우
    else :
        turn_time += 1

    # 네 방향 모두 갈 수 없는 경우, 
    if turn_time == 4 :
        nx = x - dx[direction]
        ny = y - dy[direction]
        # 뒤로 갈 수 있으면 뒤로 가기
        if array[nx][ny] == 0 :
            x = nx
            y = ny
            turn_time = 0
        # 뒤로 갈 수 없다면 종료
        else :
            break
print(cnt)


