def binarySearch(nArr, start, end, target) :
    if start > end :
        return False
    mid = (start + end) // 2
    if nArr[mid] == target :
        return True
    elif nArr[mid] < target :
        return binarySearch(nArr, mid + 1, end, target)
    elif nArr[mid] > target :
        return binarySearch(nArr, start, mid - 1, target)


n = int(input())
nArr = list(map(int, input().split()))
nArr.sort()

m = int(input())
mArr = list(map(int, input().split()))
for i in range(m) :
    if binarySearch(nArr, 0, n-1, mArr[i]) == True:
        print("yes", end=' ')
    else :
        print("no", end=' ')

'''

5
8 3 7 9 2
3
5 7 9

'''