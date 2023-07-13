import random
#import array as arr

'''
def binary_search(start,end,find):
    mid=int(((start+end)/2))
    for find in range(start,end):
        if(find==arr_list[mid]):
            flag=1
            break
        elif(find<arr_list[mid]):
            binary_search(start,mid-1,find)
        elif(find>arr_list[mid]):
            binary_search(mid+1,end,find)
'''
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

def merge(arr,start,mid,end):
    n1=mid-start+1
    n2=end-mid
    
    #create temp arrays
    L=[0] * (n1)
    R=[0] * (n2)
    
    #copy data to temp arrays
    for i in range (0,n1):
        L[i] = arr[start+i]
    
    for j in range (0,n2):
        R[j] = arr[mid+1+j]
        
    #merge temp arrays back in arr
    i=0
    j=0
    k=start
    
    while i<n1 and j<n2:
        if L[i] <= R[j] :
            arr[k]=L[i]
            i += 1
        else :
            arr[k] = R[j]
            j += 1
        k += 1
        
    #Copy the remaining elements of L[], if there are any
    while i < n1:
        arr[k] = L[i]
        i += 1
        k +=1
        
    while j<n2:
        arr[k] = R[j]
        j += 1
        k += 1
   
def merge_sort(arr,start,end):
    if(start<end):
        mid= start+(end - start) // 2
        merge_sort(arr,start,mid)
        merge_sort(arr,mid+1,end)
        merge(arr,start,mid,end)

num=int(input("Enter maximum numbers of elements in array : "))
#num=100
arr=[]
#random.randint(0,9)
#num=int(num)
for i in range(num):
    x=random.randint(0,9)
    #print(x)
    arr.append(i+x)
finds = int(input("Enter element to find : "))
print("Input Array is : ",arr)

merge_sort(arr,0,len(arr)-1)

print("Output Array is : ",arr)
result = binary_search(arr,0,len(arr)-1,finds)
if(result==-1):
    print("Element not found.")
else:
    print("Element found.!!! at index",str(result))
    