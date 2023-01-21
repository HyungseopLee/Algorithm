from itertools import combinations
import copy

# 1. 0인 부분을 리스트에 담는다
# 2. 3개 조합을 모두 만든다
# 3. 각각의 조합에 대해서 
# 4. 모든 바이러스(2)를 DFS 탐색하면서 거쳐간 곳을, virus(2)로 전파시킨다
# 5. 4. 과정을 마친 후 0의 개수를 반환한다.
# 6. 반환된 0의 개수 중 최대값을 출력한다.

def DFS(temp, x, y) :
    for i in range(4) :
        nx = x + dx[i]
        ny = y + dy[i]
        # 범위 안에서
        if nx >= 0 and nx < n and ny >= 0 and ny < m :
            # virus(2)와 0인 곳이 이어져있다면 virus(2)로 전파시킨다
            if temp[nx][ny] == 0 :
                temp[nx][ny] = 2
                DFS(temp, nx, ny)
            
def virusDFS() :
    global original
    temp = copy.deepcopy(original) # 값만 복사해준다.
    local_result = 0
    for i in range(n) :
        for j in range(m) :
            # virus가 있는 곳만 DFS 탐색 시작.
            if original[i][j] == 2:
                DFS(temp, i ,j)
    for i in range(n) :
        for j in range(m) :
            # virus 전파가 끝나고 난 뒤 남아있는 안전구역(0) 개수를 반환
            if temp[i][j] == 0 :
                local_result += 1
    return local_result
    

n, m = map(int,input().split())
zero_area = []
two_area = [] # virus가 존재하는 곳
all_zero_combinations = []
original = [] # original map
visited = [] 

# 상하좌우 이동할 리스트
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# original map 입력받기
for _ in range(n) :
    original.append(list(map(int, input().split())))

# 0인 곳의 index들을 리스트에 담아두기 -> 3개 조합을 만들기 위해
# 2인 곳의 index들을 리스트에 담아두기 -> 바이러스가 위치하는 곳을 기억하기 위해서
for i in range(n):
    for j in range(m):
        if original[i][j] == 0 :
            zero_area.append(i*10 + j)
        if original[i][j] == 2 :
            two_area.append((i, j))

result = 0

# 각각의 조합들을 DFS 탐색한 후 0의 개수가 최대인 것을 출력
for i in combinations(zero_area, 3) :
    # 0인 곳에 벽(1)을 설치
    original[i[0]//10][i[0]%10] = 1
    original[i[1]//10][i[1]%10] = 1
    original[i[2]//10][i[2]%10] = 1

    # virus 전파 후, 남은 0의 개수의 최대값을 result에 update
    result = max(result, virusDFS())

    # 원래대로 되돌려 놓음 0으로..
    original[i[0]//10][i[0]%10] = 0
    original[i[1]//10][i[1]%10] = 0
    original[i[2]//10][i[2]%10] = 0

print(result)

'''

7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
-> 27

'''
