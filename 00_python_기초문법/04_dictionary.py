# dictionary: key와 value 쌍을 데이터로 가짐.
# list, tuple이 값을 순차적으로 저장하는 것과는 대비됨.
# dictionary는 immutable data type을 key로 사용할 수 있음. (string, tuple)
# python의 dictionary는 Hash Table을 이용하므로 data 조회 및 수정에 있어서 O(1)의 시간에 처리 가능

data = dict()
data['사과'] = 'apple'
data['바나나'] = 'banana'

print(data)

if '사과' in data :
    print(True)
    
    
# ---------------------------------------------------------------------------------------------------------------------
# keys(), values() method는 dictionary data의 key와 value들을 
dict_ks = data.keys() # 엄밀히 말하면, dict_keys라는 object 반환. -> interable하므로 for문에서 바로 순회 가능
dict_vs = data.values() # 엄밀히 말하면, dict_values라는 object 반환. -> interable하므로 for문에서 바로 순회 가능
print(f"keys: {dict_ks}")
print(f"values: {dict_vs}")

list_ks = list(data.keys())
list_vs = list(data.values())

for key in dict_ks:
    print(f"key: {key}, value: {data[key]}")
for key in list_ks:
    print(f"key: {key}, value: {data[key]}")