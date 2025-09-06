# sum()
print(f"sum([1, 2, 3]): {sum([1, 2, 3])}")


# min(), max()
print(f"min([1, 2, 3]): {min([1, 2, 3])}")
print(f"max([1, 2, 3]): {max([1, 2, 3])}")


# eval(" 사람이 이해하는 수식 ")
result = eval("1 + 2 * 3")
print(f"result: {result}")

# sorted()
l1 = [1, 6, 3, 4, 5, 2]
print(f"sorted(l1): {sorted(l1)}")
print(f"sorted(l1, reverse=True): {sorted(l1, reverse=True)}")


# sorted() with key
l2 = [('이순신', 4), ('김유신', 5), ('최철순', 1)]
sorted_l2 = sorted(l2, key=lambda x: x[1]) # 각 element의 두 번째 element를 기준으로 sort
print(f"sorted_l2: {sorted_l2}")