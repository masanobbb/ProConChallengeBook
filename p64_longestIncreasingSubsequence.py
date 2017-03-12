
n = int(input())
a = list(map(int, input().split()))

dp = [0 for i in range(n+1)]
dp[0] = 0
for i in range(n):
    dp[i] = 1
    for j in range(i):
        if a[i] > a[j]:
            dp[i] = max(dp[i],dp[j]+1)

print(max(dp))