f = open('aplusbb.in', 'r')
numbers = [int(i) for i in f.read().split()]

f = open('aplusbb.out', 'w')
f.write(str(numbers[0] + numbers[1] * numbers[1]))
