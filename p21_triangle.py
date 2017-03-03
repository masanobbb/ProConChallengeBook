
if __name__ == "__main__":

    s = input().split( )

    k = [int(i) for i in s[1:]]
    #先に降順にソートしておく
    k = sorted(k,reverse=True)
    
    ans = 0 

    #重複して選ばないようにループ
    for a in range(len(k)):
        for b in range(a+1,len(k)):
            for c in range(b+1,len(k)):
                if k[a] < (k[b] + k[c]):
                    ans = max([ans, k[a]+k[b]+k[c]])
    print(ans)
