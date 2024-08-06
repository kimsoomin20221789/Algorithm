s = input()
for i in s:
    if ord(i) >= 97:
        print(i.upper(), end='')
    else:
        print(i.lower(), end='')