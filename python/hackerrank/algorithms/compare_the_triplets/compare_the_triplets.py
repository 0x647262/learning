#!/bin/python3

import sys

def solve(a0, a1, a2, b0, b1, b2):
    score = [0, 0]
    alist = [a0, a1, a2]
    blist = [b0, b1, b2]
    clist = zip(alist, blist)
    for pair in clist:
        if pair[0] > pair[1]:
            score[0] += 1
        elif pair[0] < pair[1]:
            score[1] += 1
        else:
            continue
    return score
        

a0, a1, a2 = input().strip().split(' ')
a0, a1, a2 = [int(a0), int(a1), int(a2)]
b0, b1, b2 = input().strip().split(' ')
b0, b1, b2 = [int(b0), int(b1), int(b2)]
result = solve(a0, a1, a2, b0, b1, b2)
print (" ".join(map(str, result)))
