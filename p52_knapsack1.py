
n = int( input() )
w = list( map(int, input().split()))
v = list( map(int, input().split()))
W = int( input() )

# Binary search
def rec(i, j):

    if i == n:
        val = 0
    elif j < w[i]:
        val = rec(i+1,j)
    else:
        val = max( rec(i+1, j-w[i]) + v[i], rec(i+1,j) )
    return val

print( rec(0,W) )