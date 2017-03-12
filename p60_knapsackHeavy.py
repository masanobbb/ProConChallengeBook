N_MAX = 100
V_MAX = 100
n = int(input())
wv = list(map(int, input().split()))
W = int(input())
w = wv[0::2]
v = wv[1::2]

dp = [[100000000 for i in range(N_MAX*V_MAX+1)] for j in range(n+1)]

dp[0][0] = 0
for i in range(n):
    for j in range(N_MAX*V_MAX+1):
        if j < v[i]:
            dp[i+1][j] = dp[i][j]
        else:
            dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i])

ans = 0
for i in range(N_MAX*V_MAX+1):
    if dp[n][i] <= W:
        ans = i

print(ans)