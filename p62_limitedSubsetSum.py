
n = int(input())
a = list(map(int, input().split()))
m = list(map(int, input().split()))
K = int(input())

dp = [-1 for i in range(K+1)]
dp[0] = 0
for i in range(n):
    for j in range(K+1):
        if dp[j] >= 0:
            dp[j] = m[i]
        elif j < a[i] or dp[j-a[i]] <= 0:
            dp[j] = -1
        elif dp[j-a[i]]>0:
            dp[j] = dp[j-a[i]]-1
if dp[K]>=0:
    print("Yes")
else:
    print("No")