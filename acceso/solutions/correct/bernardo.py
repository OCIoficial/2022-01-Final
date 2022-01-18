M, N = map(int, input().split(' '))
sw_M = list(map(int, input().split(' ')))
sw_N = list(map(int, input().split(' ')))
X, Y, F = map(int, input().split(' '))
E = int(input())
V = M*N
G = {}
iedges = []
for e in range(E):
	a, b, c = map(int, input().split(' '))
	iedges.append((a,b,c))

dist = {(X-1, Y-1): 0}
q = [(X-1,Y-1)]
while len(q):
	i, j = q.pop()
	vdirs = []
	if sw_M[i]:
		vdirs.extend([(0, 1), (0,-1)])
	if sw_N[j]:
		vdirs.extend([(1,0), (-1, 0)])
	for vdir in vdirs:
		di, dj = vdir
		if min(i+di, j+dj) >= 0 and i+di < M and j+dj < N:
			if (i+di, j+dj) not in dist or dist[(i+di, j+dj)] > dist[(i,j)] + 1:
				dist[(i+di, j+dj)] = dist[(i, j)] + 1
				q.append((i+di, j+dj))
ans = 0
for iedge in iedges:
	a, b, c = iedge
	a, b = a-1, b-1
	if (a,b) not in dist or (a+c, b+1-c) not in dist: continue
	ans += max(dist[(a,b)], dist[(a+c,b+1-c)]) <= F
print(ans)

