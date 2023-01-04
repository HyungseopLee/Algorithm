
def findFamily(family, data) :
    if family[data] != data :
        family[data] = findFamily(family, family[data])
    return family[data]

def beFamily(family, h1, h2) :
    h1_family = findFamily(family, h1)
    h2_family = findFamily(family, h2)
    if h1_family < h2_family :
        family[h2_family] = h1_family
    else :
        family[h1_family] = h2_family

n, m = map(int, input().split())
family = [0] * (n+1)

edges = []
result = 0

for i in range(1, n+1) :
    family[i] = i

for _ in range(m) :
    h1, h2, cost = map(int ,input().split())
    edges.append((cost, h1, h2))

edges.sort() 
last_cost = 0

for edge in edges :
    cost, h1, h2 = edge
    if findFamily(family, h1) != findFamily(family,h2) :
        beFamily(family, h1, h2)
        result += cost
        last_cost = cost

print(result - last_cost) 

'''

7 12
1 2 3
1 3 2
3 2 1
2 5 2
3 4 4
7 3 6
5 1 5
1 6 2
6 4 1
6 5 3
4 5 3
6 7 4

'''