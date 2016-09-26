f = open('antiqs.in', 'r')

n = int(f.read())
numbers = [i for i in range(1, n + 1)]

numbers[-1] = numbers[n // 2]
numbers[n // 2] = n

f = open('antiqs.out', 'w')
f.write(' '.join(str(x) for x in numbers))

# f = open('antiqs.out', 'w')
# print(count - 2, file=f)
