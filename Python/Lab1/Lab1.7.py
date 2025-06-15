Lst = ['abc', 'xyz', 'aba', '1221'] 
New_Lst = []

cnt = 0

for i in Lst:
    L = len(i)
    if(i[0] == i[L-1]):
        New_Lst.append(i)
        cnt += 1

print(New_Lst)
print(cnt)        
