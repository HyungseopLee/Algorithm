""" 

python 내장함수 input()보다 더 빠른 속도로 입력받고 싶다면? sys.stdin.readline()
단, 입력 후 \n가 입력되므로 주로 rstrip() method를 함께 사용함.

"""

import sys

data = sys.stdin.readline()
print(f"data: {data}")

data = sys.stdin.readline().rstrip()   # strip()은 문자열의 시작과 끝에서 공백을 제거한 후 반환.
print(f"data: {data}")