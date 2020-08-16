class set:
    def __init__(self,comp_student,cricket_playing, badminton_playing, football_playing):
        self.comp_student=comp_student
        self.badminton_playing=badminton_playing
        self.football_playing=football_playing


    #_________________________functin for cheak is the element is present in the list or not (repacement of " in or " "not in")
    def pin(self,lst, elem):
        flag= False
        for i in range (len(lst)):
            if(lst[i]==elem):
                flag=True
        return flag
     #_____________________________function to find the intersection of the two set
    def intersection(self,lst1,lst2):
        lst3=[]
        for i in range (len(lst1)):
            for j in range (len(lst2)):
                if(lst1[i]==lst2[j]):
                    lst3.append(lst1[i])
        return lst3
    # ---------------------------------function to find the union of the two set
    def union(self,list1, list2):
        list3=list1.copy()
        for i in range (len(list2)):
            if(self.pin(list2,list2[i])==False):
                list3.append(list2[i])
        return list3
    #-----------------------------------Function to find the Difference to the two set
    def diff(self,lst1, lst2):
        lst3=[]
        for i in range (len(lst1)):
            if (self.pin(lst2, lst1[i])== False):
                lst3.append(lst1[i])
        return(lst3)
    # ------------------------------------function for finding symetric difference which 
    def diff2(self,lst1,lst2):
        a1=self.union(lst1, lst2)
        a2=self.intersection(lst1, lst2)
        D1=self.diff(a1,a2)
        return D1

    # function for finding the parameters in the assignment
    # 1......List of students who play both cricket and badminton.
    def cricket_badminton(self):
        lst1=cricket_playing
        lst2=badminton_playing
        print("no of student who play both cricket and badminton",len(self.intersection(lst1, lst2)))
        print("list of student who play both cricket and badminton",self.intersection(lst1, lst2))
        return len(self.intersection(lst1, lst2))

    # 2..........List of students who play either cricket or badminton but not both.

    def only_cricket_o_badminton(self):
        lst1=cricket_playing
        lst2=badminton_playing
        print("no of student who play either cricet or badminton but not both",len(self.diff2(lst1, lst2)))
        print("list of student who play either cricet or badminton but not both",self.diff2(lst1, lst2))
        return len(self.diff2(lst1, lst2))

    # 3........ Function for finding Number of students who play neither cricket nor badminton

    def no_N_cricket_badminton(self):
        lst1=comp_student
        lst2=cricket_playing
        lst3=badminton_playing
        lst4=self.diff(lst1,self.union(lst2,lst3))
        print(" no of students who play neither cricket nor badminton is : ",len(lst4))
        print("\n\nList of students who play neither cricket nor badminton is : ",lst4)
        return len(lst4)

    # 4............  Number of students who play cricket and football but not badminton

    def no_cricket_badminton_N_football(self):
        lst1=cricket_playing
        lst2=football_playing
        lst3=badminton_playing
        lst4 = self.diff(self.intersection(lst1,lst2),lst3)
        print("no of student who play cricket and football but not badminton    :",len(lst4))
        print("\n\nList of students who play cricket and football but not badminton is : ",lst4)
        return len(lst4)

# ____________________Function for taking Input from the User ______________________________________________

comp_student=[]
cricket_playing=[]
badminton_playing=[]
football_playing=[]
print("Totle no of student in comp department")
n_comp_department=int(input())
print('Enter the name of student(each on new line)')
for i in range (n_comp_department):
    comp_student.append(input())
print("No of student who play cricket")
n_cricket=int(input())
print("enter name of student who play cricket(each on new line)")
for i in range (n_cricket):
    cricket_playing.append(input())
print("No of student who play badminton")
n_badminton=int(input())
print("enter name of student who play badminton(each on new line)")
for i in range (n_badminton):
    badminton_playing.append(input()) 
print("No of student who play football")
n_football=int(input())
print("enter name of student who play football(each on new line)")
for i in range (n_football):
    football_playing.append(input())
print("_____________________________________________________________")
print("no of student in comp department", n_comp_department)
print(comp_student)
print("no of student who play cricket",n_cricket)
print(cricket_playing)
print("no of student who play badminton",n_badminton)
print(badminton_playing)
print("no of student who play football",n_football)
print(football_playing)
print("______________________________________________________________")
# ________________________________________________Main function for the menu driven program

s1=set(comp_student,cricket_playing,badminton_playing,football_playing)

while True:
    print("_______________________________________________________________")
    print("1. both cricket and badminton")
    print("2. either cricket or badminton but not both")
    print("3. neither cricket nor badminton")
    print("4.  cricket and football but not badminton")
    print("5. Exit\n")
    ch=int(input("Enter your Choice (from 1 to 5) :"))
    print("_________________________________________________________________")
    if ch==1:
        ( s1.cricket_badminton())
    elif ch==2:
        ( s1.only_cricket_o_badminton())
    elif ch==3:
        ( s1.no_N_cricket_badminton())
    elif ch==4:
        ( s1.no_cricket_badminton_N_football())
    elif ch==5:
        break
    else:
        ("!!Wrong Choice!! ")

'''
Output of the program
----------------------------********---------------------------------------
Totle no of student in comp department
5
Enter the name of student(each on new line)
a
b
c
d
e
No of student who play cricket
2
enter name of student who play cricket(each on new line)
a
b
No of student who play badminton
2
enter name of student who play badminton(each on new line)
b
c
No of student who play football
2
enter name of student who play football(each on new line)
c
d
_____________________________________________________________  
no of student in comp department 5
['a', 'b', 'c', 'd', 'e']
no of student who play cricket 2
['a', 'b']
no of student who play badminton 2
['b', 'c']
no of student who play football 2
['c', 'd']
______________________________________________________________ 
_______________________________________________________________
1. both cricket and badminton
2. either cricket or badminton but not both
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit

Enter your Choice (from 1 to 5) :1
_________________________________________________________________
no of student who play both cricket and badminton 1
list of student who play both cricket and badminton ['b']
_______________________________________________________________
1. both cricket and badminton
2. either cricket or badminton but not both
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit

Enter your Choice (from 1 to 5) :2
_________________________________________________________________
no of student who play either cricet or badminton but not both 1
list of student who play either cricet or badminton but not both ['a']
_______________________________________________________________
1. both cricket and badminton
2. either cricket or badminton but not both
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit

Enter your Choice (from 1 to 5) :3
_________________________________________________________________
 no of students who play neither cricket nor badminton is :  3


List of students who play neither cricket nor badminton is :  ['c', 'd', 'e']
_______________________________________________________________
1. both cricket and badminton
2. either cricket or badminton but not both
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit

Enter your Choice (from 1 to 5) :4
_________________________________________________________________
no of student who play cricket and football but not badminton    : 0


List of students who play cricket and football but not badminton is :  []
_______________________________________________________________
1. both cricket and badminton
2. either cricket or badminton but not both
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit

Enter your Choice (from 1 to 5) :2
_________________________________________________________________
no of student who play either cricet or badminton but not both 1
list of student who play either cricet or badminton but not both ['a']
_______________________________________________________________
1. both cricket and badminton
2. either cricket or badminton but not both
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit

Enter your Choice (from 1 to 5) :3
_________________________________________________________________
 no of students who play neither cricket nor badminton is :  3


List of students who play neither cricket nor badminton is :  ['c', 'd', 'e']
_______________________________________________________________
1. both cricket and badminton
2. either cricket or badminton but not both
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit

Enter your Choice (from 1 to 5) :4
_________________________________________________________________
no of student who play cricket and football but not badminton    : 0


List of students who play cricket and football but not badminton is :  []
_______________________________________________________________
1. both cricket and badminton
2. either cricket or badminton but not both
3. neither cricket nor badminton
4.  cricket and football but not badminton
5. Exit

Enter your Choice (from 1 to 5) :5
_________________________________________________________________
'''

