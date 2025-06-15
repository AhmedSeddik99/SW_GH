Func_Name = input("Enter function name: ")
No_Arg = int(input("Enter number of arguments: "))

Arg_Name = []

for i in range(0, No_Arg):
    Arg_Name.append(input("Enter argument name: "))
    
# print(Arg_Name)    

F = open("func_temp.txt",'w')

F.write(f"def {Func_Name}(")
for i in range(0, len(Arg_Name)):    
    if(i == (len(Arg_Name)-1)):
        F.write(f"{Arg_Name[i]}")
    else:        
        F.write(f"{Arg_Name[i]}, ")
    
F.write(f")")

F.write("\n\t------- Code ---------")
F.write("\nreturn")



F.close()
