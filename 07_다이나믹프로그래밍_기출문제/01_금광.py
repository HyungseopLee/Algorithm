
t = int(input())

for _t in (0, t):
    # 금광 정보 입력
    n, m = map(int, input().split())
    array = list(map(int, input().split()))

    # dp_table 초기화 (금광 정보 array 값들 복사해서 담기)
    dp_table = []
    index = 0
    for i in range(n):
        dp_table.append(array[index:index + m])
        index += m

    # dp_table update (두번째 열부터 시작)
    for _m in range(1, m):
        for _n in range(n):
            # 왼쪽 위에서 올 수 없는 경우
            if _n == 0:
                left_up = 0
            # 왼쪽 위에서 올 수 있는 경우
            else:
                left_up = dp_table[_n - 1][_m - 1]
            # 왼쪽에서 오는 경우
            left = dp_table[_n][_m - 1]
            # 왼쪽 아래에서 올 수 없는 경우
            if _n == n - 1:
                left_down = 0
            # 왼쪽 아래에서 올 수 있는 경우
            else:
                left_down = dp_table[_n + 1][_m - 1]
            dp_table[_n][_m] = dp_table[_n][_m] + max(left_up, left_down, left)

    result = 0
    for i in range(n):
        result = max(result, dp_table[i][m - 1])

    print(result)

    
'''

2
3 4
1 3 3 2 2 1 4 1 0 6 4 7
4 4
1 3 1 5 2 2 4 1 5 0 2 3 0 6 1 2

'''