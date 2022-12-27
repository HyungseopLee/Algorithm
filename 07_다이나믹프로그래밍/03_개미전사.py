n = int(input())

warehouse = list(map(int, input().split()))

dp_table = [0] * 100

dp_table[0] = warehouse[0]
dp_table[1] = max(warehouse[0], warehouse[1])

for i in range(2, n) :
    dp_table[i] = max(dp_table[i-1], dp_table[i-2] + warehouse[i])

print(dp_table[n-1])