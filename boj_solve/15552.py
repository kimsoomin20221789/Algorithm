import sys
n = int(input())
result = []
input = sys.stdin.readline
for i in range(n):
    a, b = map(int, input().rstrip('\n').split())
    result.append(a+b)

for i in range(n):
    print(result[i])
