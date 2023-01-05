n = 5

data = [10, 20, 30, 40, 50]

prefix_sum = 0
prefix = [0]
for i in data : 
    prefix_sum += i
    prefix.append(prefix_sum)

left, right = 1, 3
print(prefix[right] - prefix[left - 1])