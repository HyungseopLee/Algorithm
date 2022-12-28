def showDP(dp_table) :
    for i in dp_table :
        print(i, end=' ')
    print('n')


n = int(input())
arr = list(map(int, input().split()))

dp_table = [1] * n

# LDS 알고리즘 수행
for i in range(1, n) :
    for j in range(0, i) :
        # 내림차순이 성립하면, DP Table update
        if arr[j] > arr[i] :
            dp_table[i] = max(dp_table[i], dp_table[j] + 1)

showDP(dp_table)

# 열외해야 하는 병사의 최소 수   
print(n - max(dp_table))

'''

7
15 11 4 8 5 2 4

'''