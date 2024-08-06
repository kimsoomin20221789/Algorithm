month, day = input().split()

date = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
list1 = list(range(1, int(month)+1))
realDay = int(day)
for i in list1:
    i -= 1
    if i in [1, 3, 5, 7, 8, 10, 12]:
        realDay += 31
    elif i in [4, 6, 9, 11]:
        realDay += 30
    elif i == 2 :
        realDay += 28
    else:
        continue
print(date[(realDay - 1) % 7])