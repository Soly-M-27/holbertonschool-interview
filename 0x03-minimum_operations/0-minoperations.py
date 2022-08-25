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
    if n < 2 or type(n) is not int:
        return 0
    
    a = "H"
    x = a[0]  # the letter H
    m = 1

    paste = 0

    if n % 2 == 0 and n % 3 != 0 and len(a) <= 1:
        paste = 2
    elif n % 2 != 0 and n % 3 == 0 and len(a) <= 1:
        paste = 3
    elif n % 2 == 0 and n % 3 == 0 and len(a) <= 1:
        paste = 3

    while len(a) < paste:
        a += x
        m += 1

    rep_paste = a
    
    while len(a) < n:
        if len(a) < n:
            a += rep_paste
            m += 1
        if len(a) == n:
            return m + 1
