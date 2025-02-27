#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pangrams' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def pangrams(s):
    # Write your code here
    count = [0] * 26
    offset = ord('a')
    for c in s.lower():
        if c != ' ':
            index = ord(c) - offset
            count[index] = 1
    
    if sum(count) == 26:
        return "pangram"
    else:
        return "not pangram"

# def pangrams(s):
#     # Write your code here
#     s = s.lower()
#     letters = set(c for c in s if 'a' <= c <= 'z')
    
#     if len(letters) == 26:
#         return "pangram"
#     else:
#         return "not pangram"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)

    fptr.write(result + '\n')

    fptr.close()
