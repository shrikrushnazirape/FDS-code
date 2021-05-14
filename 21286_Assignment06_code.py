class sort:
    #recursive call for the quick sort function
    def quickSort(self,arr,low,high): 
        if low < high:  
            pi = self.part(arr,low,high) 
            self.quickSort(arr, low, pi-1) 
            self.quickSort(arr, pi+1, high) 
    #function for sorting the array left to pivote and right to pivote and return pivote index
    def part(self,arr,low,high): 
        pindex = low-1
        pivot = arr[high]    
        for j in range(low , high): 
            if arr[j] <= pivot: 
                pindex +=1
                arr[pindex],arr[j] = arr[j],arr[pindex] 
                
        arr[pindex+1],arr[high] = arr[high],arr[pindex+1] 
        return ( pindex +1 )

#function for printing top 5 score
    def topper(self, lst):
        print("------------------------------------------")
        print("Top 5 Scores")
        for i in range (-1,-6,-1):
            print(lst[i])
        print("------------------------------------------")
t=int(input("Enter the total no of  "))
lst=[]
for i in range (t):
    lst.append(float(input()))


    
s1=sort()
while True:
    print("1. Sort Numbers using the quick sort")
    print("2. Exit\n")
    ch=int(input("Enter your Choice (from 1 to 2) :"))
    if ch==1:
        print("Before Sorting",lst)
        s1.quickSort(lst,0,t-1)
        print("After Sorting",lst)
        s1.topper(lst)
    elif ch==2:
        break
    else:
        print("!!Wrong Choice!! ")



'''Output:


Enter the total no of student5
10.25
45.32
14.32
56.32
11.12
1. Sort Numbers using the quick sort
2. Exit

Enter your Choice (from 1 to 2) :1  
Before Sorting [10.25, 45.32, 14.32, 56.32, 11.12]
After Sorting [10.25, 11.12, 14.32, 45.32, 56.32] 
------------------------------------------        
Top 5 Scores
56.32
45.32
14.32
11.12
10.25
------------------------------------------
1. Sort Numbers using the quick sort
2. Exit
'''