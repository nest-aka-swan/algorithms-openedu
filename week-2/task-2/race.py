result = {}

f = open('race.in', 'r')
entries = f.readlines()

for entry in entries[1:]:
    country, lastname = entry.split()
    if country in result:
        result[country].append(lastname)
    else:
        result[country] = [lastname]

f = open('race.out', 'w')
for key in sorted(result):
    print("=== {} ===".format(key), file=f)
    for name in result[key]:
        print(name, file=f)