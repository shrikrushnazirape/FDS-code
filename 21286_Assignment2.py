class string:

#function to determine the longest string in the two string
    def longest_length(self):
        string1=str(input("Enter the first string           :"))
        string2=str(input("Enter the second string          :"))
        if(self.getlength(string1)>self.getlength(string2)):
            print("The Largest String is ", string1, "with the length ", self.getlength(string1))
        else:
            print("The Largest String is ", string2, "with the length ", self.getlength(string2))
#function to obtain freq of char
    def char_freq_op(self):
        string=str(input("Enter the string            :"))
        char=str(input("Enter the Char                :"))
        freq=self.char_freq(string, char)
        print("frequency of char", char, "in the string", string, "is ", freq)
  # function to check is the string is palindrome or not  
    def ispalindrome(self):
        string=str(input("Enter the string  :"))
        len_of_string=self.getlength(string)
        ans="Pallindrome"
        for i in range (int(len_of_string/2)):
            if(string[i] != string [(0-i)-1]):
                ans="Not Pallindrome"
                break
        print("Given string is", ans)

 # function to find first occurance of substring in the string  
    def first_occur(self):
        string1=str(input("Enter the string          :"))
        substring=str(input("Enter the Substring    :"))
        len1=self.getlength(string1)
        len2=self.getlength(substring)
        occur=[]
        for i in range (len1-len2+1):
            if string1[i: (i+len2)]== substring:
                occur.append(i)
        print("First occurance of" ,substring, "in the ",string1, " at the index", occur[0])

 # function to find all occurrences of the substring in the string    
    def alloccur(self):
        string1=str(input("Enter the string          :"))
        substring=str(input("Enter the Substring     :"))
        len1=self.getlength(string1)
        len2=self.getlength(substring)
        occur=[]
        for i in range (len1-len2+1):
            if string1[i: (i+len2)]== substring:
                occur.append(i)
        print("Totle occurrences of ", substring, "in the ", string1, "are",len(occur)," at index ", occur)
    
# -------------function for returning the length of given string_____________
    def getlength(self,str):
        count=0
        while str[count:]:
            count+=1
        return count

# -------------function for determining the frequency of given char in the string
    def char_freq(self, string, char):
        chr=char[0]
        len_of_string=self.getlength(string)
        count=0
        for i in range (len_of_string):
            if(string[i]==chr):
                count+=1
        return count  


s1=string()
# main program for menu and choice 
while (True):
    choice=0
    print("____________________________________________________________________")
    print("         Menu For the Program")
    print("1.   To display the word of longest length")
    print("2.   To display frequency of charecter")
    print("3.   To determine palindrome or not")
    print("4.   To display index of first appeerence of substring")
    print("5.   To display count of occurrence of each word in given string")
    print("6.   To End the program")
    choice = int(input("Enter Choice - "))
    print("______________________________________________________________________")
    if choice==1 :
        s1.longest_length()
    elif choice==2 :
        s1.char_freq_op()
    elif choice==3 :
        s1.ispalindrome()
    elif choice==4:
        s1.first_occur()
    elif choice ==5:
        s1.alloccur()
    elif choice ==6:
        print("Ending the Program")
        break
    else:
        print("Enter the Correct Choice")
   

'''OUTPUT >>>
____________________________________________________________________
         Menu For the Program
1.   To display the word of longest length
2.   To display frequency of charecter
3.   To determine palindrome or not
4.   To display index of first appeerence of substring
5.   To display count of occurrence of each word in given string
6.   To End the program
Enter Choice - 1
______________________________________________________________________
Enter the first string           :shrikrushna
Enter the second string          :krushna
The Largest String is  shrikrushna with the length  11
____________________________________________________________________
'''