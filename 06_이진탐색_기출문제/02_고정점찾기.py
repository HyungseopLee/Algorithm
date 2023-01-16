def binarySearch(arr, start, end) :
    if start > end :
        return
    mid = (start + end) // 2

    if arr[mid] == mid :
        global fix_point
        fix_point = mid
    if arr[mid] > mid :
        return binarySearch(arr, start , mid - 1)
    else :
        return binarySearch(arr, mid + 1 , end)

n = int(input())
arr = list(map(int,input().split()))

fix_point = -1
binarySearch(arr, 0, n-1)

if fix_point :
    print(fix_point)
else :
    print(-1)  

'''

5
-15 -6 1 3 7
-> 3

7
-15 -4 3 8 9 13 15
-> -1

'''