n = int( input() )
wv = list( map(int, input().split()))
W = int( input() )
w = wv[0::2]
v = wv[1::2]

dp = [[-1 for i in range(W+1)] for j in range(n+1)]

# Binary search with Memorization
def rec(i, j):

    if dp[i][j] >=0:
        return dp[i][j]

    if i == n:
        res = 0
    elif j < w[i]:
        res = rec(i+1,j)
    else:
        res = max( rec(i+1,j), rec(i+1,j-w[i])+v[i] )

    dp[i][j] = res
    return res

print(rec(0,W))