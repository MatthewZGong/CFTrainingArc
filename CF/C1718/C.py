N = 32

arr = [i for i in range(N)]

cycles = set()

def test_cycle(N,start,k):
    ind = start
    val = 0
    visited = [0 for _ in range(N)]
    for i in range(N): 
        visited[ind] += 1
        # print(ind)
        val += arr[ind]
        ind += k
        ind %= N
    

    # print(start,k)
    # print(start,ind)
    assert start == ind
    # tuple(visited)
    cycles.add(tuple(visited))
    return tuple(visited)



# for i in range(N): 
#     for j in range(1,N-1): 
#         test_cycle(N, i, j)

# print(len(cycles))
for i in range(1,N):
    print(i,":",test_cycle(N,1,i))
    # print(test_cycle(N,0,9))

