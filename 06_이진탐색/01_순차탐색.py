
# strs 처음부터 끝까지 target과 같은 것이 있는지 확인
def sequential_search(n, target, strs) :
    for i in range(n) :
        if strs[i] == target :
            return i

print("생성할 원소의 개수와 찾을 문자열을 입력하세요 : ")
user_input = input().split()
n = int(user_input[0])
target = user_input[1]

print("앞서 적은 원소 개수만큼 문자열을 입력하세요 : ")
strs = input().split()

# 순차 탐색 수행 결과 출력
print(str(target) + "은 "+str(sequential_search(n, target, strs))+"번째 인덱스에 있습니다.")