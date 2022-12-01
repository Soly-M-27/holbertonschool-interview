#!/usr/bin/python3

def rain(walls=[]):
    list_len = len(walls)
    current_wall = 0
    temp = 0
    new_wall = 0
    zero_count = 0
    wall_extract = 0
    total_water = 0
    
    if (list_len == 0):
        return 0
     
    for x in walls:
        if (x > 0):
            current_wall = x
            #print("current_wall: {:d}".format(current_wall))
            if (walls[x + 1] > 0):
                new_wall = x + 1
                #print("new_wall: {:d}".format(new_wall))
            if (current_wall < new_wall):
                total_water += current_wall
            if (current_wall > new_wall):
                total_water += new_wall
            if (total_water < 0):
                total_water *= -1
            #print("-------------------------")
            #print("total_water: {:d}".format(total_water))
    return total_water