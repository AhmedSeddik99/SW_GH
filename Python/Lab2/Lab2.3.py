import re

def my_function(str):
    up_cnt = 0
    low_cnt = 0
    for i in str:
        if(re.search(r'\w', i) != None):
            if(i == i.upper()):
                print(i)
                up_cnt += 1
            else:
                print(i)
                low_cnt += 1
    return up_cnt, low_cnt                
            


string = "I'm DIC Engineer at ITI"

(up_cnt, low_cnt) = my_function(string)
print(f"Upper case letters: {up_cnt}")
print(f"Lower case letters: {low_cnt}")

