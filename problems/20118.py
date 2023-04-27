N, M = map(int,input().split())
nums = []
for i in range(N):
    x = list(map(int, input().split()))
    nums.append(x)
K = 2 * (N + M - 1)
if (N + M - 1) % 2 == 1:
    K += 2
print(K)
for j in range(0,M-1,2):
    for _ in range(2):
        print(f'0 {j}')
        print(f'0 {j+1}')
start = 0
if M % 2 == 0:
    start += 1
if (N + M - 1) % 2 == 1:
    for i in range(start,N-2,2):
        for _ in range(2):
            print(f'{i} {M-1}')
            print(f'{i+1} {M-1}')
    for _ in range(2):
        print(f'{N-1} {M-2}')
        print(f'{N-1} {M-1}')
else:
    for i in range(start,N-1,2):
        for _ in range(2):
            print(f'{i} {M-1}')
            print(f'{i+1} {M-1}')
