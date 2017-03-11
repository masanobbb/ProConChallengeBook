
N = int( input() )
L = list( map(int, input().split()))

ans = 0

while len(L) > 1:

    L = sorted(L)

    min1 = L.pop(0)
    min2 = L.pop(0)

    L.append(min1+min2)
    ans += min1 + min2

print(ans)