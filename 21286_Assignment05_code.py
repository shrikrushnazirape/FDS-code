import math
class sort:
    #function to determine length of given array
    def getlen(self, lst):
        lst.append(-1)
        i=0
        while (lst[i] != -1):
            i+=1
        lst.remove(-1)
        return i

    # function to perform insertion sort 
    def insertion_sort(self,lst):
        i,key,j=0,0,0
        n=self.getlen(lst)
        for i in range (1,n):
            key=lst[i]
            j=i-1
            while (j>=0 and key < lst[j]):
                lst[j+1]=lst[j]
                j-=1
            lst[j+1]=key
        print("----------------Insertion Sort------------")
        print("Top 5 Scores")
        for i in range (-1,-6,-1):
            print(lst[i])
        print("------------------------------------------")

    #function for swap       
    def shell_sort(self, lst):
        n=self.getlen(lst)
        gap=n//2
        while (gap>0):
            for i in range (gap, n):
                temp=lst[i]
                j=i
                while  j >= gap and arr[j-gap] >temp: 
                    lst[j] = arr[j-gap] 
                    j -= gap 
                arr[j] = temp  
            gap =gap//2
        print("-----------Shell Sort-------------------")
        print("Top 5 Scores")
        for i in range (-1,-6,-1):
            print(lst[i])
        print("------------------------------------------")

# Taking the input of the user
t=int(input("Enter the Total No of student in class  "))
arr=[]
print("Enter the Scores")
for i in range (t):
    arr.append(float(input()))
s1=sort()

while True:
    print("1. Insertion Sort")
    print("2. Shell Sort")
    print("3. Exit\n")
    ch=int(input("Enter your Choice (from 1 to 3) :"))
    if ch==1:
        s1.insertion_sort(arr)
    elif ch==2:
        s1.shell_sort(arr)
    elif ch==3:
        break
    else:
        ("!!Wrong Choice!! ")



'''
OUTPUT

Enter the Total No of student in class  7
Enter the Scores
35.25
65.45
87.35
98.45
100.00
45.25
87.15
1. Insertion Sort
2. Shell Sort
3. Exit

Enter your Choice (from 1 to 3) :1
----------------Insertion Sort------------
Insertion Sort
Top 5 Scores
100.0
98.45
87.35
87.15
65.45
------------------------------------------
'''