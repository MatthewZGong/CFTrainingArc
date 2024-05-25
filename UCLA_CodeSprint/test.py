# Sample Input:
# [
#     [(1,1),(2,2),(4,4)],  
#     [(2,1),(4,2)],  
#     [(3,3),(6,6)],  
#     [(7,7),(8,8)]
# ]

# Sample Output:
# [
#     [(1,1),(2,2),(3,3),(4,4),(6,6)],
#     [(7,7),(8,8)],
#     [(2,1),(4,2)]
# ]

#(4,4)(4,4)

def merge_line_on_slope(lines): 
    points = []
    for line in lines: 
        for i,point in enumerate(line):
            x,y = point
            if(i == 0): 
                points.append((point, 1)) 
            elif(i == len(line)-1): 
                points.append((point,-1))
            else:
                points.append((point,0))
    points.sort()  
    new_lines = [] 
    #init 
    current_line = [points[0][0]]
    i = 0
    ballance = 0
    while(i < len(points) and current_line[-1] == points[i][0] ): 
        ballance += points[i][1]
        i += 1
    while(i < len(points)):
        current_line.append(points[i][0])
        while(i < len(points) and current_line[-1] == points[i][0] ): 
            ballance += points[i][1]
            i += 1 
        if(ballance == 0): 
            new_lines.append(current_line)
            current_line = [] 
    return new_lines


        
def get_slope(line):
    '''
        y2-y1/x2-x1
        y = mx+b 
        y-mx = b
    ''' 
    x1,y1 = line[0]
    x2,y2 = line[-1]
    slope = (y2-y1)/(x2-x1)
    intercept = y1-slope*x1 
    return (slope,intercept)


def merge_lines(lines): 
    slopes = {} 
    for line in lines: 
        slope = get_slope(line)
        slopes.setdefault(slope,[]).append(line)
    res = []
    for slope in slopes: 
        for line in merge_line_on_slope(slopes[slope]): 
            res.append(line)
    return res

lines =  [
     [(1,1),(2,2),(4,4)],  
     [(2,1),(4,2)],  
     [(2,2), (4,4),(6,6)],  
     [(7,7),(8,8)]
    ]

lines = [[(0,0),(1,1)],  [(1,1),(2,2)],  [(0,1),(1,3)],  [(0.5,2),(2,5)]]
# Expected Output:
# [[(0,0),(1,1),(2,2)],  [(0,1),(0.5,2),(1,3),(2,5)]]

print(merge_lines(lines))
    