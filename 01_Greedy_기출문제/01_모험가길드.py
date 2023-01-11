n = int(input())
arr = list(map(int, input().split()))

arr.sort()

print(arr)  

result = 0
cur_cnt = 0
for x in arr :
    cur_cnt += 1
    print(x)
    if cur_cnt >= x :
        print()
        result += 1
        cur_cnt = 0

print(result)

'''

5
2 3 1 2 2

8
5 5 5 5 3 4 1 2

'''