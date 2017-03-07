
coinN = list(map(int, input().split()))

A = coinN.pop()

# Sort coinN in the descending order based on value
coinN = reversed(coinN)

coinV = [500, 100, 50, 10, 5, 1]

count=0

# n for coin num
# v for coin value
for n,v in zip(coinN,coinV):

    if n > 0 and A/v > 0:
        count += min(n, int(A/v))
        A -= v * min(n, int(A/v))

print(count)