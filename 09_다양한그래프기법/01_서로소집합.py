# 조상 root를 찾을 때까지 재귀적으로 호출 + 
# 찾으러 가기 직전에 부모 테이블에 루트 노드를 update시키며 경로 압축
def find_parent(parent, data) :
    if parent[data] == data :
        return data
    parent[data] = find_parent(parent, parent[data])
    return parent[data]

# union 연산 수행
def union_parent(parent, a, b) :
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b :
        parent[b] = a
    else :
        parent[a] = b

# 노드 개수 : v, 간선 개수 : e
v, e = map(int, input().split())

# 부모 테이블 초기화
parent = [0] * (v+1)
for i in range(1, v+1) :
    parent[i] = i

# union 연산을 입력받아 수행
for i in range(e) :
    a, b = map(int, input().split())
    union_parent(parent, a, b)

print("[각 원소가 속한 집합] ", end= " ")
for i in range(1, v+1) :
    print(find_parent(parent, i), end=" ")

print("")
print("[부모 테이블 출력] ", end= " ")
for i in range(1, v+1) :
    print(parent[i], end=" ")

'''

6 4
1 4
2 3
2 4
5 6

'''