n, m, k = map(int, input().split())

data = list(map(int, input().split()))

data.sort()
first = data[n - 1]
second = data[n - 2]

result = 0

while True :
    for i in range(k) : # 1. 가장 큰 수를 k번 더한다
        if m == 0 :
            break
        result += first
        m -= 1
        
    if m == 0 :
        break

    result += second # k번 가장 큰 수를 더한 후, 두번째로 가장 큰 수를 더한다
    m -= 1 

print(result)
