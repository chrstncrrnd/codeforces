import sys

input = sys.stdin.read
data = input().splitlines()


# `data` is a list of strings where each string is a line

cases = int(data.pop(0))


def bs(ls: list[int]) -> int:
    if sum(ls[:-1]) <= ls[-1]:
        return ls[-1]

    s = False

    for i in range(len(ls) - 1):
        s = True
        if ls[i] > ls[i + 1]:
            temp = ls[i + 1]
            ls[i + 1] += ls[i]
            ls[i] = temp
            s = False

    if s:
        return ls[-1]

    return bs(ls)


for i in range(cases):
    piles = int(data[2*i])
    ducks = [int(k) for k in data[2*i + 1].split(" ")]
    print(bs(ducks))



