# Enter your code here. Read input from STDIN. Print output to STDOUT

import re
import sys

def split_camel_case(input_str, type_):
    if type_ == "M":
        # Remove "()" for methods
        input_str = input_str[:-2]  
    words = re.findall(r'[A-Za-z][^A-Z]*', input_str)
    return ' '.join(word.lower() for word in words)

def combine_camel_case(input_str, type_):
    words = input_str.split()
    if type_ == "C":
        # Class: Every word capitalized
        return ''.join(word.capitalize() for word in words)
    elif type_ == "V":
        # Variable: First word lowercase, rest capitalized
        return words[0].lower() + ''.join(word.capitalize() for word in words[1:])
    elif type_ == "M":
        # Method: First word lowercase, rest capitalized, ends with "()"
        return words[0].lower() + ''.join(word.capitalize() for word in words[1:]) + "()"

# Read all input and process each line
for line in sys.stdin:
    operation, type_, input_str = line.strip().split(';')
    if operation == "S":
        sys.stdout.write(split_camel_case(input_str, type_) + "\n")
    elif operation == "C":
        sys.stdout.write(combine_camel_case(input_str, type_) + "\n")
