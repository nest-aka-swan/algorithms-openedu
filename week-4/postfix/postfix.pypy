f = open('postfix.in', 'r')

stack = []

for token in f.readline().split():
    try:
        number = int(token)
    except ValueError:
        if token == '+':
            a = stack.pop()
            b = stack.pop()
            stack.append(b + a)
            continue
        if token == '-':
            a = stack.pop()
            b = stack.pop()
            stack.append(b - a)
            continue
        if token == '*':
            a = stack.pop()
            b = stack.pop()
            stack.append(b * a)
            continue
    
    stack.append(number)

f = open('postfix.out', 'w')
f.write(str(stack.pop()))
    