n = int(input())
nArr = [0] * 1000001 # 입력 받는 정수는 1~1,000,000 라고 명시 되어 있기 때문

for i in input().split() :
    nArr[int(i)] = 1

m = int(input())
mArr = list(map(int, input().split()))
for i in range(m) :
    if nArr[mArr[i]] == 1 :
        print('yes', end=' ')
    else :
        print('no', end=' ')