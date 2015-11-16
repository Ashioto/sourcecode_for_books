from ctypes import *
import pdb

class Person(Structure):
	__fields__ = [
		("name",c_char_p),
		("age",c_int),
		("sex",c_byte)
	]

class PersonUnion(Union):
	__fields__ = [
		("age_long",c_long),
		("age_int",c_int),
		("age_char",c_char * 8)
	]

# value = raw_input("please enter a number\n")

my_person = PersonUnion()

print "a person's age as int:%d"%my_person.age_int
print "a person's age as long:%ld"%my_person.age_long
print "a person's age as char:%s"%my_person.age_char