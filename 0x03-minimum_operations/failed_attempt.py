#!/usr/bin/python3
"""

def minOperations(n):
    if n < 2 or type(n) is not int:
        return 0

    a = "H"
    x = a[0]  # the letter H
    m = 1

    paste = 0

    if n % 2 != 0 and n % 3 != 0 and len(a) <= 1:
        paste = n
    if n % 2 == 0 and n % 3 != 0 and len(a) <= 1:
        paste = 2
    if n % 2 != 0 and n % 3 == 0 and len(a) <= 1:
        paste = 3
    if n % 2 == 0 and n % 3 == 0 and len(a) <= 1:
        paste = 3

    while len(a) < paste:
        a += x
        m += 1
        if len(a) == n:
            return m

    rep_paste = a
    m += 1

    while len(a) < n:
        if len(a) < n:
            a += rep_paste
            m += 1
        if len(a) == n:
            return m
"""