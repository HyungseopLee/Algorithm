
from operator import itemgetter

def solution(food_times, k) :
    foods = []
    n = len(food_times)
    for i in range(n):
        foods.append(food_times[i], i+1)
    
    foods.sort()

    prev_time = 0
    for i, food in enumerate(foods) :
        diff = food[0] - prev_time
        if diff != 0 :
            spend_time = diff * n
            if spend_time <= k :
                k -= spend_time
                prev_time = food[0]
            else :
                k %= n
                # 1번 index(음식 번호)로 정렬
                sublist = sorted(foods[i:], key=itemgetter(1))
                return sublist[k][1]
        n -= 1
    
    return -1

