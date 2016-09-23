f = open('smallsort.in', 'r')

_, numbers = f.readlines()
numbers = sorted(int(i) for i in numbers.split())

f = open('smallsort.out', 'w')
f.write(' '.join(str(i) for i in numbers))
