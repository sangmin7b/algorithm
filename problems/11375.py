N, M = map(int, input().split())
adj = []
visited = [0 for i in range(N)]
matched = [-1 for i in range(M)]

cnt = 0
def dfs(now):
	if visited[now]:
		return False
	visited[now] = True
	
	for next in adj[now]:
		if (matched[next] == -1):
			matched[next] = now
			return True
	
	for next in adj[now]:
		if (matched[next] == -1 or dfs(matched[next])):
			matched[next] = now
			return True
	
	
	return False


for i in range(N):
	jobs = list(map(int, input().split()))[1:]
	jobs = [x-1 for x in jobs]
	adj.append(jobs)

for i in range(N):
	visited=[0 for i in range(N)]
	if dfs(i):
		cnt += 1
print(cnt)