import sys
N, K = map(int, input().split())
input = sys.stdin.readline

list1 = list(range(1, N+1))

result = []
j = 0
for i in range(N):
    j += K-1
    if j >= len(list1)-1:
        j = j % len(list1)
    result.append(str(list1.pop(j)))
# print(result)
print("<", ", ".join(result)[:], ">", sep = '')