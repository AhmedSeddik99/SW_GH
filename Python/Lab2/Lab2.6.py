F_old = open("report.txt", 'r')

F_new = open("New_report.txt", 'w')

cnt = 0

for line in F_old:
    if((line.find("setup") != -1) | (line.find("slack") != -1)):
        F_new.write(f"{cnt} - {line}")
    cnt += 1        



F_new.close()
