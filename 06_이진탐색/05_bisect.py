from bisect import bisect_left, bisect_right

def countByRange(arr, left_value, right_value) :
    right_index = bisect_right(arr, right_value)
    left_index = bisect_left(arr, left_value)
    return right_index - left_index

arr = [1, 2, 3, 3, 3, 3, 4, 4, 8 , 9]

# arr에서 값이 4~4인 개수 출력
print(countByRange(arr, 4, 4))
# arr에서 값이 -1~3인 개수 출력
print(countByRange(arr, -1, 3))