from itertools import islice
# def merge_sort(arr):
#     if len(m) <= 1:
#         return arr
 
#     middle = len(m) // 2
#     left = arr[:middle]
#     right = arr[middle:]
 
#     left = merge_sort(left)
#     right = merge_sort(right)

#     result = []
#     l_i, r_i = 0, 0
#     while l_i < len(left) and r_i < len(right):
#         if left[l_i] <= right[r_i]:
#             result.append(left[l_i])
#             l_i += 1
#         else:
#             result.append(right[r_i])
#             r_i += 1
#     if l_i < len(left):
#         result += left[l_i:]
#     if r_i < len(right):
#         result += right[r_i:]

#     return result


def sort(pos):
    i = m
    indices = list(range(1,m+1))
    arr = list(zip(indices, *pos))
    while i > 0:
        arr.sort(key=lambda x: x[i])
        yield arr
        i -= 1


f = open('radixsort.in', 'r')
n_m_k, *positions = f.readlines()
n, m, k = (int(x) for x in n_m_k.split(' '))
positions = [x.strip() for x in positions]


for x in sort(positions):
    print(x)

# пятый тест валится из-за неизменения размеров при транспонировании