def find_parent(parent, data) :
    if parent[data] != data :
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
parent = [0] * (v+1)
edges = []
result = 0

for i in range(1, v+1) :
    parent[i] = i

# 모든 간선 입력받기
for _ in range(e) :
    v1, v2, cost = map(int, input().split())
    edges.append((cost, v1, v2))

# 간선의 비용순으로 정렬 
edges.sort()

# 정렬된 간선들을 하나씩 확인하며 사이클이 발생하지 않는 경우에만 MST에 포함
for i in edges :
    cost, a, b = i
    if find_parent(parent, a) == find_parent(parent, b) :
        continue
    else :
        union_parent(parent, a, b)
        print(str(a)+"---"+str(b))
        result += cost

print("total cost : "+str(result))



'''

7 9
1 2 29
1 5 75
2 3 35
2 6 34
3 4 7
4 6 23
4 7 13
5 6 53
6 7 25

'''