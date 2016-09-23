f = open('sortland.in', 'r')

_, income = f.readlines()
income = [float(i) for i in income.split()]
x = [i + 1 for i, v in sorted(enumerate(income), key=lambda iv: iv[1])]

f = open('sortland.out', 'w')
f.write('{} {} {}'.format(x[0], x[len(x) // 2], x[-1]))
