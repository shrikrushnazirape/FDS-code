/*
Name            :-  Shrikrushna S Zirape
Assignment      :-  11
Roll No         :-  21286
Batch           :-  H2
Prb Sta         :-   
                    Queues are frequently used in computer programming, and a typical example is the creation of a job queue by an operating system. 
                    If the operating system does not use priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job queue. Write functions to add job and delete job from queue. 

*/

#include<iostream>
#include<string>
#define max 10
using namespace std;
class queue{
    int front;
    int rear;
    string job[max];
    public:
        queue(){
            front = -1;
            rear = -1;
            for (int i=0; i<max; i++){
                job[i]="Null";
            }
        }
        bool is_empty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else return false;
        }
        bool is_full(){
            if(rear == (max -1)){
                return true;
            }
            else return false;
        }
        void enqueue(string str){
            if(is_full()){
                cout<<"Queue is Full\n";
                return ;
            }
            else if(is_empty()){
                front=0;
                rear =0;
                job[rear]=str;
            }
            else{
                rear +=1;
                job[rear] = str;
            }
        }
        string dequeue(){
            string x="Null";
            if (is_empty()){
                cout<<"Queue is Empty\n";
                return x;
            }
            else if(rear == front){
                x= job[front];
                rear = front = -1;
                return x;
            }
            else{
                x= job[front];
                job[front]="Null";
                front  +=1;
                return x;
            }
        }
        void display(){
            if(is_empty()){
                cout<<"No Job Present\n";
                return;
            }
            else {

            cout<<"-------------------\n All Jobs \n";
            int count =1;
            for (int i=front; i<= rear; i++){
                cout<<count<<"  -  "<<job[i]<<"\n";
                count ++;
            }
            cout<<"-------------------\n \n";
            }
        }
};
int main(){
    queue q;
    int ch;
    string str;
    do{
        cout<<"\n---------------------Menu--------------------------\n";
        cout<<"1.   Insert a Job\n";
        cout<<"2.   Delete a Job\n";
        cout<<"3.   Print all Job\n";
        cout<<"0.   End the Program\n";
        cout<<"Enter the Choice\n";
        cout<<"-------------------------------------------------------\n";
        cin>>ch;
        switch(ch){
            case 0:
                break;
            case 1:
                cout<<"Enter the job wanted to add\n";
                cin>>str;
                q.enqueue(str);
                cout<<"Job Added Successfully\n";
                break;

            case 2:
                q.dequeue();
                cout<<"Job Deleted Successfully\n";
                break;

            case 3:
                q.display();
                break;

            default:
                cout<<"Entet the correct Option\n";
                break;
        }

    }while(ch != 0);
    return 0;
}


/*

Output of program 

---------------------Menu--------------------------
1.   Insert a Job
2.   Delete a Job
3.   Print all Job
0.   End the Program
Enter the Choice
-------------------------------------------------------
1
Enter the job wanted to add
first
Job Added Successfully

---------------------Menu--------------------------
1.   Insert a Job
2.   Delete a Job
3.   Print all Job
0.   End the Program
Enter the Choice
-------------------------------------------------------
1
Enter the job wanted to add
second
Job Added Successfully

---------------------Menu--------------------------
1.   Insert a Job
2.   Delete a Job
3.   Print all Job
0.   End the Program
Enter the Choice
-------------------------------------------------------
1
Enter the job wanted to add
third 
Job Added Successfully

---------------------Menu--------------------------
1.   Insert a Job
2.   Delete a Job
3.   Print all Job
0.   End the Program
Enter the Choice
-------------------------------------------------------
3
-------------------
 All Jobs 
1  -  first
2  -  second
3  -  third
-------------------
 

---------------------Menu--------------------------
1.   Insert a Job
2.   Delete a Job
3.   Print all Job
0.   End the Program
Enter the Choice
-------------------------------------------------------
2
Job Deleted Successfully

---------------------Menu--------------------------
1.   Insert a Job
2.   Delete a Job
3.   Print all Job
0.   End the Program
Enter the Choice
-------------------------------------------------------
3
-------------------
 All Jobs 
1  -  second
2  -  third
-------------------


*/