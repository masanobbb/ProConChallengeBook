
N = int(input())
R = int(input())
x = list(map(int, input().split()))


i = 0
count = 0
while i < N:

    s = x[i]
    i += 1
    
    while i < N and x[i] - s <= R:
        i += 1

    count += 1
    n = x[i-1]

    while i < N and x[i] - n <= R:
        i += 1

print(count)