n = input()
mid = len(n)//2
left = sum(list(map(int, n[:mid])))
right = sum(list(map(int, n[mid:])))

if left == right :
    print("LUCKY")
else :
    print("READY")

'''
(1)
123402

(2)
7755

'''