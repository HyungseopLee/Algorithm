def solution(s):
    answer = len(s)
    # 1개 단위(unit)부터 압축 단위를 늘려가며 확인
    for unit in range(1, len(s) // 2 + 1):
        finalStr = ""
        curStr = s[0:unit] # 앞에서부터 unit만큼의 문자열 추출
        count = 1
        # 단위(unit) 크기만큼 증가시키며 이전 문자열과 비교
        for j in range(unit, len(s), unit):
            # 이전 상태와 동일하다면 압축 횟수(count) 증가
            nextStr = s[j:j + unit]
            if curStr == nextStr:
                count += 1
            # 다른 문자열이 나왔다면(더 이상 압축하지 못하는 경우라면)
            else:
                finalStr += str(count) + curStr if count >= 2 else curStr
                curStr = nextStr # 다시 상태 초기화
                count = 1
        # 남아있는 문자열에 대해서 처리
        finalStr += str(count) + curStr if count >= 2 else curStr
        # 만들어지는 압축 문자열이 가장 짧은 것이 정답
        print(finalStr)
        answer = min(answer, len(finalStr))
    return answer

print(solution("abcabcabcabcdededededede"))