arr = input()

result = int(arr[0])

for i in range(1, len(arr)) :
    num = int(arr[i])
    if result <= 1 or num <= 1 :
        result += num
    else :
        result *= num

print(result)

'''

02984   -->  576

567    ---> 210

'''