import queue as Q
import re
from string import ascii_lowercase

patterns = [
    (r'\+$', 'add'),
    (r'-$', 'sub'),
    (r"\*$", 'mul'),
    (r"/$", 'div'),
    (r"%$", 'mod'),
    (r">([a-z])$", 'set_register'),
    (r"<([a-z])$", 'get_register'),
    (r"P$", 'print'),
    (r"P([a-z])$", 'print_register'),
    (r"C$", 'print_as_char'),
    (r"^C([a-z])$", 'print_as_char_register'),
    (r":(\w+)$", 'label'),
    (r"J(\w+)$", 'jmp'),
    (r"Z([a-z])(\w+)$", 'jz'),
    (r"E([a-z])(\w+)$", 'je'),
    (r"G([a-z])(\w+)$", 'jg'),
    (r"Q$", 'quit'),
    (r"(\d+)$", 'number')
]

queue = Q.Queue()
registers = dict(zip(ascii_lowercase, range(1,27)))
labels = dict()
trunc = 65536
class Actions:
    def add(self, m):
        result = (queue.get_nowait() + queue.get_nowait()) % trunc
        queue.put_nowait(result)
    def sub(self, m):
        result = (queue.get_nowait() - queue.get_nowait()) % trunc
        queue.put_nowait(result)
    def mul(self, m):
        result = (queue.get_nowait() * queue.get_nowait()) % trunc
        queue.put_nowait(result)
    def div(self, m):
        try:
            result = (queue.get_nowait() // queue.get_nowait()) % trunc
        except ZeroDivisionError:
            result = 0
        queue.put_nowait(result)
    def mod(self, m):
        try:
            result = (queue.get_nowait() % queue.get_nowait()) % trunc
        except ZeroDivisionError:
            result = 0
        queue.put_nowait(result)
    def set_register(self, m):
        registers[m.group(1)] = queue.get_nowait()
    def get_register(self, m):
        queue.put_nowait(registers[m.group(1)])
    def print(self, m):
        f.write('{}\n'.format(queue.get_nowait()))
    def print_register(self, m):
        f.write('{}\n'.format(registers[m.group(1)]))
    def print_as_char(self, m):
        f.write('{}\n'.format(chr(queue.get_nowait() % 256)))
    def print_as_char_register(self, m):
        f.write('{}\n'.format(chr(registers[m.group(1)] % 256)))
    def label(self, m):
        pass
    def jmp(self, m):
        ip = labels[m.group(1)] - 1
    def jz(self, m):
        if registers[m.group(1)] == 0:
            self.jmp(m.group(2))
    def je(self, m):
        if registers[m.group(1)] == registers[m.group(2)]:
            self.jmp(m.group(3))
    def jg(self, m):
        if registers[m.group(1)] > registers[m.group(2)]:
            self.jmp(m.group(3))
    def quit(self, m):
        ip = -100
    def number(self, m):
        queue.put_nowait(int(m.group(1)))

funcs = Actions()
def tick(string):
    for pat in patterns:
        res = re.match(pat[0], string)
        if res is None:
            continue

        # print(pat[1])
        getattr(funcs, pat[1])(res)

f = open('quack.in', 'r')
program = f.readlines()
f.close()
f = open('quack.out', 'w', newline='')

# обработать метки
for i in range(len(program)):
    line = program[i]
    m = re.match(r":(\w+)$", line)
    if m is None:
        continue
    labels[m.group(1)] = i

ip = 0
while ip > -1 and ip != len(program):
    tick(program[ip])
    ip += 1

# проблема с обработкой меток

# while not queue.empty():
#     print(queue.get_nowait())