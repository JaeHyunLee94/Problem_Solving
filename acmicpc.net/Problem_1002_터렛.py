# site domain
# https://www.acmicpc.net/problem/1002

import math

test_case = int(input())
for i in range(test_case):
    data = input()
    list = data.split()
    listx = list[0:3]
    listy = list[3:]
    listz = [(int(listx[0]) - int(listy[0])) ** 2 + (int(listx[1]) - int(listy[1])) ** 2, int(listx[2]),
             int(listy[2])]
    if listz[0] == 0 and listz[1] == listz[2]:
        print(-1)
    elif listz[0] == (listz[1] + listz[2]) ** 2 or listz[0] == (listz[1] - listz[2]) ** 2:
        print(1)
    elif listz[0] < (listz[1] + listz[2]) ** 2 and listz[0] > (listz[1] - listz[2]) ** 2:
        print(2)
    else:
        print(0)
