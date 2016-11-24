f = open('map.in', 'r')

input = "".join(f.readline().split())
n = len(input)
result = 0
prefix = [x[:] for x in [[0] * 26] * (n + 1)]

for i in range(1, n + 1):
    prefix[i] = prefix[i - 1]
    prefix[i][ord(input[i - 1]) - 97] += 1

for i in range(1, n - 1):
    for j in range(26):
        result += prefix[i][j] * (prefix[n][j] - prefix[i + 1][j])

print(prefix)