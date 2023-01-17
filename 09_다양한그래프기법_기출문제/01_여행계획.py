def findParent( data) :
    global parent
    if data != parent[data] :
        parent[data] = findParent( parent[data])
    return parent[data]

def unionParent( a, b) :
    pa = findParent( a)
    pb = findParent( b)
    global parent
    if pa < pb :
        parent[b] = pa
    else :
        parent[a] = pb

n, m = map(int, input().split())
parent = [0] * (n+1)

# 부모 테이블 생성
for i in range(1, n+1):
    parent[i] = i

# Union 연산 수행
for i in range(n) :
    data = list(map(int, input().split()))
    for j in range(n) :
        if data[j] == 1 :
            unionParent( i+1, j+1)

# 여행 계획 입력 받기
plan = list(map(int, input().split()))

flag = True

for i in range(m-1) :
    if findParent( plan[i]) != findParent( plan[i+1]) :
        flag = False
        break

if flag :
    print("YES")
else :
    print("NO")

'''

5 4
0 1 0 1 1
1 0 1 1 0
0 1 0 0 0
1 1 0 0 0
1 0 0 0 0
2 3 4 3

'''