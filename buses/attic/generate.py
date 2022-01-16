import random
import sys

# Argumentos:
#
# 1. Seed para random
#
# 2. Valor de M
#
# 3. Valor de N
#
# 4. Valor de F
#
# 5. Probabilidad de poner vereda (entre 0 y 1), 7 hace override
#
# 6. Lugar de partida:
#   1: parte en 1, 1
#   2: parte en 1, N
#   3: parte en M, 1 
#   4: parte en M, N
#   etc, parte en posición random
#
# 7. Veredas en lugar de partida:
#   0: no hay
#   1: hay horizontal
#   2: hay vertical
#   3: hay ambas
#
# 8. Puntos de interés:
#   TODO: -3: en cada cuadra de la 1ra y última calle vertical y horizontal c/veredas
#   TODO: -2: en cada cuadra de la 1ra y última calle vertical c/veredas
#   TODO: -1: en cada cuadra de la 1ra y última calle horizontal c/veredas
#   0: en cada cuadra
#   >= 0: número de puntos de interés dispuestos al azar
#
# 9. TODO: Verificar F-1, F, F+1 distintos
#   0: no
#   != 0: sí
#

random.seed(str(sys.argv[1:]))

m = int(sys.argv[2])
n = int(sys.argv[3])
f = int(sys.argv[4])
r = float(sys.argv[5])
s = int(sys.argv[6])
v = int(sys.argv[7])
t = int(sys.argv[8])
z = bool(int(sys.argv[9]))

# Verificaciones

assert 0 < min(m, n)
assert max(m, n) <= 100
assert 1 <= f <= max(m, n) + m + n - 3
assert 0 <= r <= 1
assert 0 <= v <= 3
assert -3 <= t <= 1000

# Cálculo del output

xopts = {1: 1, 2: 1, 3: m, 4: m}
yopts = {1: 1, 2: n, 3: 1, 4: n}
x = xopts.get(s, random.randint(1, m))
y = xopts.get(s, random.randint(1, n))

horizontal = [0] * m
for i in range(m):
    if i == x - 1:
        horizontal[i] = v & 1
    else:
        horizontal[i] = int(random.random() < r)

vertical = [0] * n
for i in range(n):
    if i == y - 1:
        vertical[i] = (v & 2) >> 1
    else:
        vertical[i] = int(random.random() < r)

pdi = []
if t == 0:
    for i in range(m):
        for j in range(n - 1):
            pdi.append((i + 1, j + 1, 0))
    for i in range(m - 1):
        for j in range(n):
            pdi.append((i + 1, j + 1, 1))
elif t > 0:
    cuadras = m * (n - 1) + (m - 1) * n
    for i in range(t):
        rand = random.randint(0, cuadras - 1)
        if (rand < m * (n - 1)):
            a = rand % m
            b = rand // m
            c = 0
        else:
            rand -= m * (n - 1)
            a = rand // n
            b = rand % n
            c = 1
        pdi.append((a + 1, b + 1, c))

# Output

print(m, n)
print(*horizontal)
print(*vertical)
print(x, y, f)
print(len(pdi))
for i in range(len(pdi)):
    print(*pdi[i])
