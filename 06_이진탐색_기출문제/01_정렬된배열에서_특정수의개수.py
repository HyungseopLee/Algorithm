import bisect 

n, x = map(int, input().split())
arr = list(map(int,input().split()))

lr = bisect.bisect_right(arr, x) - bisect.bisect_left(arr, x)

if lr :
    print(lr)
else :
    print(-1)

'''

7 2
1 1 2 2 2 2 3

'''