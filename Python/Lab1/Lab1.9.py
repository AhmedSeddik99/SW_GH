str = "0123456789"
str_even = ""
str_odd  = ""
str_div3 = ""
str_rvr  = ""

L = len(str)


for i in str:
    if ((int(i) % 2) == 0):
        str_even += i
    else:    
        str_odd += i
    
    if ((int(i) % 3) == 0):
        str_div3 += i    
    
    
    idx = L - str.index(i) - 1
    print(idx)
    
    str_rvr += str[idx]
            
    
                
print ("Even: ", str_even)    
print ("Odd : ", str_odd)    
print ("Div3: ", str_div3)    
print ("Rvr : ", str_rvr)    
   