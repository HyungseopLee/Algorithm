
import math

m, n = map(int, input().split())
prime = [True for i in range(n+1)]
# 1은 소수가 아니기 때문에 무조건 초기화 False해줘야 한다. (반복문을 2부터 실행시키기 때문)
prime[1] = False

for i in range(2, int(math.sqrt(n)) + 1) :
    if prime[i] == True :
        j = 2
        while True :
            if i*j > n :
                break
            prime[i * j] = False
            j += 1

for i in range(m , n+1) :
    if prime[i] == True :
        print(i)

'''

3 16

'''