t = input()
t = int(t)
def is_valid_isbn10(isbn): 
    sections = isbn.split("-")
    #more than 3 hyphens
    if(len(sections) > 4): 
        return False
    #last hyphen must split
    if(len(sections) == 4): 
        if( len(sections[-1]) != 1 ): 
            return False
    #no adj hyphens: 
    for sec in sections: 
        if len(sec) == 0: 
            return False
    total = 0
    digit_num = 10
    for i,digit in enumerate(isbn): 
        if digit == "-": 
            continue
        elif digit == "X" and i != len(isbn)-1: 
            return False
        elif i == len(isbn)-1: 
            continue 
        elif digit.isnumeric():
            total += int(digit)*digit_num
            digit_num -= 1
        else: 
            return False
    if digit_num != 1: 
        return False

    check_sum = isbn[-1]
    if check_sum.isnumeric(): 
        total += int(check_sum)
    elif check_sum == 'X': 
        total += 10 
    else: 
        return False 

    return total%11 == 0


def covert_to_isbn13(isbn):
    #remove the checksum
    isbn = "978-"+isbn[:-1]
    odd = True
    total = 0
    for i, digit in enumerate(isbn): 
        if digit == '-': 
            continue
        else: 
            if odd: 
                total += int(digit)
            else:
                total += 3*int(digit)
            odd = not odd 
    total %= 10
    if total == 0: 
        isbn += "0"
    else: 
        isbn += str(10-total)
    return isbn 
    


for i in range(t): 
    isbn = input()
    # print(isbn)
    if is_valid_isbn10(isbn): 
        print(covert_to_isbn13(isbn))
    else: 
        print("invalid")

