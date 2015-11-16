#!/usr/bin/python

from ctypes import *

libc = CDLL("libc.so.6")
message_string = "Hello world."

libc.printf("Testing :%s"%message_string)