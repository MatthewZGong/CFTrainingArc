import math 


# math.comb() 

s = "CACCABAABBABABBCBBCAAACAAACCCA"

k = 10
n = len(s)
count = [0]*3
for i in range(len(s)):
    count[ord(s[i])-ord('A')] += 1

a = count[0]
b = count[1]
c = count[2]
res = 0 
def solve(a,b,c): 
    values = [a,b,c]
    values.sort(reverse=True)
    a, i = values[0]
    b, j = values[1]
    c, k = values[2]
    res = math.comb(count[i], a)* math.comb(count[j], b)*math.comb(count[k], c) * math.comb(b+c, a) * math.comb(a+c,b)
    return res
for i in range(2, 2*k): 
    res += math.comb(a)

# complysci
