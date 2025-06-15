
x = 3

while x > 0:
    score = int(input("Enter yout score: "))
    if (score > 100):
        print("Error, Score should be < 100")
    elif (score <= 100 and score >= 85):
        print("Grade: A")
    elif(score <= 84 and score >= 75):  
        print("Grade: B")
    elif(score <= 74 and score >= 65):
        print("Grade: C")
    elif(score <= 64 and score >= 60):
        print("Grade: D")
    else:
        print("Grade: F")


