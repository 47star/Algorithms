#!/usr/bin/python3

import os, sys

file = open('batch', 'r', encoding='utf8')
data = file.read().split('\n')
file.close()

os.system(f'g++ -g {sys.argv[1]} -o out && chmod +x ./out')

i = 0
while i < len(data):
    file = open('input', 'w', encoding='utf8')
    file.write(data[i].split(': ', 2)[1])
    file.close()
    os.system(f'./out < input > output')
    file = open('output', 'r', encoding='utf8')
    exp = data[i+1][8:].strip('\n').strip('\r')
    res = file.read().strip('\n').strip('\r')
    # if not(exp == res):
    print(f'Test #{i / 2} => {exp == res}')
    file.close()
    i += 2