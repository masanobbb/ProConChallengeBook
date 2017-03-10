
N = int(input())
S = list(input())
R = list(reversed(S))

ans = []

while len(ans) < N:
    if S<=R:
        ans.append(S.pop(0))
    else:
        ans.append(R.pop(0))

print("".join(ans))