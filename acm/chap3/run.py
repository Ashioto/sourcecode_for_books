#!/usr/bin/python

import sys
import os

cmd = "gcc -std=c99 {0}".format(sys.argv[1]);
print cmd
os.system(cmd)

cmd = "./a.out"
os.system(cmd)
