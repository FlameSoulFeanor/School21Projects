import sys

i = 0
for j in sys.argv:
	i = j

for line in range(0, int(i)):
	f = input()
	if (len(f) == 32) and (f.startswith("00000")) and (f[5] != '0'):
		print(f)