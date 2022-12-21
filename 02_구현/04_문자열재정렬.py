data = input()
result = []
value = 0

for x in data :
    if x.isalpha() :
        result.append(x)
    else :
        value += int(x)

result.sort()

# 숫자가 존재했을 경우, 가장 뒤에 삽입
if value != 0 :
    result.append(str(value))

print(''.join(result)) # '' : 구분자, .join : result 리스트의 매개변수들을 합쳐주는 함수