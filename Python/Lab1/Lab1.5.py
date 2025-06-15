x = 3


GPA = float(input("Enter your GPA: "))
Exp = int(input("Enter your Experience: "))

Master = input("Do you have Master: ")
if(str.capitalize(Master) == "Yes"):
    Master = 1
else:
    Master = 0

MBA = input("Do you have MBA: ")
if (str.capitalize(MBA) == "Yes"):
    MBA = 1
else:
    MBA = 0
    
 
if (GPA > 3.8):
    if((Master == 1) and (MBA == 1) and (Exp > 15)):
        Emp = "Manager"
        
if(GPA > 3.6):
    if((Master == 1) and ((Exp <= 15) and (Exp > 10))):    
        Emp = "Staff Senior"
    elif((Exp <= 10) and (Exp > 5)):
        Emp = "Senior"
        
if(GPA > 3.4):
    if((Exp <= 5) and (Exp > 3)):
        Emp = "Team Leader"

if(GPA > 3):
    if(Exp > 1):
        Emp = "Standard"

if(GPA > 2.5):
    if(Exp < 1):
        Emp = "Junior"
        
    
    
print(Emp)        
    
