#!/usr/bin/python3

def rain(walls=[]):
    list_len = len(walls)
    current_wall = 0
    new_wall = 0
    total_water = 0

    if (list_len == 0):
        return 0

    for x in walls:
        if (x > 0):
            current_wall = x
            if (walls[x + 1] > 0):
                new_wall = x + 1
            if (current_wall < new_wall):
                total_water += current_wall
            if (current_wall > new_wall):
                total_water += new_wall
            if (total_water < 0):
                total_water *= -1
    return total_water
