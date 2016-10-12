import random
import string

F = open('radixsort.in', 'wt')

N, M, K = 20000, 1000, 1000
# N, M, K = 10, 10, 10

F.write('{} {} {}\n'.format(N, M, K))

for i in range(M):
    F.write(' '.join(random.choice(string.ascii_lowercase)
                     for _ in range(N)) + '\n')
