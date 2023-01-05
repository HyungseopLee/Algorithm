
# 특정한 합을 가지는 부분 수열 찾기

n = 5
m = 5 # 특정한 합
arr = [1, 2, 3, 2, 5]

cnt = 0
local_sum = 0
start, end = 0, 0

for start in range(n) :
    local_sum = arr[start]  
    while True :
        local_sum += arr[end]
        if start == end :
            local_sum -= arr[start]
        if end >= n :
            break
        elif m == local_sum :
            cnt += 1
            break
        elif local_sum < m :
            end += 1
        elif local_sum > m :
            break


print(cnt)