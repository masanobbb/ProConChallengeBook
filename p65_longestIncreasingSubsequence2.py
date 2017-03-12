import bisect
n = int(input())
a = list(map(int, input().split()))
INF = 10000000
dp = [INF for i in range(n)]

for i in range(n):
    index = bisect.bisect_left(dp,a[i])
    dp[index] = a[i]

print(bisect.bisect_left(dp,INF))