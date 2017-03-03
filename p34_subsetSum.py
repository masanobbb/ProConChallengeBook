
def dfs(summ, i):

    if i == len(arr):
        return summ==target
    if dfs(summ, i+1):
        return True
    if dfs(summ + arr[i], i+1):
        return True

    return False

input()     # for n
arr = list( map( int, input().split()) )
target = int( input() )

if dfs(0, 0):
    print( "Yes" )
else :
    print( "No" )
