/*
Name                :- Shrikrushna S Zirape
Roll No             :- 21286
Assignment          :- Grpup C , assigment 8
Problem statement   :-

                    Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C++ program to store two sets using linked list. compute and display- 
                        a) Set of students who like both vanilla and butterscotch 
                        b) Set of students who like either vanilla or butterscotch or not both 
                        c) Number of students who like neither vanilla nor butterscotch

*/

#include<string.h>
#include<iostream>
using namespace std;
class student{
    int roll_no;
    string name;
    student *link;
public:
    student(){
        roll_no=0;
        name="student name";
        link=NULL;
    }
    student(int roll,string n){
        roll_no=roll;
        name=n;
        link=NULL;
    }
    friend class set;
};
class set{ 
    int total_in_set;
    student *head;
public:
    set(){
        head=NULL;
    }
    //adding node at the end of the linked list
    void create_student_node(int roll, string nm){
        student *temp=new student(roll, nm);
        if(head == NULL){
            head= temp;
        }
        else{
            student *temp2=head;
            while(temp2->link != NULL){
                temp2=temp2->link;
            }
            temp2->link=temp;
        }
    }
    //printing all members of the linked list
    void print_all_member(){
        if(head == NULL){
            cout<<"List is Empty No members to Show"<<endl;
        }
        student *temp=head;
        cout<<"------------------------------------------"<<endl;
        cout<<"Roll_no"<<"\t|\t"<<"Name of student"<<endl;
        cout<<"------------------------------------------"<<endl;
        while (temp != NULL){
            cout<<temp->roll_no<<"\t|\t"<<temp->name<<endl;
            temp=temp->link;
        }

    }
    //function to create set;
    void create_set(){
        int n,ro;
        string str;
        cout<<"Enrer the total no of student :";
        cin>>n;
        total_in_set=n;
        for (int i=0; i<n; i++){
            cout<<"Enter roll no :";
            cin>>ro;
            cout<<"Enter name :";
            cin>>str;
            create_student_node(ro,str);
        }
    }
    //function to check presence of emement
    bool is_present(int r){
        bool check=false;
        if(head == NULL){
            return false;
        }
        else{
            student *temp=head;
            while (temp != NULL){
                if(temp->roll_no == r){
                    check=true;
                }
                temp=temp->link;
            }
            return check;
        }
    }
    //function to calculate length of linked list
    int getlen(){
        int count=0;
        student *temp=head;
        while (temp !=NULL){
            count+=1;
            temp=temp->link;
        }
        return count;
    }
    // function to find union of two sets
    void union_set(set a, set b){
 
        student *t1 =  a.head;
        student *t2 =  b.head;
        while (t1 != NULL){
            if(is_present(t1->roll_no)==false){
                create_student_node(t1->roll_no, t1->name);
            }
            t1=t1->link;
        }
        while (t2 != NULL){
            if(is_present(t2->roll_no)==false){
                create_student_node(t2->roll_no, t2->name);
            }
            t2=t2->link;
        }
    }
    //fuction to find intersection of two set
    void intersection_set(set a, set b){
        student *temp=a.head;
        while(temp != NULL){
            if(b.is_present(temp->roll_no)){
        
                if(is_present(temp->roll_no) == false){
                create_student_node(temp->roll_no, temp->name);
                }
            }
            temp=temp->link;
        }
    }
    //function to determine difference of the two sets;
    void diff(set a, set b){
        student *temp=a.head;
        while (temp != NULL){
            if(b.is_present(temp->roll_no) == false){
                if(is_present(temp->roll_no) == false){
                create_student_node(temp->roll_no, temp->name);
                }
            }
            temp=temp->link;
        }
      
    }
    // function to determine symetric difference of the two sets (a union b )- (a intersection b)
    void sym_diff(set a, set b){
        set union_s, inter_s;
        union_s.union_set(a,b);
        inter_s.intersection_set(a,b);
        diff(union_s,inter_s);
    }

};

int main(){
    set comp_student, vanila , butterscotch, result1, result2, result3;
 
    while (true){
        int choice;
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"1.   Add Second Year Student"<<endl;
        cout<<"2.   Add Student Who like Vanilla Ice-cream"<<endl;
        cout<<"3.   Add a student who like butterscotch ice-cream"<<endl;
        cout<<"4.   Display students who like both vanilla and butterscotch"<<endl;
        cout<<"5.   Display students who like either vanilla or butterscotch or not both"<<endl;
        cout<<"6.   Display students who like neither vanilla nor butterscotch"<<endl;
        cout<<"7.   Exit"<<endl;
        cout<<"-------------------------------------------------------------------------"<<endl;
        cout<<"Enter Your Choice  ";
        cin>>choice;
        
            if (choice ==1){
                int t;
                cout<<"Enter Total no of student : ";
                cin>>t;
                for (int i=0; i<t; i++){
                    int roll;
                    string name;
                    cout<<"Enter the Roll No of student : ";
                    cin>>roll;
                    cout<<"Enter the Name of student : ";
                    cin>>name;
                    comp_student.create_student_node(roll, name);
                }
            }

            else if(choice ==2){

                int v;
                cout<<"Enter No of Student who like Vanila Ice-Cream : ";
                cin>>v;
                for (int j=0; j<v; j++){
                    int roll;
                    string name;
                    cout<<"Enter the Roll No of student : ";
                    cin>>roll;
                    cout<<"Enter the Name of student : ";
                    cin>>name;
                    vanila.create_student_node(roll, name);
                    if(comp_student.is_present(roll) == false){
                        comp_student.create_student_node(roll, name);
                    }
                }
            }
            else if (choice ==3) {
                
                 int b;
                cout<<"Enter No of Student who like butterscotch Ice-Cream : ";
                cin>>b;
                for (int k=0; k<b; k++){
                    int roll;
                    string name;
                    cout<<"Enter the Roll No of student : ";
                    cin>>roll;
                    cout<<"Enter the Name of student : ";
                    cin>>name;
                    butterscotch.create_student_node(roll, name);
                    if(comp_student.is_present(roll) == false){
                        comp_student.create_student_node(roll, name);
                    }
                }
            }

            else if (choice ==4){

                result1.intersection_set(vanila,butterscotch);
                cout<<"---------------------------------------------------"<<endl;
                cout<<"Student Who Likes Both Vanila as well as Butterscotch"<<endl;
                cout<<"---------------------------------------------------"<<endl;
                result1.print_all_member();
            }
            else if (choice ==5){
                result2.sym_diff(vanila, butterscotch);
                cout<<"---------------------------------------------------"<<endl;
                cout<<"Student Who Likes either vanilla or butterscotch but not both"<<endl;
                cout<<"---------------------------------------------------"<<endl;
                result2.print_all_member();
            }
            else if (choice ==6){
                
                set temp_union;
                temp_union.union_set(vanila,butterscotch);
                result3.diff(comp_student,temp_union);
                cout<<"---------------------------------------------------"<<endl;
                cout<<"Student Who Likes neither vanilla nor butterscotch"<<endl;
                cout<<"---------------------------------------------------"<<endl;
                result3.print_all_member();
            }

            else if(choice ==7){

                break;
            }
            
            else{

                cout<<"Wrong choice";
            }
        
    }

    return 0;
}

/*
OUTPUT:-

1.   Add Second Year Student
2.   Add Student Who like Vanilla Ice-cream
3.   Add a student who like butterscotch ice-cream
4.   Display students who like both vanilla and butterscotch
5.   Display students who like either vanilla or butterscotch or not both
6.   Display students who like neither vanilla nor butterscotch
7.   Exit
-------------------------------------------------------------------------
Enter Your Choice  1
Enter Total no of student : 6
Enter the Roll No of student : 1
Enter the Name of student : shrikrushna
Enter the Roll No of student : 2
Enter the Name of student : suyash
Enter the Roll No of student : 3
Enter the Name of student : shlok
Enter the Roll No of student : 4
Enter the Name of student : sahil
Enter the Roll No of student : 5
Enter the Name of student : utkarsh
Enter the Roll No of student : 6
Enter the Name of student : sid 
-------------------------------------------------------------------------
1.   Add Second Year Student
2.   Add Student Who like Vanilla Ice-cream
3.   Add a student who like butterscotch ice-cream
4.   Display students who like both vanilla and butterscotch
5.   Display students who like either vanilla or butterscotch or not both
6.   Display students who like neither vanilla nor butterscotch
7.   Exit
-------------------------------------------------------------------------
Enter Your Choice  1
Enter Total no of student : 1
Enter the Roll No of student : 7
Enter the Name of student : mota-bhai
-------------------------------------------------------------------------
1.   Add Second Year Student
2.   Add Student Who like Vanilla Ice-cream
3.   Add a student who like butterscotch ice-cream
4.   Display students who like both vanilla and butterscotch
5.   Display students who like either vanilla or butterscotch or not both
6.   Display students who like neither vanilla nor butterscotch
7.   Exit
-------------------------------------------------------------------------
Enter Your Choice  2
Enter No of Student who like Vanila Ice-Cream : 3
Enter the Roll No of student : 1
Enter the Name of student : shrikrushna
Enter the Roll No of student : 2
Enter the Name of student : suyash
Enter the Roll No of student : 3
Enter the Name of student : shlok
-------------------------------------------------------------------------
1.   Add Second Year Student
2.   Add Student Who like Vanilla Ice-cream
3.   Add a student who like butterscotch ice-cream
4.   Display students who like both vanilla and butterscotch
5.   Display students who like either vanilla or butterscotch or not both
6.   Display students who like neither vanilla nor butterscotch
7.   Exit
-------------------------------------------------------------------------
Enter Your Choice  3
Enter No of Student who like butterscotch Ice-Cream : 3
Enter the Roll No of student : 3
Enter the Name of student : shlok
Enter the Roll No of student : 4
Enter the Name of student : sahil
Enter the Roll No of student : 5
Enter the Name of student : utkarsh
-------------------------------------------------------------------------
1.   Add Second Year Student
2.   Add Student Who like Vanilla Ice-cream
3.   Add a student who like butterscotch ice-cream
4.   Display students who like both vanilla and butterscotch
5.   Display students who like either vanilla or butterscotch or not both
6.   Display students who like neither vanilla nor butterscotch
7.   Exit
-------------------------------------------------------------------------
Enter Your Choice  4
---------------------------------------------------
Student Who Likes Both Vanila as well as Butterscotch
---------------------------------------------------
------------------------------------------
Roll_no |       Name of student
------------------------------------------
3       |       shlok
-------------------------------------------------------------------------
1.   Add Second Year Student
2.   Add Student Who like Vanilla Ice-cream
3.   Add a student who like butterscotch ice-cream
4.   Display students who like both vanilla and butterscotch
5.   Display students who like either vanilla or butterscotch or not both
6.   Display students who like neither vanilla nor butterscotch
7.   Exit
-------------------------------------------------------------------------
Enter Your Choice  5
---------------------------------------------------
Student Who Likes either vanilla or butterscotch but not both
---------------------------------------------------
------------------------------------------
Roll_no |       Name of student
------------------------------------------
1       |       shrikrushna
2       |       suyash
4       |       sahil
5       |       utkarsh
-------------------------------------------------------------------------
1.   Add Second Year Student
2.   Add Student Who like Vanilla Ice-cream
3.   Add a student who like butterscotch ice-cream
4.   Display students who like both vanilla and butterscotch
5.   Display students who like either vanilla or butterscotch or not both
6.   Display students who like neither vanilla nor butterscotch
7.   Exit
-------------------------------------------------------------------------
Enter Your Choice  6
---------------------------------------------------
Student Who Likes neither vanilla nor butterscotch
---------------------------------------------------
------------------------------------------
Roll_no |       Name of student
------------------------------------------
6       |       sid
7       |       mota-bhai
-------------------------------------------------------------------------

*/