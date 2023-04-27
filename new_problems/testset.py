import random
f = open("/home/sangmin7b/projects/ps/new_problems/t.txt","w")

t = 10
n = 2000000
m = 500
k = 2500
x = 100000
f.write(f'{t}')
f.write("\n")
for i in range(t):
    f.write(f'{n}')
    f.write("\n")
    for j in range(n):
        f.write(f'{random.randint(100000,1000000)}')
        f.write("\n")
f.close()