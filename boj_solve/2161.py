# n = int(input())
# list = [i for i in range (1, n+1)]
# while len(list) != 0:
#     print(list.pop(0), end = ' ')
#     if len(list) == 0:
#         break
#     list.append(list.pop(0))
    
list = [*range(int(input()))]
while len(list) != 0:
    print(list.pop(0)+1, end = ' ')
    if len(list) == 0:
        break
    list.append(list.pop(0))