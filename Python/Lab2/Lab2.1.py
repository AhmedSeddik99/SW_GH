def my_function(*Lst):
    sum = 0
    mult = 1
    for i in Lst:
        sum += i
        mult *= i
    
    print("sum = ", sum)        
    print("mult = ", mult)        
    
    # return sum, mult

 
my_function(8, 2, 3, 0, 7)     
