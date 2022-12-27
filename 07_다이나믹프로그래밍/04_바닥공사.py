n = int(input())

dp_table = [0] * (n+1)

dp_table[1] = 1
dp_table[2] = 3

for i in range(3, n+1) :
    dp_table[i] = (dp_table[i-1] + 2*dp_table[i-2]) % 796796

print(dp_table[n])