arr = input()

cnt0 = 0
cnt1 = 0
cur_char = arr[0]

if cur_char == '0' :
    cnt0 += 1
else :
    cnt1 += 1

for i in range(0, len(arr)) :
    if cur_char != arr[i] :
        if arr[i] == '0' :
            cnt0 += 1
        else :
            cnt1 += 1
        cur_char = arr[i]

print(min(cnt0, cnt1))

'''

0001100

0101010001110

'''


