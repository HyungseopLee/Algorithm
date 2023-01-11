
import itertools

n, m = input().split()
arr = list(map(int, input().split()))

nC2 = itertools.combinations(arr, 2)

cnt = 0
for i in nC2 :
    first = i[0]
    second = i[1]
    if first != second :
        cnt += 1

print(cnt)

'''

5 3
1 3 2 3 2

8 5
1 5 4 3 2 4 5 2

'''