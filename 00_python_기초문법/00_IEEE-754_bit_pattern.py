# IEEE-754 비트 패턴으로 인해, 

a = 0.3
b = 0.6
c = a + b
print(f"c: {c}")
if c == 0.9:
    print(f"True")
else :
    print(f"False")

a = 0.3
b = 0.9
c = a + b
print(f"c: {c}")
if c == 1.2:
    print(f"True")
else :
    print(f"False")
    
    
'''
python은 IEEE-754 비트 패턴을 공식적으로 사용함.
IEEE-754 비트 패턴: 컴퓨터에서 실수를 표현하는 표준 방식. 
    부동소수점은 세 부분으로 나뉨
        1. sign bit, 1bit: 0(양수) 1(음수)
        2. exponent bit: 수의 scale
        3. mantissa it: 수의 유효 숫자 (소수 부분)


0.3 + 0.6 의 실제 내부 값은 0.899999999999999911182... -> 이 값을 짧게 0.9라고 쓰면 다시 float으로 변환할 때 다른 비트 패턴이 될 수 있어서, dtoa 알고리즘이 "이 값을 보존하려면 최소한 0.8999999999999999까지 써야 한다”고 판단한 것.
0.3 + 0.9 의 실제 내부 값은 1.199999999999999955591... -> 이 값을 짧게 1.2라고 써도 다시 float으로 변환할 때 동일한 내부 비트 패턴이 되어, python은 더 짧고 보기 좋은 1.2를 출력한 것.


둘 다 마찬가지로 
'''

# 만약 정밀한 소수 계산이 필요하다면? decimal
from decimal import Decimal

a = Decimal("0.3")
b = Decimal("0.6")
c = a + b
print(f"c: {c}")