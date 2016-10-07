import sys, random


items_per_column = 15


def find_i_th_smallest( A, i ):
    t = len(A)
    if(t <= items_per_column):
        return sorted(A)[i]
    else:
        B = [ find_i_th_smallest(k, (len(k) - 1)//2) for k in [A[j:(j + items_per_column)] for j in range(0,len(A),items_per_column)]]
        M = find_i_th_smallest(B, (len(B) - 1)//2)

        P1 = [ j for j in A if j < M ]
        if(i < len(P1)):
            return find_i_th_smallest( P1, i)
        P3 = [ j for j in A if j > M ]
        L3 = len(P3)
        if(i < (t - L3)):
            return M
        return find_i_th_smallest( P3, i - (t - L3))


number_of_numbers = int(sys.argv[1])

# L = [ random.randint(0, number_of_numbers) for i in range(0, number_of_numbers) ]
L = [x for x in range(1, number_of_numbers)]
# print(L)
print(find_i_th_smallest( L, (len(L) - 1) // 2))