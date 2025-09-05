"""
input(): 한 줄의 string을 입력받음
map(): list의 모든 element에 각각 특정한 함수를 적용할 때 사용

    
"""


# 입력받을 데이터 개수: n, 그 데이터들을 내림차순 정렬하라.
n = int(input())
data = list(map(int, input().split()))

data.sort(reverse=True)
print(f"data: {data}")

# 데이터가 반드시 세 개만 들어온다면?
a, b, c = map(int, input().split())
print(a, b, c)