# set: 중복 허용 X, 순서 X
# 초기화1: list or string을 이용해서 초기화. 이때, set() 함수를 이용
# 초기화2: ({})안에 각 원소를 , 기준 구분하여 삽입
    
# ---------------------------------------------------------------------------------------------------------------------
## 초기화 방법 1
data = set( [1, 1, 2, 2, 3, 3] )
print(data)

## 초기화 방법 2
data = {1, 1, 2, 2, 3, 3}
print(data)

## 초기화시, 주의사항
data = set() 
print(type(data))

data = {} # 주의: empty {} -> set X, dictionary O
print(type(data))

# ---------------------------------------------------------------------------------------------------------------------
data = set([1, 2, 3])
print(data)

data.add(4) # 새로운 element 추가
print(data)

data.update([5, 6]) # 여러 elements 추가
print(data)

data.remove(5) # 특정값 element 제거
print(data)

# ---------------------------------------------------------------------------------------------------------------------
# 수학적 집합 연산
data = data - set({1, 2, 3}) # 차집합
print(data)

data = data | set({1, 2, 3}) # 합집합 (+ 아니라 |임.)
print(data)

newe_data = {2, 4}
data = data & newe_data # 교집합
print(data)
