K = int(input())

for t in range(K):
    a,s,t=input().split(' ')
    
    if s in t or t in s:
        print(1)
        continue
    
    if set(s) | set(t) != set(a):
        print(0)
        continue
    
    diffs_s = 0
    for i in range(len(s) - 1):
        if s[i] != s[i+1]:
            diffs_s += 1
            
    diffs_t = 0
    for i in range(len(t) - 1):
        if t[i] != t[i+1]:
            diffs_t += 1
            
    if diffs_s > 1 or diffs_t > 1:
        print(0)
        continue
    
    print(1)
            
    
    
    