# Memoization하기 위한 리스트 초기화
m = [0] * 100

# 재귀 -> Top down
def fibo(x) :
    print('f(' + str(x) + ')', end=' ')
    if x == 1 or x == 2 :
        return 1
    # 계산한 적 있는 문제라면, 리스트에서 해당 값 꺼내옴
    if m[x] != 0 :
        return m[x]
    else :
        m[x] = fibo(x-1) + fibo(x-2)
        return m[x]

print(fibo(6))