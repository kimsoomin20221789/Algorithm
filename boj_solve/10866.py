import sys
from collections import deque
d = deque()
input = sys.stdin.readline
n = int(input())
for i in range(n):
    list = input().rstrip('\n').split()
    if list[0] == 'push_back':
        d.append(list[1])
    elif list[0] == 'push_front':
        d.appendleft(list[1])
    elif list[0] == 'front':
        if len(d) == 0:
            print(-1)
        else:
            print(d[0])
    elif list[0] == 'back':
        if len(d) == 0:
            print(-1)
        else:
            print(d[-1])
    elif list[0] == 'pop_front':
        if len(d) == 0:
            print(-1)
        else:
            print(d.popleft())
    elif list[0] == 'pop_back':
        if len(d) == 0:
            print(-1)
        else:
            print(d.pop())
    elif list[0] == 'size':
        print(len(d))
    elif list[0] == 'empty':
        if len(d) == 0:
            print(1)
        else:
            print(0)