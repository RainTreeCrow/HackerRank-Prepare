#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    n = len(arr)
    positives = sum(1 for x in arr if x > 0)
    negatives = sum(1 for x in arr if x < 0)
    zeros = sum(1 for x in arr if x == 0)

    positive_ratio = positives / n
    negative_ratio = negatives / n
    zero_ratio = zeros / n

    print(f"{positive_ratio:.6f}")
    print(f"{negative_ratio:.6f}")
    print(f"{zero_ratio:.6f}")

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
