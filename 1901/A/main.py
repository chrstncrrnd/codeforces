import sys

inp = sys.stdin.read()
data = inp.splitlines()


t = int(data.pop(0))


for i in range(t):
    l1 = data[i*2].split(" ")
    l2 = data[i*2 + 1].split(" ")
    n, x = [int(j) for j in l1]
    a = [int(j) for j in l2]
    a.insert(0,0)
    a.append(a[-1] + 2*(x-a[-1]))
    maximum = 0
    for j in range(n+1):
        dist = a[j+1] - a[j]
        if dist > maximum:
            maximum = dist
    print(maximum)

