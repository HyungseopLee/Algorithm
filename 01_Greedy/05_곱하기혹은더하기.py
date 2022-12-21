user_input = input()

result = int(user_input[0])

for i in range(1, len(user_input)) :
    num = int(user_input[i])
    if num <= 1 or result <= 1 :
        result += num
    else :
        result *= num   

print(result)