n = int( input() )
m = int( input() )
s = list( input() )
t = list( input() )

dp = [[0 for i in range(m+1)] for j in range(n+1)]

for i in range(n):
    for j in range(m):
        if s[i]==t[j]:
            dp[i+1][j+1] = dp[i][j]+1
        else :
            dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])

print(dp[n][m])