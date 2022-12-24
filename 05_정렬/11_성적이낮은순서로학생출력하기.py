n = int(input())

array = []

for i in range(n) :
    user_input = input().split()
    array.append( (user_input[0], int(user_input[1])) )

# array를 lambda식을 이용하여 정렬
array = sorted(array, key = lambda stduent : stduent[1]) 

for student in array :
    print(student[0], end=' ')

"""

2
홍길동 95
이순신 77

"""