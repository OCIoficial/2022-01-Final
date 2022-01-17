import sys
import random

random.seed(sys.argv[1])

N = int(sys.argv[2])
MAX = int(sys.argv[3])
V = random.randint(1, MAX)

print(N, V)
print(' '.join(str(random.randint(1, MAX)) for _ in range(N)))
