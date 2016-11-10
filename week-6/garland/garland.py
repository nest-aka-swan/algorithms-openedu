def h(h1, h2, n):
    return [h1, h2] + [(i - 1) * h2 - (i - 2) * h1 + (i - 1) * (i - 2) for i in range(3, n + 1)]

f = open('garland.in', 'r')
n, A = f.readline().split()

n = int(n)
h1 = float(A)


l, r = 0, h1

while r - l > 1e-9:
    h2 = (l + r) / 2
    heights = h(h1, h2, n)

    if any(h < 0 for h in heights):
        l = h2
    else:
        r = h2

f = open('garland.out', 'w')
f.write(str(round(heights[-1], 2)))
