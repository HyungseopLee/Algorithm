n = int(input())
arrs = []

for _ in range(n) :
    arrs.append(list(map(int, input().split())))

for i in range(1, n) :
    for j in range(i+1) :
        left = 0
        right = 0
        if j != 0 :
            left = arrs[i-1][j-1]
        if j != i :
            right = arrs[i-1][j]
        arrs[i][j] += max(left, right)

print(max(arrs[n-1]))

'''

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

'''