'''

lambda 표현식은 특정한 기능을 수행하는 함수를 한 줄에 간단하게 작성할 수 있음

'''

# 함수
def add(a, b):
    return a+b
print(add(3, 7))

# lambda 표현식
print( (lambda a, b: a+b)(3, 7) )




# ---------------------------------------------------------------------------------------------------------------------
# 예시: 점수가 높은순으로 학생들을 오름차순 정렬하라.

array = [ ('홍길동', 50), ('이순신', 32), ('아무개', 74) ]

def my_key(x):
    return x[1]

print( sorted(array, key=my_key, reverse=True))
print( sorted(array, key=lambda x: x[1], reverse=True) )


# ---------------------------------------------------------------------------------------------------------------------
# 예시: 여러 개의 list에 적용

list1 = [1, 2, 3, 4, 5]
list2 = [10, 20, 30, 40, 50]
list3 = [100, 200, 300, 400, 500]

result = map(lambda a, b, c: a + b + c, list1, list2, list3)
print(list(result))

