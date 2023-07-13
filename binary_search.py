import random
import time

st = time.process_time()

def binary_search(arr, low, high, x):
 
    # Check base case
    if high >= low:
 
        mid = (high + low) // 2
 
        # If element is present at the middle itself
        if arr[mid] == x:
            return mid
 
        # If element is smaller than mid, then it can only
        # be present in left subarray
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        # Else the element can only be present in right subarray
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        # Element is not present in the array
        return -1
    
num=int(input("Enter maximum numbers of elements in array : "))
arr=[]
num=int(num)
for i in range(num):
    x=random.randint(0,9)
    #print(x)
    arr.append(i+x)
find = int(input("Enter element to find : "))
print("Array is : ",arr)

st1 = time.process_time()
result = binary_search(arr,0,len(arr)-1,find)
et1 = time.process_time()

if(result==-1):
    print("Element not found.")
else:
    print("Element found.!!! at index",str(result))

et = time.process_time()
res=et-st
print("Execution time of whole program : ",res)
res1=et1-st1
print("Execution time of binary search : ",res1)