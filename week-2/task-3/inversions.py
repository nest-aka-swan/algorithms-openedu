count = 0

def merge_sort(arr):
    global count
    if len(arr) < 2:
        count += 1
        return arr
    merged = []
    mid = len(arr) // 2
    arr_l = merge_sort(arr[:mid])
    arr_r = merge_sort(arr[mid:])

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

    count += 1
    return merged

f = open('inversions.in', 'r')

_, numbers = f.readlines()
numbers = [int(i) for i in numbers.split()]
merge_sort(numbers)

f = open('inversions.out', 'w')
print(count - 2, file=f)
