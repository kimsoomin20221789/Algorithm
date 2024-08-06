a = [1,2,3]
for i in range(3):
    if i==2:
        a.remove(a[i])
    print(a[i])