from ctypes import *

print '''\
c_int()
c_char()
c_byte()
c_ushort(-1)
c_uint(-1)
c_double(-1)'''

c_int()
c_char()
c_byte()
c_ushort(-1)
c_uint(-1)
c_double(-1)

seitz = c_char_p("hello world")
print seitz.value


print "Remember byref funciton"