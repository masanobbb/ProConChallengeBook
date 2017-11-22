
if __name__ == "__main__":

    s = input().split( )
    m = int(s[1])

    k = [int(i) for i in s[2:]]
    print(k)

    f = False

    for a in k:
        for b in k:
            for c in k:
                for d in k:
                    if a+b+c+d == m:
                        f = True
    
    if f :
        print("Yes")
    else :
        print("No")
