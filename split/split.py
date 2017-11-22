#!/usr/bin/env python

fo = open('lipsum.txt', 'r')

for i in range(0, 100000):
    fo.seek(0, 0)
    for line in fo:
        fields = line.split(' ')
    if i%1000 == 0:
        print('%d %s' % (i, fields[i % len(fields)]))

fo.close();
