def isPrimeNum(x) :
    for i in range(2, x) :
        # 2 ~ (x-1) 중 나누어 떨어지는 수가 있으면 소수가 아님
        if(x % i == 0) :
            return False
        return True

print(isPrimeNum(4))
print(isPrimeNum(7))