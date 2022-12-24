array = [('바나나', 2), ('사과', 6), ('당근', 3)]

def mySort(data) :
    return data[1]

# sorted() : 복사본을 넘겨 result에 정렬된 list 반환
result = sorted(array, key=mySort)
print(result)
print(array)

# sort() : 원본이 바로 정렬됨 , list 객체의 내장된 method
array.sort(key=mySort)
print(array)