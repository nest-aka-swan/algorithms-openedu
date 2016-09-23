f = open('aplusb.in', 'r')
numbers = [int(i) for i in f.read().split()]

f = open('aplusb.out', 'w')
f.write(str(sum(numbers)))
