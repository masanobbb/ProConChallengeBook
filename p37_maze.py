N = int( input() )
M = int( input() )
maze = [list( input() ) for i in range(N)]
INF = 10000000
pathcost = [[INF for i in range(M)] for j in range(N)]

sx = 0
sy = 0

for i in range(N):
    for j in range(M):
        if maze[i][j] == 'S':
            sx = j
            sy = i

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs():
    que = []
    que.append([sy,sx])
    pathcost[sy][sx] = 0
    while len(que) > 0:
        y, x = que.pop(0)

        for i, j in zip(dx, dy):
            ny = y + j
            nx = x + i
            if ny in range(N) and nx in range(M):
                if maze[ny][nx] == '.' and pathcost[ny][nx]==INF:
                    que.append([ny,nx])
                    pathcost[ny][nx] = pathcost[y][x]+1
                elif maze[ny][nx] == 'G':
                    pathcost[ny][nx] = pathcost[y][x]+1
                    return pathcost[ny][nx]

print(bfs())