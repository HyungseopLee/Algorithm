# 더 효율적인 방법
# 수학적인 방법으로 첫번째로 큰수가 등장한 횟수, 두번쨰로 큰수가 등장한 횟수를 구한다.

n, m, k = map(int, input().split())

data = list(map(int, input().split()))

data.sort()
first = data[n - 1]
second = data[n - 2]

# 첫번째로 큰 수가 더해지는 횟수
cnt = int(m / (k+1)) * k 
cnt += m % (k + 1) # m/(k+1)이 나누어 떨어지지 않은 경우

result = 0
result += (cnt) * first
result += (m - cnt) * second

print(result)
