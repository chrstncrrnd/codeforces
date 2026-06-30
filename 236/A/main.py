import sys


input = sys.stdin.read

data = input().splitlines()


name = data[0]

alpha = {}


for c in name:
    if c in alpha:
        alpha[c] += 1
    else:
        alpha[c] = 1


distinct = len(alpha)

# odd (male)
if distinct % 2 == 1:
    print("IGNORE HIM!")
else:
    print("CHAT WITH HER!")
