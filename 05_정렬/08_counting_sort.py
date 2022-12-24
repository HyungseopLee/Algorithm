A = [9,8,7,6,5,4,3,2,1,0,0,0,1,2,3,4,5,6,7,8,9]

# 초기 배열 A에서 최대값만큼 크기를 갖는 배열 B 생성
B = [0] * (max(A) + 1)

for i in range(len(A)) :
    B[A[i]] += 1 # 배열 A의 값에 해당하는 B의 인덱스의 값을 증가 
                 # 따라서 리스트에 음수가 있다면 계수 정렬 사용 불가

for i in range(len(B)) :
    for j in range(B[i]) :
        print(i, end=' ')
