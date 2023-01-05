import math

def isPrimeNum(x) :
    # math 라이브러리를 굳이 사용하지 않아도 된다.
    # for i in range(2, int(math.sqrt(x)) + 1) :
    
    # x의 제곱근까지만 실행
    for i in range(2, int(x**(1/2)) + 1) :
        if(x % i == 0) :
            return False
        return True

print(isPrimeNum(4))
print(isPrimeNum(7))

print(2^3)  # ^ : XOR 연산자
print(2**3) # ** : 거듭제곱