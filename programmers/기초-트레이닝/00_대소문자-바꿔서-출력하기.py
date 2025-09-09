''' https://school.programmers.co.kr/learn/courses/30/lessons/181949

문제 설명
    영어 알파벳으로 이루어진 문자열 str이 주어집니다. 
    각 알파벳을 대문자는 소문자로 소문자는 대문자로 변환해서 출력하는 코드를 작성해 보세요.
    
제한 사항
    1 ≤ str의 길이 ≤ 20 
    (str은 알파벳으로 이루어진 문자열입니다.)
    
입출력 예
    입력 #1 
        aBcDeFg    
    출력 #1
        AbCdEfG

'''

# 내 풀이
str = input()
result = []
for c in range(len(str)):
    if str[c] >= 'a' and str[c] <='z':
        print(f"{str[c].upper()}", end="")
    elif str[c] >= 'A' and str[c] <= 'Z':
        print(f"{str[c].lower()}", end="")
        
        
# 다른 사람의 풀이
print(f"{input().swapcase()}")