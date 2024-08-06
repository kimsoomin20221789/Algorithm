# import sys
# input = sys.stdin.readline
# n = int(input())
# for i in range(n):
#     stack = []
#     a = input().rstrip('\n')
#     cnt = 0
#     for j in a:
#         if j == '(':
#             stack.append(j)
#             cnt += 1
#         elif j == ')':
#             if not stack:
#                 print('NO')
#                 break
#             else:
#                 cnt += 1
#                 stack.pop()
#     if not stack and (cnt == len(a)):
#         print('YES')
#     elif (cnt == len(a)):
#         print('NO')
#     else:
#         continue
import sys
input = sys.stdin.readline
n = int(input())
for i in range(n):
    stack = []
    a = input().rstrip('\n')
    for j in a:
        if j == '(':
            stack.append(j)
        elif j == ')':
            if not stack:
                print('NO')
                break
            else:
                stack.pop()
            # if stack:
            #     stack.pop()
            # else:
            #     print('NO')
            #     break
    else:
        if not stack:
            print('YES')
        else:
            print('NO')