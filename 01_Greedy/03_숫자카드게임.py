n, m = map(int, input().split()) 

result = 0

for i in range(n) :
    data = list(map(int, input().split()))
    # 현재 줄에서 가장 작은 수 찾기
    min_value = 99999
    for a in data :
        min_value = min(min_value, a)
    result = max(result, min_value)

print(result)



'''
3 3
3 1 2
4 1 4
2 2 2

2 4
7 3 1 8
3 3 3 4
'''


