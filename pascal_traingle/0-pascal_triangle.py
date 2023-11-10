#!/usr/bin/python3
''' Module Pascal's Triangle '''


def pascal_triangle(n):
    """
    Function that returns a list of lists of integers representing
    the Pascal's triangle o n.
    Args:
        n (int): Limit for the Pascal Triangle to be created
    Returns:
        Pascal's Triangle of n or an empty list if n <= 0.
    """
    if n <= 0:
        return []

    triangle = []
    for i in range(n):
        row = [1]

        if triangle:
            prev_row = triangle[-1]
            for j in range(len(prev_row) - 1):
                row.append(prev_row[j] + prev_row[j + 1])

            row.append(1)

        triangle.append(row)

    return triangle
