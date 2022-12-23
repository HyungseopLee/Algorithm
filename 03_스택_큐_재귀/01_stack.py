stack = []

stack.append(5)
stack.append(2)
stack.append(3)
stack.append(7)

stack.pop()

stack.append(1)
stack.append(4)

stack.pop()

print(stack)       # bottom 부터 원소 출력
print(stack[::-1]) # top부터 원소 출력