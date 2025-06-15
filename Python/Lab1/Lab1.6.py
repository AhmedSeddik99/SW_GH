
x = 3

while x > 0:
    num = float(input("Enter a number between 1.5 & 150: "))
    
    if (num > 1.5 and num < 150):
        print("Done, the Number is between 1.5 and 150")
        break
    else:
        print("Error, the Number is not between 1.5 and 150, try again")