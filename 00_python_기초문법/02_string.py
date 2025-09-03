data = "Hello World!"
print(data)

data = "Don't you know \"Python\"?"
print(data)

# ---------------------------------------------------------------------------------------------------------------------
# string은 list와 달리, immutable하기 때문에 특정 index의 값을 변경할 수 "없음"
s1 = "Hello"
s2 = "World"

print(s1 + " " + s2)

s1[0] = "h"  # 변경 불가. immutable -> tuple: (), str: "" or ''
print(s1)