def merge_sort(start, end):
    if len(numbers[start:end]) < 2:
        print('{} {}'.format(numbers[start], numbers[end]))
        return numbers[start:end]
    merged = []
    mid = len(numbers[start:end]) // 2
    arr_l = merge_sort(start, start + mid)
    arr_r = merge_sort(end - mid, end)

    i = 0
    j = 0
    while i < len(arr_l) and j < len(arr_r):
        if arr_l[i] < arr_r[j]:
            merged.append(arr_l[i])
            i += 1
        else:
            merged.append(arr_r[j])
            j += 1
    merged += arr_l[i:]
    merged += arr_r[j:]
    print('{} {}'.format(merged[0], merged[-1]))
    return merged

f = open('sort.in', 'r')

_, numbers = f.readlines()
numbers = [int(i) for i in numbers.split()]

f = open('sort.out', 'w')
print(' '.join(str(x) for x in merge_sort(0, len(numbers))))
# print(numbers[0:len(numbers)])

# f = open('sort.out', 'w')
# f.write('{} {} {}'.format(x[0], x[len(x) // 2], x[-1]))
