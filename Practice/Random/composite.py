# def amount_of_composite(n):
#     i = 1;
#     count = 0
#     while(i*i <= n):
#         if(n%i == 0):
#             if(i*i == n): 
#                 count += 1
#             else:
#                 count += 2
#         i += 1
#     return count
        

# def most_composite(n): 
#     res = 1
#     num = amount_of_composite(1);
#     vals = []
#     for i in range(2, n):
#         vals.append((-amount_of_composite(i),i))

#     return vals
# res = most_composite(50_000);
# res.sort()
# # reversed(res)
# print(res[:100])
# c_sum = 0
# for i in range(100): 
#     c_sum += (-res[i][0])**3
# print(c_sum)


# def find_solutions(n): 
#     res = []
#     for i in range(1, n):

#     return res
import math
def solve(n): 
    start = n//4+1
    end = (3*n)//4 
    
    for a in range(start, end):
        dem = 4*a-n; 
        num = a*n;
        gcd = math.gcd(num,dem)
        dem //= gcd
        num //= gcd 
        b_start =num//dem+1
        b_end = 2*(num//dem)

        if(dem == 1): 
            print(a, num+1,num*(num+1))
            return
        # print(a)
        print(b_start,b_end)
        for b in range(b_start, b_end):
            # print(b)
            top = b*dem-num 
            bot = b*num 
            if(bot%top == 0):
                print(a,b,bot//top)
                return

for i in range(49_000,50_000): 
    print(i)
    solve(i)

solve(13)
solve(529)
solve(49849)
solve(49850)
solve(18)