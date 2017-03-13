
n = int(input())
m = int(input())
a = list(map(int, input().split()))
M = int(input())

dp = [[0 for i in range(m+1)] for j in range(n+1)]

for i in range(n):
    dp[i][0] = 1
    for j in range(m+1):
        if j-1-a[i]>=0:
            dp[i+1][j] = (dp[i][j] + dp[i+1][j-1] - dp[i][j-1-a[i]])%M
        else:
            dp[i+1][j] = (dp[i][j] + dp[i+1][j-1])%M

print(dp[n][m])