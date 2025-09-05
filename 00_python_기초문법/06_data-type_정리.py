''' python data type 총정리
1. list, string, tuple은 순서가 있기 때문에(=iterable하기 때문에) indexing을 통해 값을 얻을 수 있음(=loop 사용 가능).
    * 위 dtype 모두 indexing을 통해 element값을 얻을 수는 있지만, list(=mutable)와 달리 string과 tuple은 immutable(=변경 불가능)하기 때문에 element값을 "변경"할 수는 없음.
2. dict, set은 순서가 없기 때문에 indexing을 통해 값을 얻을 수 없음.
    * dict에 대해서는 key를 이용해 O(1) 시간 복잡도로 조회 가능. (이때, key는 immutable한 string or tuple이어야 함)
    * set에 대해서는 element를 이용해 O(1) 시간 복잡도로 조회 가능.
'''

# ---------------------------------------------------------------------------------------------------------------------
# 1. list, string, tuple   data type에 대한 핵심 정리.
list_1 = [1, 2, 3]
tuple_1 = (1, 2, 3)
string_1 = "hello"

## iterable 특성으로 인한 indexing과 loop 가능 유무
print(f"list_1[1]: {list_1[1]}")     # list   dtype은 iterable(순서가 있기) 때문에, indexing을 통해 element값을 얻을 수 있다.
print(f"tuple_1[1]: {tuple_1[1]}")   # tuple  dtype은 iterable(순서가 있기) 때문에, indexing을 통해 element값을 얻을 수 있다.
print(f"string_1[1]: {string_1[1]}") # string dtype은 iterable(순서가 있기) 때문에, indexing을 통해 element값을 얻을 수 있다.
for l in list_1:  # list   dtype은 iterable(순서가 있기) 때문에, loop 사용 가능하다.
    print(f"{l}", end=' ')
print()
for t in tuple_1:  # tuple  dtype은 iterable(순서가 있기) 때문에, loop 사용 가능하다.
    print(f"{t}", end=' ')
print()    
for s in string_1:  # string dtype은 iterable(순서가 있기) 때문에, loop 사용 가능하다.
    print(f"{s}", end=' ')
print()

## mutable 속성으로 인한 element 변경 가능 유무
list_1[1] = 0     # list   dtype은 mutable(변경 가능하기) 때문에, element값을 변경할 수 있다.
# tuple_1[1] = 0     # error: tuple  dtype은 immutable(변경 불가능하기) 때문에, element값을 변경할 수 없다.
# string_1[1] = "0"   # error: string dtype은 immutable(변경 불가능하기) 때문에, element값을 변경할 수 없다.



# ---------------------------------------------------------------------------------------------------------------------
# 2. dict, set   data type에 대한 핵심 정리.
dict_1 = {'a' : 1, (1, 2): 2, (1, 3): 3}
set_1 = {'a', 'a', 'a', 'b', 1, 1, 1}

# dict: key를 이용한 조회
print(f"dict_1['a']: {dict_1['a']}")
print(f"dict_1[(1, 2)]: {dict_1[(1, 2)]}")
for key in list(dict_1.keys()) :
    print(f"key: {key}, value: {dict_1[key]}")

# set: element 이용한 조회
print(f"set_1: {set_1}")
print(f"'a' in set_1: {'a' in set_1}")
print(f"'c' in set_1: {'c' in set_1}")