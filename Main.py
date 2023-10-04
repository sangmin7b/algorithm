import random
N = 100000
Q = 100000
print(N, Q)
for i in range(Q):
    # a = random.randint(1, N)
    # b = random.randint(a, N)
    a = i + 1
    b = i + 3    
    x = random.randint(1, 1e9)
    print(a, b, x)