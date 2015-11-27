import os
for i in file('commands.txt'):
	print i,
	os.system(i)
	print ''
