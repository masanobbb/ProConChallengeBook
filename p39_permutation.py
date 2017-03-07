import itertools

n = int( input("Input N:") )

used = [False for i in range(n)]
perm = [0 for i in range(n)]

def permutation(pos, n):

    if pos == n:
        print("".join( [ str(elem) for elem in perm ] ))

    for i in range(n):
        if not used[i]:
            perm[pos] = i
            used[i] = True
            permutation(pos+1,n)
            used[i] = False

print("-----Recursive Function-----")
permutation(0,n)

print("----------Library-----------")
for perm in itertools.permutations(range(n),n):
    print( "".join( [str(elem) for elem in perm] ) )