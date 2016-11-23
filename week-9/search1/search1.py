f = open('search1.in', 'r')
sub, text = (x.rstrip() for x in f.readlines())

f = open('search1.out', 'w')

start = 0
indices = []
while True:
    index = text.find(sub, start)
    if index is -1:
        break
    start = index + 1
    indices.append(start)

f.write("{}\n".format(len(indices)))
for index in indices:
    f.write("{} ".format(index))