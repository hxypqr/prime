w=0
g=1000100
q=g
for w in range(1,10):
 r=0
 for i in range (1000000,g):
    t=math.floor(math.sqrt(i*i+w))
    t=int(t)
    k=0
    for j in range(2,t+1):
        if (i*i+w)%j==0:
         k=1
    if k==0:
        r=r+1
        print i*i+w
 print r

print q/math.log(q)


g=1000
q=g
r=0
for i in range (1,g):
    t=math.floor(math.sqrt(i))
    t=int(t)
    k=0
    for j in range(2,t+1):
        if (i)%j==0:
         k=1
    if k==0:
        r=r+1
print r

print q/math.log(q)
