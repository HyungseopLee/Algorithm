arr = [5, 3, 8, 5, 9, 1, 6, 2, 7]

def quickSort(arr) :
    # list가 하나 이하의 원소만 담고 있으면 종료
    if len(arr) <= 1 :
        return arr
    pivot = arr[0] 
    tail = arr[1:] # 피벗을 제외한 나머지 리스트

    left = [x for x in tail if x <= pivot] # 분할된 왼쪽 부분
    right = [x for x in tail if x >= pivot] # 분할된 왼쪽 부분

    # 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행하고, 전체 리스트 반환
    return quickSort(left) + [pivot] + quickSort(right)

print(quickSort(arr))