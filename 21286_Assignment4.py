class sort:
    array=[]
    totle_student=0
    def __init__(self,list,n):
        self.array=list
        self.totle_student=n

#function to perform linear search
    def linear_search(self,key):
        count=0
        for i in range (self.totle_student):
            if(self.array[i]==key):
                count+=1
        if(count==0):
            print("not attended the training program")
        else:
            print(" attended the training program")

#function to perform sentinal search
    def sen_search(self,key):
        lst=self.array
        lst.append(99)
        count=0
        i=0
        while (lst[i]!=99):
            if(lst[i]==key):
                count+=1
            i+=1
        if(count==0):
            print("Not attended the training program")
        else:
            print("attended the training program")

#function to perform binary search
    def bin_search(self,key):
        ls=self.array
        n=self.totle_student
        mid, low, high = 0, 0, n - 1
        while low <= (high):
            mid = low + (high - low) // 2
            if ls[mid] == key:
                print("Attended the training program")
                break
            elif ls[mid] < key:
                low = mid + 1
            else:
                high = mid - 1
        else:
            print("Not attended the training program")

# function in fib search for returning the (m-2)th element in the fib series
    def rindex(self,n):
        f2 = 0
        f1 = 1
        f = 1
        index = 0
        while (f < n):
            f2 = f1
            f1 = f
            f = f1 + f2
            index = f1
        return index
# function for cheaking is the key element is present in the list or not
    def fibonacci(self,ls, n, key):
        flag, first, last = 0, 0, n - 1
        while (flag != 1 and first <= last):
            index = self.rindex(n)
            if (key == ls[index + first]):
                flag = 1
                break
            elif (key > ls[index + first]):
                first = first + index + 1
            else:
                last = first + index - 1
            n = last - first + 1
        if (flag == 1):
            print(" attended the training program")
        else:
            print("Not attended the training program")

# actual function of fib search which handles the user input
    def fib_search(self,key):
        ls=self.array
        n=self.totle_student
        self.fibonacci(ls,n,key)

# program for taking input from the user
n=int(input("Enter the no of student who attended the training program  :"))
lst=[]
print("Enter the roll no of student")
for i in range (n):
    lst.append(int(input()))
key=int(input("Enter the Roll no you want to search"))
searching=sort(lst, n)
while True:
    print("_________________________________________________________________")
    print("1.  Linear search")
    print("2.  Sentinel search")
    print("3.  Binary search")
    print("4.  Fibonacci search ​")
    print("5.  Exit ")
    ch=int(input("Enter your Choice (from 1 to 5) :"))
    print("_________________________________________________________________")
    if ch==1:
        searching.linear_search(key)
    elif ch==2:
        searching.sen_search(key)
    elif ch==3:
        searching.bin_search(key)
    elif ch==4:
        searching.fib_search(key)
    elif ch==5:
        print("Ending the Program")
        break
    else:
        print("!!Wrong Choice!! ")

'''OUTPUT:-
Enter the no of student who attended the training program  :5
Enter the roll no of student
1
2
3
4
5
Enter the Roll no you want to search5
_________________________________________________________________
1.  Linear search
2.  Sentinel search
3.  Binary search
4.  Fibonacci search ​
5.  Exit 
Enter your Choice (from 1 to 5) :4
_________________________________________________________________
 attended the training program
_________________________________________________________________
'''