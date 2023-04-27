import random
n = 100
print(n)
x = 1e12
for i in range(n):
    if random.random() < 0.9:
        print('0 0')
    else:
        print(f'{random.randint(0,100)} {random.randint(0, 100)}')
