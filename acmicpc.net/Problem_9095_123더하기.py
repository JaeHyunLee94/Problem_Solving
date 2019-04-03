# site domain
# https://www.acmicpc.net/problem/9095

testcase = int(input())

for i in range(testcase):
    num = int(input())
    table = [0 for i in range(12)]
    table[1] = 1
    table[2] = 2
    table[3] = 4
    for j in range(4, num + 1):
        table[j] = table[j - 1] + table[j - 2] + table[j - 3]

    print(table[num])
