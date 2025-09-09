# 0~100까지의 짝수들의 합
list_1 = [i for i in range(100) if i%2==0]
print(f"{list_1}")
result = sum(list_1)
print(f"result: {result}")


# 1부터 50까지의 정수 중에서 3의 배수이면서 5의 배수는 아닌 수만 리스트로 만들어보세요.
result = [ i for i in range(50) if i%3==0 and i%5!=0 ]
print(f"result: {result}")

# 아래와 같은 2차원 리스트가 있습니다:
# matrix = [[1, 2, 3], [4, 5], [6, 7, 8, 9]]
# 이 리스트를 하나의 리스트로 평탄화(flatten)하세요.
matrix = [[1, 2, 3], [4, 5], [6, 7, 8, 9]]
flatten_matrix = [ m for row in matrix for m in row]
print(f"{flatten_matrix}")


# 문자열 리스트가 있습니다:
# 이 중에서 글자 수가 6 이상이고, ‘a’로 시작하는 단어만 대문자로 변환한 리스트를 만들어보세요.
words = ["apple", "banana", "cherry", "avocado", "blueberry"]
new_words = [ str.upper(word) for word in words if word[0]=='a' and len(word)>=6]
print(f"new_words: {new_words}")