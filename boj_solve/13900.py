import sys
input = sys.stdin.readline

total = 0
n = int(input())
list1 = list(map(int, input().split()))
sum = sum(list1)
for pivot in list1:
    sum -= pivot
    total += pivot * sum
print(total)