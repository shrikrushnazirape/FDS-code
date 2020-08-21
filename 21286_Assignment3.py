class matrix:

# function for taking single matrix input which takes row and column parameter and return a single 2D matrix
    def getone(self,r,c):
        mat=[]
        for i in range (r):
            sub_mat=[]
            for j in range (c):
                sub_mat.append(int(input()))
            mat.append(sub_mat)
        return mat

# # function for addition of two matrices
    def add(self):
        row=int(input("Enter the no of rows     :"))
        column=int(input("Enter the no of column    :"))
        print("Enter the first matrix   ")
        mat1=self.getone(row, column)
        print("Enter the second matrix  ")
        mat2=self.getone(row, column)
        print("Addition of two matrix is") 
        for i in range (row):
            for j in range (column):
                print(mat1[i][j]+mat2[i][j], end="  ")
            print(" ")


 # function for subtraction of two matrices
    def sub(self):
        row=int(input("Enter the no of rows     :"))
        column=int(input("Enter the no of column    :"))
        print("Enter the first matrix")
        mat1=self.getone(row, column)
        print("Enter the second matrix")
        mat2=self.getone(row, column) 
        print("subtraction of two matrix is") 
        for i in range (row):
            for j in range (column):
                print(mat1[i][j]-mat2[i][j], end="  ")
            print(" ")

#Function for multiplication of two matrix
    def multi(self):
        r1=int(input("Enter the no of rows      :"))
        c1=int(input("Enter the no of columns   :"))
        r2,c2=c1, r1
        print("Enter the first matrix")
        mat1=self.getone(r1,c1)
        print("Enter the second matrix")
        mat2=self.getone(r2,c2)
        print("Multiplication of two marix is")
        for i in range (r1):
            for j in range (c2):
                result=0
                for k in range(r2):
                    result += mat1[i][k] * mat2[k][j]
                print(result, end=" ")
            print("")


#function for transpose of given matrix
    def trans(self):
        r=int(input("Enter the No of rows       :"))
        c=int(input("Enter the No of columns    :"))
        matrix=self.getone(r,c)
        print("you have Entered the matrix  :",matrix)
        print("Transpose of given matrix    :")
        for i in range (c):
            for j in range (r):
                print(matrix[j][i], end=" ")
            print("")
        
s1=matrix()
while True:
    print("_______________________________________________________________")
    print("1.  Addition of two matrices")
    print("2.  subtraction of two matrices")
    print("3.  Multiplication of two matrices")
    print("4.  Transpose of matrix")
    print("5.  Exit ")
    ch=int(input("Enter your Choice (from 1 to 5) :"))
    print("_________________________________________________________________")
    if ch==1:
        s1.add()
    elif ch==2:
        s1.sub()
    elif ch==3:
        s1.multi()
    elif ch==4:
        s1.trans()
    elif ch==5:
        print("Ending the Program")
        break
    else:
        print("!!Wrong Choice!! ")

        
'''
OUTPUT:>>>>>
_______________________________________________________________
1.  Addition of two matrices      
2.  subtraction of two matrices   
3.  Multiplication of two matrices
4.  Transpose of matrix
5.  Exit 
Enter your Choice (from 1 to 5) :1
_________________________________________________________________
Enter the no of rows     :3
Enter the no of column    :3
Enter the first matrix   
1
2
3
4
5
6
7
8
9
Enter the second matrix  
1
2
3
4
5
6
7
8
9
Addition of two matrix is
2  4  6   
8  10  12
14  16  18
_______________________________________________________________
'''