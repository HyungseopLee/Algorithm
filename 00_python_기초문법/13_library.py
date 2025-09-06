from itertools import permutations, combinations
# itertools -> permutation, combination

data = ['A', 'B', 'C']

permutation_data = list(permutations(data, 3))
print(f"permuted_data: {permutation_data}")
permutation_data = list(permutations(data, 2))
print(f"permutation_data: {permutation_data}")

combination_data = list(combinations(data, 3))
print(f"combination_data: {combination_data}")
combination_data = list(combinations(data, 2))
print(f"combination_data: {combination_data}")




# ---------------------------------------------------------------------------------------------------------------------


from collections import Counter

l1 = ['red', 'red', 'blue', 'blue', 'blue']
counter = Counter(l1)
print(f"counter['red']: {counter['red']}")
print(f"dict(counter): {dict(counter)}")


# ---------------------------------------------------------------------------------------------------------------------

import math
# GCD(Greatest Common Devisor): 최대공약수
# LCM(Leaset Common Multiplier): 최소공배수

a = 21
b = 14

print(f"math.gcd(a, b): {math.gcd(a, b)}")
print(f"math.lcm(a, b): {math.lcm(a, b)}")