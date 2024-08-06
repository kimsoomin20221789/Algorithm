import sys
input = sys.stdin.readline
first = input().rstrip('\n')
if int(first) < 10:
    firstList = list(str(first))
    firstList.insert(0, '0')
    first = '0' + str(first)
else:
    firstList = list(first)
result = 0
cnt = 0
while first != result:
    sum1 = sum(list(map(int, firstList)))
    result = firstList[-1] + str(sum1)[-1]

    cnt += 1
    firstList = list(result)
print(cnt)