#거리의 합 , r1 + r2 
import sys
n = int(input())
input = sys.stdin.readline
for i in range(n):
    list1 = list(map(int, input().rstrip('\n').split()))
    a = (list1[2] + list1[5])**2
    distance = (list1[0]-list1[3])**2 + (list1[1]-list1[4])**2
    
    if [list1[0], list1[1]] == [list1[3], list1[4]]:
        if list1[2] == list1[5]:
            print(-1)
        else:
            print(0)
    elif (distance == a) or (distance == (list1[2]-list1[5])**2):
        print(1)
        
    elif (distance < a) and (distance > (list1[2]-list1[5])**2):
        print(2)
    else:
        print(0)