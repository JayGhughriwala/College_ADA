import time
import random
print("Linear Search Program in a python")

def linearSearch(element,ls):
    flag = False
    index=0
    for i in range(len(ls)):
        if ls[i] == element:
            index = i
            flag = True
            break
    
    if flag == True:
        print("Element Found at the index ",index)
    else:
        print("Element Not found in the array")



print("This is starting of a program")
ls = []

element = int(input("Enter a Element to find in the list "))

for i in range(1000):
    val = random.randint(0,10000)
    ls.append(val)
linearSearch(element,ls)

