#!/usr/bin/python3
"""
Main file for testing
"""


from re import I


minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 9
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 24
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 16
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))