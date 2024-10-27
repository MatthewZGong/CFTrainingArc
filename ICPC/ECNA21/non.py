N = int(input())
arr = [-10000000000000]
while len(arr) < N+1:
    arr += list(map(int, input().split()))

s = [0]
ans = 0
a,b = 0,0
for i in range(1, N+1):
    while arr[s[-1]] > arr[i]:
        s.pop()
  
    print(i, s[-1], (i-s[-1])*arr[i])
    if (i-s[-1]) * arr[i] > ans:
        ans = max(ans, (i-s[-1])*arr[i])
        a,b = s[-1], i

    s.append(i)
    print(s)
while len(s) > 1: 
    cur = s.pop()
    weeks = cur - (s[-1] if len(s) > 0 else 0)

    expected = arr[s[-1]] if len(s) else 0
    if weeks* expected >= ans: 
        ans = weeks *expected 
        if s[-1] 

    
    pass
print(s)

print(a,b,ans)