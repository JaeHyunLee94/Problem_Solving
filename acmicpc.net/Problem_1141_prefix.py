# site domain
# https://www.acmicpc.net/problem/1141

def compare(a, b):
    if a and b:
        if a in b[:len(a)]:
            return a
        elif b in a[:len(b)]:
            return b
        else:
            return False
    else:
        return False


lists = []
for i in range(int(input())):
    lists.append(input())

size = len(lists)

for i in range(size):
    for j in range(i + 1, size):
        if compare(lists[i], lists[j]):
            if compare(lists[i], lists[j]) == lists[i]:
                lists[i] = False
            elif compare(lists[i], lists[j]) == lists[j]:
                lists[j] = False

list2 = list(filter(lambda x: x, lists))
print(len(list2))
