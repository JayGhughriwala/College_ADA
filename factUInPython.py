import time
def factUsingRec (n):
    if n == 1:
        return 1
    else:
        return n * factUsingRec(n-1)


def factUsingIter(n):
    fact=1
    while(n>0):
        fact=fact*n
        n=n-1
        
    return fact

print("This is a program of finding a factorial")
num = int(input("Enter a number for finding a factorial"))
time_1 = time.time()
print("Factorial using a recursion ",factUsingRec(num))
time_1=time.time()-time_1

time_2 = time.time()
print("Factorial Using Iterative ",factUsingIter(num))
time_2 = time.time() - time_2

print("Time taken by the Recurion is ", time_1)
print("Time taken by the Iteratin is ", time_2)
