def factorial(num):                         # fact(5) = 5*4*3*2*1
    if num > 1:
        return num * factorial(num - 1)
    else:
        return 1
    
    
x = int(input("Enter a number: "))
print(f"factorial of ", x, " is ",  factorial(x))    
    
    
