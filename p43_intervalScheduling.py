
n = int( input() )
s = list( map(int, input().split()) )
t = list( map(int, input().split()) )

jobs = zip(s,t)

jobs = sorted(jobs,key=lambda l:l[1], reverse=False)

now = 0
count =0
for job in jobs:
    if now < job[0]:
        now = job[1]
        count += 1
print(count)