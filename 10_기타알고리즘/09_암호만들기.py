from itertools import combinations

# 모음 정의
mo = {'a', 'e', 'i', 'o', 'u'}

l, c = map(int, input().split())

# 암호를 사전순으로 출력해야 하니까 정렬
arr = input().split(' ')
arr.sort()

# 사전순으로 정렬된 arr를 l 개수에 맞도록 combination 수행
for passwd in combinations(arr, l) :
    cnt_mo = 0
    cnt_ja = 0
    for i in passwd :
        # 조합된 문자열에서 모음 개수 세기
        if i in mo :
            cnt_mo += 1
        # 조합된 문자열에서 자음 개수 세기
        else :
            cnt_ja += 1
    # 최소 한개의 모음, 최소 두개의 자음이 있으면 출력
    if cnt_mo >= 1 and cnt_ja >= 2 :
        # 각각의 문자들을 ''을 통해 합친다
        print(''.join(passwd))

'''

4 6
a t c i s w

'''