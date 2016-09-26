f = open('kth.in', 'r')

n, k1, k2 = [int(x) for x in f.readline().split()]
A, B, C, a1, a2 = [int(x) for x in f.readline().split()]

def int32(x):
    return x.to_bytes(32, byteorder='big', signed=True)

def a_i(size):
    helper = [a1, a2] + (size - 2)*[0]
    yield helper[0]
    yield helper[1]
    i = 2
    while i < size:
        new = A * helper[i - 2] + B * helper[i - 1] + C
        helper[i] = new
        i += 1
        yield new

# for num in a_i(n):
#     print(num)
