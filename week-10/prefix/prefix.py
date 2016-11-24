import mmap

def prefix(s):
    n = len(s)
    p = [0]*n
    for i in range(1, n):
        k = p[i - 1]
        while k > 0 and s[i] != s[k]:
            k = p[k - 1]
        if s[i] == s[k]:
            k += 1
        p[i] = k

    return p

f = open('prefix.in', 'rb')
mm = mmap.mmap(f.fileno(), 0)
p = prefix(mm.readline().rstrip())
f = open('prefix.out', 'w')
for x in p:
    f.write('{} '.format(x))