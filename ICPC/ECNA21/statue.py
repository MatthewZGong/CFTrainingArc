dims = input().split(' ')
n, m = map(int, dims)

park = [] 
ascending = [] 
descending = []
for r in range(n): 
    row = input().split(' ')
    row = list(map(int, row))
    park.append(row)
    for value in row:
        if value != -1:
            ascending.append(value)
ascending.sort() 
descending = ascending[::-1]

def compare(ordering, start, actual): 
    expected = ordering[start:start+len(actual)]
    res = 0 
    for statue in actual: 
        res += (statue not in expected)
    return res 

SE = 0 
NW = 0 
NE = 0 
SW = 0 

used = 0 
for i in range(n-1, -1, -1): 
    row = i 
    column = 0 
    diagonal = []
    while row < n and column < m: 
        if(park[row][column] != -1):
            diagonal.append(park[row][column])
        row += 1 
        column += 1 
    NE += compare(descending, used, diagonal)
    SW += compare(ascending, used, diagonal)
    used += len(diagonal)

for i in range(1, m): 
    column = i
    row = 0 
    diagonal = []
    while row < n and column < m: 
        if(park[row][column] != -1):
            diagonal.append(park[row][column])
        row += 1 
        column += 1 

    NE += compare(descending, used, diagonal)
    SW += compare(ascending, used, diagonal)
    used += len(diagonal)


used = 0
for i in range(m): 
    column = i 
    row = 0 
    diagonal = []
    while row < n and column >= 0: 
        if(park[row][column] != -1):
            diagonal.append(park[row][column])
        row += 1 
        column -= 1
    SE += compare(descending, used, diagonal)
    NW+= compare(ascending, used, diagonal)
    used += len(diagonal)


for i in range(1, n): 
    row = i 
    column = m-1 
    diagonal = []
    while row < n and column >= 0:
        if(park[row][column] != -1):
            diagonal.append(park[row][column])
        row += 1 
        column -= 1
    SE += compare(descending, used, diagonal)
    NW += compare(ascending, used, diagonal)
    used += len(diagonal)

print(min(NW,SW,SE,NE))



        




