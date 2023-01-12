s = input()
flag = 0
sum = 0

result = []

for i in s :
    if i.isalpha() :
        result.append(i)
    else :
        flag = 1
        sum += int(i)

result.sort()

# 숫자가 있는 경우에만 뒤에 sum을 합친다
if flag :
    result.append(str(sum))

print(''.join(result))

'''

K1KA5CB7

AJKDLSI412K4JSJ9D

'''