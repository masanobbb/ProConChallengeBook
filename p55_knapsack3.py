
n = int( input() )
wv = list( map(int, input().split()))
W = int( input() )
w = wv[0::2]
v = wv[1::2]

dp = [[0 for i in range(W+1)] for i in range(n+1)]

for i in range(n):
    for j in range(W+1):

        if j < w[i]:
            dp[i+1][j] = dp[i][j]
        else:
            dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i])
print(dp[n][W])