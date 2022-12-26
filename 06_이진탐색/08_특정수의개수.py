# bisect library 사용

from bisect import bisect_left, bisect_right 

def countByRange(arr, x) :
    right_index = bisect_right(arr, x)
    left_index = bisect_left(arr, x)
    return right_index - left_index

n, x = map(int, input().split())
arr = list(map(int, input().split()))

count = countByRange(arr, x)

if count == 0 :
    print(-1)
else :
    print(count)