
str = input("Enter the word to start the game: ")
str = str.lower()
print(str)

in_str = ""
final_str = ""


end_flag = 0

L = len(str)

cnt = 0
allowed = 3             

Lst = ['_']
Lst = L*Lst 

 
idx = 0
idx1 = 0
start = 0


while end_flag == 0:
    ch = input("Enter a character: ")
    ch = ch.lower() 
    
    if(in_str.find(ch) != -1):
        allowed -= 1  
        print("This Character has been entered before and ", allowed, "mistakes allowed")  
        
    else:
        in_str += ch
        if(str.find(ch) != -1):
            for j in range(0, L):    
                if(str[j] == ch):                                
                    Lst[j] = ch
                    cnt += 1
            
            if(cnt == L):
                end_flag = 1                              
                      
        else:
            allowed -= 1
            print("This Character is not in the string and ", allowed, "mistakes allowed")     
            if(allowed == 0):
                end_flag = 1


for w in Lst:
    final_str += w

print(final_str)
        
                    
   


