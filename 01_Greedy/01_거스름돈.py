n = 1260
cnt = 0

array = [500, 100, 50, 10]

for coin in array :
    cnt += n // coin # 해당 화폐로 거슬러 줄 수 있는 동전의 개수 세기
    n %= coin

print(cnt)