
N = int( input() )
M = int( input() )
arr = [ list(input()) for i in range(N) ]

ans = 0

def dfs(y, x):
    arr[y][x] = '.'
    for i in [-1,0,1]:
        for j in [-1, 0, 1]:
            ny = y+i
            nx = x+j
            if (ny in range(N)) and (nx in range(M)) and (arr[ny][nx]=='W'):
                dfs(ny, nx)

for i in range(N):
    for j in range(M):
        if arr[i][j] == 'W':
            dfs(i,j)
            ans = ans+1

print( ans )