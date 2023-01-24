
n, c = list(map(int, input().split()))

house = []
for _ in range(n) :
    house.append(int(input()))
house.sort()

start = 1
end = house[n-1] - house[0]
result = 0

while (start <= end) :
    gap = (start + end) // 2
    prev_house = house[0]
    cnt = 1
    for i in range(1, n) :
        diff = house[i] - prev_house
        if(diff >= gap) :
            cnt += 1
            prev_house = house[i]
    # 공유기 설치제한 횟수보다 더 많이 설치했으면, gap을 줄여야 한다
    if cnt >= c :
        start = gap + 1
        result = gap
    # 공유기 설치제한 횟수보다 모자르면, gap을 늘려야 한다
    else :
        end = gap - 1

print(result)

'''

5 3
1
2
8
4
9

'''