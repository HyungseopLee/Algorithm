
from collections import deque
import copy

def topologySort() :
    # 원본 배열(time)의 보존을 위해 deepcopy 진행
    # 그냥 shallow copy(=) : result = time은 변수를 복사했지만, 참조한 곳이 동일하기 때문에 같은 변수를 가리키게 된다.
    result = copy.deepcopy(time)
    q = deque()
    for i in range(1, v+1) :
        if indegree[i] == 0 :
            q.append(i)
    
    while q:
        node = q.popleft()
        for i in graph[node] :
            indegree[i] -= 1
            if indegree[i] == 0 :
                q.append(i)
            result[i] = max(result[i], result[node] + time[i])

    for i in result :
        print(i)



v = int(input())

indegree = [0] * (v + 1)
time = [0] * (v + 1)
graph = [[] for i in range(v + 1)]

for i in range(1, v+1) :
    data = list(map(int, input().split()))
    time[i] = data[0]
    # 1번쨰 인덱스 ~ 마지막 인덱스에서 -1번째 인덱스 (-1입력을 배제하기 위해)
    for j in data[1 : -1] :
        print(j, end=" ")
        indegree[i] += 1
        graph[j].append(i)

topologySort()

'''

5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

'''