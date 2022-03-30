import random

n = random.randint(2,13)
m = random.randint(1,100)
s = ""
table = ['A', 'B', 'C']
print(n,m)
for j in range(m):
    s = ""
    for i in range(0, n):
        s += (table[ random.randint(0,2) ])
    print(s)

