# pypy проходит по времени

f = open('binsearch.in', 'r')

lines = f.readlines()
n = int(lines[0])
arr = [int(x) for x in lines[1].split()]
to_find = lines[3].split()
f.close()
f = open('binsearch.out', 'w')

for x in to_find:
    x = int(x)
    l = 0
    r = n - 1
    start = -2
    while l <= r:
        m = (l + r) // 2
        if arr[m] > x:
            r = m - 1
        elif arr[m] == x:
            start = m
            r = m - 1
        else:
            l = m + 1

    end = -2
    l = r
    r = n - 1
    if start != -1:
        while l <= r:
            m = (l + r) // 2
            if arr[m] > x:
                r = m - 1
            elif arr[m] == x:
                end = m
                l = m + 1
            else:
                l = m + 1

    f.write('{} {}\n'.format(start + 1, end + 1))
