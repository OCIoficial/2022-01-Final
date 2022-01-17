import random
import sys

random.seed(sys.argv[1])


def read_arg(arg, min_value, max_value):
    if arg == 'rand':
        return random.randint(min_value, max_value)
    else:
        return int(arg)


def gen_random_matrix(M, N):
    return [[random.randint(NUM_MIN, NUM_MAX)
             for _ in range(N)] for _ in range(M)]


def print_matrix(matrix):
    for r in matrix:
        print(*r)


if __name__ == '__main__':
    M = read_arg(sys.argv[2], 1, 500)
    N = read_arg(sys.argv[3], 1, 500)

    NUM_MIN = read_arg(sys.argv[4], 0, 10**6)
    NUM_MAX = read_arg(sys.argv[5], NUM_MIN, 10**6)
    eq = False
    if len(sys.argv) == 7 and sys.argv[6] == 'eq':
        eq = True

    assert 1 <= M <= 500
    assert 1 <= N <= 500
    assert 0 <= NUM_MIN <= 10**6
    assert NUM_MIN <= NUM_MAX <= 10**6

    print(M, N)
    up_matrix = gen_random_matrix(M, N)
    if eq:
        left_matrix = up_matrix
    else:
        left_matrix = gen_random_matrix(M, N)
    print_matrix(up_matrix)
    print_matrix(left_matrix)
