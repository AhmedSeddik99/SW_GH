F_old = open("Lab2.5.txt", 'r')

F_new = open("New_Lab2.5.txt", 'w')

i = 0
cnt = 1

for line in F_old:
    if(line.find("DIC") != -1):
        print(line)
        F_new.write(f"{cnt} - DIC\n")
        cnt +=1
    i += 1        

F_new.close()


