n, m = map(int, input().split())

currencies = []
for i in range(n) :
    currencies.append(int(input()))

dp_table = [10001] * (m + 1)
dp_table[0] = 0

for i in range(n) :
    for j in range(currencies[i], m+1) :
        if dp_table[j - currencies[i]] != 10001 :
            dp_table[j] = min(dp_table[j], dp_table[j - currencies[i]]+1)

if dp_table[m] == 10001 :
    print(-1)
else :
    print(dp_table[m])

'''

2 15
2
3

3 4
3
5
7

'''