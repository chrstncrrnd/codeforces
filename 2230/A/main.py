import math


file = open("input.txt")

lines = file.read().splitlines()

_ = lines.pop(0)

def min_amount(line):
    n, a, b = [int(k) for k in line.split(" ")]
    print(n, a, b)
    if 3*a < b:
        return n * a

    if math.ceil(b / 3) < a:
        return math.ceil((n / 3) * b)
    with_three = n // 3

    remaining = n*3 - with_three





for line in lines:
    print(min_amount(line))


