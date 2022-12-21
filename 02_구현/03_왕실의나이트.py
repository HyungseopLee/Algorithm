# 현재 나이트의 위치 입력받기
user_input = input()
row = int(user_input[1])
col = int(ord(user_input[0])) - int(ord('a')) + 1 # ord() : ascii값으로 바꿔주는 함수

# 나이트가 이동할 수 있는 8가지 방향 정의
steps = [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1,2) , (-1, 2), (-2, 1)]

# 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
result = 0
for step in steps:
    next_row = row + step[0]
    next_cal = col + step[1]

    # 해당 위치로 이동이 가능하다면 result += 1
    if next_row >= 1 and next_row <= 8 and next_cal >= 1 and next_cal <= 8 :
        result += 1

print(result)