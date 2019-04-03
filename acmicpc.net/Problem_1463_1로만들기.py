# site domain
# https://www.acmicpc.net/problem/1463

import math

num = int(input())
table = [0 for i in range(num + 1)]
for i in range(num, 0, -1):
    if i > math.floor(num / 2):
        table[i] = num - i
    elif i > math.floor(num / 3):
        table[i] = min(table[2 * i], table[i + 1]) + 1
    else:
        table[i] = min(table[2 * i], table[3 * i], table[i + 1]) + 1

print(table[1])
