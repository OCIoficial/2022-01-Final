N = int(input())
lengths = map(int, input().split(' '))
rows = [map(int, input().split(' ')) for _ in range(N)]
print(min(sum(row) for row in rows))
