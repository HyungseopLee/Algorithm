
def findFamily(family, data) :
    if family[data] != data :
        family[data] = findFamily(family, family[data])
    return family[data]

def beFamily(family, t1, t2) :
    t1_family = findFamily(family, t1)
    t2_family = findFamily(family, t2)
    if t1_family < t2_family :
        family[t2] = t1
    else :
        family[t1] =  t2

n, m = map(int, input().split())
family = [0] * (n+1)

for i in range(1, n+1) :
    family[i] = i

for _ in range(m) :
    teacher_input, t1, t2 = map(int, input().split())
    
    if teacher_input == 0 :
        beFamily(family, t1, t2)

    else :
        if findFamily(family, t1) == findFamily(family, t2) :
            print("YES")
        else :
            print("NO")

'''

7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

'''