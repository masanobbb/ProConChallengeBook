

if __name__ == "__main__":
	print("adafdb")
	s = input().split( )

	l = int(s[0])
	x = [int(i) for i in s[2:]]

	maxT = 0
	for p in x:
		maxT = max([maxT, p, l-p])
	
	minT = 0
	for p in x:
		minT = max([minT, min([p, l-p])])

	print("max =",maxT)
	print("min =",minT)
