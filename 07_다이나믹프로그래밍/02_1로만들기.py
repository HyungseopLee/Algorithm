x = int(input())

dp_table = [0] * (x+1)

for i in range(2, x+1) :
    # 현재의 수에서 1을 빼는 경우
    dp_table[i] = dp_table[i - 1] + 1
    # 현재의 수가 2로 나누어 떨어지는 경우
    if i % 2 == 0 :
        dp_table[i] = min(dp_table[i], dp_table[i//2] + 1)
    # 현재의 수가 3로 나누어 떨어지는 경우
    if i % 3 == 0 :
        dp_table[i] = min(dp_table[i], dp_table[i//3] + 1)
    # 현재의 수가 5로 나누어 떨어지는 경우
    if i % 5 == 0 :
        dp_table[i] = min(dp_table[i], dp_table[i//5] + 1)

print(dp_table[x])