#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste. Given a number n, write a method that calculates
the fewest number of operations needed to result in exactly n H characters
in the file.
Returns:
    int: minimum number of operations needed
"""


def minOperations(n):
    """Prototype: minOperations

    Args:
        n (int): Number of H characters to get to

    Returns:
        int: Min num of operations needed to return n number of the letter H
    """
    buf = n
    div = 2
    count = 0
    if type(n) is not int or n < 2:
        return 0
    while buf > 1:
        if buf % div == 0:
            buf /= div
            count += div
        else:
            div += 1
    return count
    



"""
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
