# 함수 안에서 global 을 통해 함수 밖 변수(global variable)를 사용

def func_global():
    global a 
    a += 1
    
def func_local():
    a += 1

a = 0    
for i in range(10):
    func_global()
print(a)

# a=0
# for i in range(10):
#     func_local()
# print(a)


# ---------------------------------------------------------------------------------------------------------------------
# 주의사항

array = [1, 2, 3]
scalar = 1

def func():
    array.append(4) # 내부 method 호출은 가능.
    print(f"array: {array}")
    print(f"scalar: {scalar}") 
    
    scalar += 1 # 에러 (값을 읽는건 되는데, 변경하는게 안되는건가?)
    
    '''
    python은 함수 내부에서 변수가 할당(=)되는 순간, 그 이름을 local variable로 취급함.
    따라서 바로 위의 scalar += 1은 scalar를 local variable로 인식함.
    그런데, scalar는 func() 함수 내에서 정의되지 않았으므로 에러가 발생하는 것임.
    '''
    
    
func()