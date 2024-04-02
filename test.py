from functools import cache

@cache
def series(n): 
    if n == 0: 
        return 1 
    res = 0;
    for i in range(n):
        res += series(i)
    return res


for i in range(20): 
    print(series(i))

for i in range(20): 
    print((2**(i)))