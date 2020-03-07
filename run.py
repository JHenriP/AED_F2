from subprocess import call

for i in range(1, 101):
    t = i*1000
    call("./F2B < inputs/input" + str(t) + ".txt >> F2B.csv", shell = True)
    call("./F2C < inputs/input" + str(t) + ".txt >> F2C.csv", shell = True)