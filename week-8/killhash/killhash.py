def hashOf(string, const):
    rv = 0
    for char in string:
        rv = rv * const + ord(char)

    return rv

# x = 'helloworld'
# y = 'aaba'
const = 2
print(hashOf('abc', const))
# for const in range(2, 1024):
#     print(hashOf('a', const))