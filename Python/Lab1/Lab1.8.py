Num_Lst = [10, 20, 30, 40, 50, 60]
L = len(Num_Lst)

Rvr_Lst = []

for i in Num_Lst:
    Rvr_Lst.append(Num_Lst[L-1])
    L = L - 1

print(Rvr_Lst)    