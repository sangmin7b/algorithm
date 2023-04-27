N, M = map(int, input().split())
mem = list(map(int, input().split()))
cost = list(map(int, input().split()))
memo = []
memo.append((cost[0], mem[0]))
for i in range(1,len(mem)):
    memo2 = []
    m = mem[i]
    c = cost[i]
    memo2.append((c,m))
    for p in memo:
        memo2.append(p)
        memo2.append((p[0] + c, p[1] + m))
    memo = memo2
print(len(memo))
memo = list(filter(lambda x: x[1] >= M, memo))
print(sorted(memo)[0][0])