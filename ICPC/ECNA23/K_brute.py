import random
def get_all(length):
    if length == 0: 
        return [""]
    res = [] 
    for word in get_all(length-1):
        for i in range(26):
            res.append(word+chr(ord('A')+i))
    return res 
with open("test.txt",'w') as f:
    words = get_all(3)
    visited = set()  
    subset = []
    while(len(visited) < 1000): 
        ind = random.randint(0,len(words)-1)
        if ind not in visited:
            visited.add(ind)
            subset.append(words[ind])
    
    for w in subset: 
        f.writelines(w+'\n')

def unique(words): 
    s
