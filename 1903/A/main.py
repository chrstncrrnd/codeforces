import sys


input = sys.stdin.read

data = input().splitlines()

t = int(data.pop(0))

# for each test case
for _ in range(t):
    l1 = data.pop(0)
    l2 = data.pop(0)

    n, k = [int(i) for i in l1.split(" ")]
    a = [int(i) for i in l2.split(" ")]
    if k >= 2:
        print("YES")
        continue

    # check that they are in non-decreasing order
    for i in range(n-1):
        if a[i] > a[i+1]:
            print("NO")
            break
    else:
        print("YES")
