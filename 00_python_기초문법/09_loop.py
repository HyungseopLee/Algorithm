# while

i = 0
sum = 0
while i<=9:
    sum+=i
    i+=1
    
print(f"sum: {sum}")


# for + in

list_1 = [1,2,3,4,5]
tuple_1 = (1, 2, 3, 4, 5)

for l in list_1 :
    print(f"{l}", end=' ')
print()
for t in tuple_1 :
    print(f"{t}", end=' ')
    
# for + in range()
for i in range(len(list_1)) :
    print(f"list_1[i]: {list_1[i]}")
  
  
    
# 특정 번호 학생은 제외하여 합불 판단
scores = [90, 85, 77, 65, 97]
threshold = 80
cheating_student_list = {2, 4}

for i in range(len(scores)):
    if i+1 in cheating_student_list:
        continue
    if scores[i] >= threshold:
        print(f"{i+1}번 학생은 합격입니다.")
    else:
        print(f"{i+1}번 학생은 불합격입니다.")