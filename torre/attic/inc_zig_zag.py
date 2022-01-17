import sys
import random

random.seed(sys.argv[1])

N = int(sys.argv[2])
S = random.randint(1, 1000000000)

tower = []

for P in range(S, N + S):
    if random.choice([True, False]):
        tower.append(P)
    else:
        tower.insert(0, P)

print(N, S)
print(' '.join(str(P) for P in tower))
