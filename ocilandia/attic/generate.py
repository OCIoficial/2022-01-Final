import random
import sys

# Argumentos:
#
# 1. Seed para random
#
# 2. Numero de filas N
#
# 3. Min numero de personas per fila
#
# 4. Max numero de persinas per fila

random.seed(str(sys.argv[1:]))

N = int(sys.argv[2])
min_fila = int(sys.argv[3])
max_fila = int(sys.argv[4])
min_tiempo = int(sys.argv[5])
max_tiempo = int(sys.argv[6])

# Verificaciones

assert 0 < N
assert 0 < min_fila
assert 0 < max_fila
assert min_fila < max_fila

# Cálculo del output
personas_en_fila = [random.randint(min_fila, max_fila) for _ in range(N)]
tiempo_por_fila = []

for n_p in personas_en_fila:
    tiempos = []
    for i in range(n_p):
        tiempos.append(random.randint(min_tiempo, max_tiempo))
    tiempo_por_fila.append(tiempos)

print(tiempo_por_fila)

def validate_times(ts):
    t_times = []
    for fila in ts:
        t_sum = sum(fila)
        assert t_sum not in t_times
        t_times.append(ts)

validate_times(tiempo_por_fila)
    
print(N)
for i in range(N):
    print(personas_en_fila[i])
for i in range(N):
    print(*tiempo_por_fila[i], sep=' ')