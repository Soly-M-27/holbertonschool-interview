#!/usr/bin/python3
""" N queens """
import sys

def check_in(b, col):
    """ Randomize list based on range """
    n = len(b)
    if col is n:
        print(str([[c, b[c]] for c in range(n)]))
        return
    for row in range(n):
        if cposition(b, row, col):
            b[col] = row
            check_in(b, col + 1)

def cposition(b, row, col):
    """ Check position """
    for c in range(col):
        if b[c] is row or abs(b[c] - row) is abs(c - col):
            return False
    return True

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        sys.exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)
    b = [0 for col in range(int(sys.argv[1]))]
    check_in(b, 0)
