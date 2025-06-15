x = 3

while x > 0:
    N_hours = float(input("Enter the number of hours worked: "))
    rate = float(input("Enter the hourly rate: "))
    
    if N_hours > 40:
        salary = 1.5 * rate * N_hours
    else:
        salary = rate * N_hours
    
    print(salary)    
        
    