import random

for i in range(1, 101):
    t = i*1000

    f = open("inputs/input" + str(t) + ".txt", "w")
    f.write(str(t) + "\n")
    for j in range(t):
        if j < t-1:
            f.write(str(random.randint(0,255)) + " ")
        else:
            f.write(str(random.randint(0,255)))
    
    f.close()