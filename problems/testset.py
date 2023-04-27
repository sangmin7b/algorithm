import random
f = open("/home/sangmin7b/projects/ps/problems/test.txt","w")

n = 4000
f.write(f'{n} {n}')
f.write("\n")
for i in range(n):
    f.write(f'a{i}' * 200 + '\n')
for i in range(n):
    f.write(f'b{i}' * 200 + '\n')
f.write(f'{20000}')
for i in range(20000):
    f.write(f'a{i}' * 200 + f'b{i}' * 200 + '\n')
    
f.close()