n = int(input())

data = list(map(int, input().split()))
data.sort()

result = 0 
cnt = 0 # 현재 그룹에 포함된 모험가의 수

for i in data :
    cnt += 1
    if cnt >= i : # 현재 그룹에 포함된 모험가의 수가 현재의 공포도 이상이라면, 그룹 결성
        result += 1
        cnt = 0

print(result)