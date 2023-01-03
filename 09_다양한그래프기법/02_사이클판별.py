
def find_parent(parent, data) :
    if parent[data] == data :
        return data
    parent[data] = find_parent(parent, parent[data])
    return parent[data]

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

cycle = False

# 모든 간선을 입력받아 하나씩 확인하며 사이클 판별
for i in range(e) :
    a, b = map(int, input().split())
    if find_parent(parent, a) == find_parent(parent, b) :
        cycle = True
        break
    else :
        union_parent(parent, a, b)

if cycle :
    print("사이클 존재 O")
else :
    print("사이클 존재 X")

'''

3 3
1 2
1 3
2 3

'''