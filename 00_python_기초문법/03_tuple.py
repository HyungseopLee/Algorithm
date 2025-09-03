a = (1, 2, 3, 4, 5)
print(a[2])
print(a[:3])

# a[0] = a[0]*2 # tuple은 str과 같이 immutable


# ---------------------------------------------------------------------------------------------------------------------
# tuple은 list와 유사하지만, list에 비해 "공간 효율적"임
''' tuple을 사용하면 좋은 경우
1. 서로 다른 성질의 데이터를 묶어서 관리해야 할 때
    - shortest path algorithm에서는 (비용, node)의 형태로 tuple type을 자주 사용
    
2. data의 나열을 Hashing의 key로 사용해야 할 때
    - tuple은 immutable하므로 list와 다르게 key로 사용될 수 있다.
    
3. list보다 memory를 효율적으로 사용해야 할 때
'''

## 1. 서로 다른 성질의 데이터를 묶어 관리할 때
import heapq

queue = []
heapq.heappush(queue, ('A', 10))
heapq.heappush(queue, ('B', 5))
heapq.heappush(queue, ('C', 7))

while queue:
    node, cost = heapq.heappop(queue)
    print(f"Node: {node}, Cost: {cost}")
    
    
    
## 2. data의 나열을 Hashing의 key로 사용해야 할 때
d = {(1, 2): 2, (1, 3):8}
for key in d.keys() :
    print(f"key: {key}, value: {d[key]}")
    
    
    
## 3. list보다 moery를 효율적으로 사용해야 할 때
import sys
a_list = [1, 2, 3, 4, 5]
a_tuple = (1, 2, 3, 4, 5)
print(sys.getsizeof(a_list))   # 예: 104 bytes
print(sys.getsizeof(a_tuple))  # 예: 80 bytes    