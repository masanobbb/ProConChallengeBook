
n = int(input())
m = int(input())
M = int(input())

dp = [[0 for i in range(n+1)] for j in range(m+1)]

for i in range(m+1):
    dp[i][0] = 1
    for j in range(n+1):
        if i > j:
            dp[i][j] = dp[i-1][j]
        else :
            dp[i][j] = (dp[i][j-i] + dp[i-1][j])%M
print(dp[m][n])

