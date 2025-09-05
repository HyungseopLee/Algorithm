a = [ i for i in range(10) ]
print(a)

a = [ i**2 for i in range(10) ]
print(a)

# ---------------------------------------------------------------------------------------------------------------------
# list comprehension은 2차원 list를 초기화할 때 효과적으로 사용할 수 있음
# 특히, N X M 크기의 2차원 리스트를 한 번에 초기화해야 할 때 유용


# 4 X 3 2차원 list 초기화
n = 4
m = 3
map = [ [0] * m for _ in range(n)]
# map = [ [0 * m] for _ in range(n) ] # 잘못된 방법. 전체 list 안에 포함된 각 list(row)가 모두 같은 object로 인식됨.
print(f"map: {map}")

cnt_zero = 0
cnt_one = 0
for i in range(n):
    cnt_zero += map[i].count(0)
    cnt_one += map[i].count(1)
print(f"cnt_zero:{cnt_zero}")
print(f"cnt_one:{cnt_one}")


# ---------------------------------------------------------------------------------------------------------------------
# list comprehension 응용

a = [1,2,3,4,5,5,5]
remove_set = {3, 3, 5}
print(f"remove_set: {remove_set}")

# a에서 remove_set에 포함된 숫자를 지워라
print(f"(before) a: {a}")
a = [ i for i in a if i not in remove_set]
print(f"(after) a: {a}")

a = [1,2,3,4,5,5,5]
remove_list = [3, 3, 5]
# a에서 remove_list에 포함된 숫자를 지워라
print(f"(before) a: {a}")
a = [ i for i in a if i not in remove_list]
print(f"(after) a: {a}")