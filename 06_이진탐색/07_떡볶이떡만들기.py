# 떡의 개수(N)과 사용자가 필요한 떡의 양(M)을 입력받기
n, m = list(map(int, input().split()))

arr = list(map(int, input().split()))

start = 0
end = max(arr)

result = 0
while(start <= end) :
    sum = 0
    mid = (start + end) // 2
    
    for i in arr :
        if i > mid :
            sum += i - mid
    
    # 떡이 모자라면, 절단기 길이를 줄임==떡을 더 많이 자름(오른쪽 부분 탐색)
    if sum < m :
        end = mid - 1
    # 떡이 사용자가 요구한 것보다 충분하면, 절단기 길이를 늘림 == 떡을 덜 자름(왼쪽 부분 탐색)
    else :
        result = mid # 최적화 절단기 길이 갱신
        start = mid + 1

print(result)
