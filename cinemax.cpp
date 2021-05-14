#include<iostream>
using namespace std;

class Node{
    int data;
    int available;
    Node* prev;
    Node* next;
public:
    Node(){
        data=0;
        available=0;
        prev=NULL;
        next=NULL;
    }
    Node(int val){
        data=val;
        available=0;
        prev=NULL;
        next=NULL;
    }
    friend class Cinemax;
};

class Cinemax{
    Node* heads[10];
public:
    Cinemax(){
        for(int i=0;i<10;i++){
            heads[i]=NULL;
        }
    }
    void initialize(){
        Node* temp=NULL;
        for(int i=0;i<10;i++){
            for(int j=0;j<7;j++){
                Node* newNode= new Node(j+1);
                if(heads[i]==NULL){
                    heads[i]=newNode;
                    temp=newNode;
                }
                else{
                newNode->prev=temp;
                temp->next=newNode;
                temp=newNode;
                }
            }
        }
    }
    void display(){
        cout<<endl;
        for(int i=0;i<10;i++){
            Node* temp=heads[i];
            cout<<i<<" | ";
            for(int j=0;j<7;j++){
                cout<<temp->data<<"-"<<temp->available<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    void book(int row,int seat){

        if(row>=10 || seat>7){
            cout<<"\nInvalid seat Number\n";
            return;
        }
        Node* temp=heads[row];
        for(int i=0;i<seat-1;i++){
            temp=temp->next;
        }
        cout<<temp->data<<endl;
        if(temp->available==1){
            cout<<"Seat is Already Booked"<<endl;
            return;
        }
        temp->available=1;
        cout<<"Ticket has been Booked Successfully"<<endl;
    }
    void cancelTicket(int row, int seat){
        if(row>=10 || seat>7){
            cout<<"\nInvalid seat Number\n";
            return;
        }
        Node* temp=heads[row];
        for(int i=0;i<seat-1;i++){
            temp=temp->next;
        }
        if(temp->available==0){
            cout<<"This Ticked is not yet booked"<<endl;
            return;
        }
        temp->available=0;
        cout<<"Ticket has been Cancelled"<<endl;
    }
    void available(){
        cout<<endl;
        for(int i=0;i<10;i++){
            Node* temp=heads[i];
            cout<<i<<" | ";
            for(int j=0;j<7;j++){
                if(temp->available==0){
                    cout<<temp->data<<"-"<<temp->available<<" ";
                }
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    void ShowBookedTickets(){
        cout<<endl;
        for(int i=0;i<10;i++){
            Node* temp=heads[i];
            cout<<i<<" | ";
            for(int j=0;j<7;j++){
                if(temp->available==1){
                    cout<<temp->data<<"-"<<temp->available<<" ";
                }
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main(){
    Cinemax Cinema;
    Cinema.initialize();
    cout<<"Program Started"<<endl;
    while(true){
        int option;
        cout<<"Enter the option:\n1.Show Cinemax \n2.Book Tickets\n3.Cancel Tickets\n4.Show Available Seats\n5.Show Book Tickets\n6.Exit\n>>>";
        cin>>option;
        if(option==1){
            Cinema.display();
        }
        else if(option==2){
            cout<<"\nTicket Booking\n";
            int row;
            cout<<"Enter the Row Number:\n>>>";
            cin>>row;
            int seat;
            cout<<"Enter the Seat Number:\n>>>";
            cin>>seat;
            Cinema.book(row, seat);
        }
        else if(option==3){
            cout<<"\nTicket Cancellation\n";
            int row;
            cout<<"Enter the Row Number:\n>>>";
            cin>>row;
            int seat;
            cout<<"Enter the Seat Number:\n>>>";
            cin>>seat;
            Cinema.cancelTicket(row, seat);
        }
        else if(option==4){
            cout<<"Available Seats"<<endl;
            Cinema.available();
        }
        else if(option==5){
            cout<<"Booked Tickets :-"<<endl;
            Cinema.ShowBookedTickets();
        }
        else{
            cout<<"Thank You !!!"<<endl;
            break;
        }
    }
    return 0;
}
/*OUTPUT :-
Enter the option:
1.Show Cinemax
2.Book Tickets
3.Cancel Tickets
4.Show Available Seats
5.Show Book Tickets
6.Exit
>>>1

0 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
1 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
2 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
3 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
4 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
5 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
6 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
7 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
8 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
9 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
Enter the option:
1.Show Cinemax
2.Book Tickets
3.Cancel Tickets
4.Show Available Seats
5.Show Book Tickets
6.Exit
>>>2

Ticket Booking
Enter the Row Number:
>>>3
Enter the Seat Number:
>>>4
4
Ticket has been Booked Successfully
Enter the option:
1.Show Cinemax
2.Book Tickets
3.Cancel Tickets
4.Show Available Seats
5.Show Book Tickets
6.Exit
>>>2

Ticket Booking
Enter the Row Number:
>>>5
Enter the Seat Number:
>>>8

Invalid seat Number
Enter the option:
1.Show Cinemax
2.Book Tickets
3.Cancel Tickets
4.Show Available Seats
5.Show Book Tickets
6.Exit
>>>4
Available Seats

0 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
1 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
2 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
3 | 1-0 2-0 3-0 5-0 6-0 7-0
4 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
5 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
6 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
7 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
8 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
9 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
Enter the option:
1.Show Cinemax
2.Book Tickets
3.Cancel Tickets
4.Show Available Seats
5.Show Book Tickets
6.Exit
>>>5
Booked Tickets :-

0 |
1 |
2 |
3 | 4-1
4 |
5 |
6 |
7 |
8 |
9 |
Enter the option:
1.Show Cinemax
2.Book Tickets
3.Cancel Tickets
4.Show Available Seats
5.Show Book Tickets
6.Exit
>>>3

Ticket Cancellation
Enter the Row Number:
>>>3
Enter the Seat Number:
>>>4
Ticket has been Cancelled
Enter the option:
1.Show Cinemax
2.Book Tickets
3.Cancel Tickets
4.Show Available Seats
5.Show Book Tickets
6.Exit
>>>4
Available Seats

0 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
1 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
2 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
3 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
4 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
5 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
6 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
7 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
8 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
9 | 1-0 2-0 3-0 4-0 5-0 6-0 7-0
Enter the option:
1.Show Cinemax
2.Book Tickets
3.Cancel Tickets
4.Show Available Seats
5.Show Book Tickets
6.Exit
>>>6
Thank You !!!


int Operations::PostfixEvaluation(string s){
    
    stack<int> k;
    
    for (int i=0; i<s.length(); i++){
        if(isNumber(s[i])){
            k.push(s[i] - '0');
            // cout<<"\npushed"<<s[i];
            
        }
        else{
        int b = k.top_element();
        k.pop();
        int a = k.top_element();
        k.pop();
        int ans = binaryOperations(a, b, s[i]);
        k.push(ans) ;
        }
    }
    cout<<"\nResult is :- "<<k.top_element();

}



int Operations::binaryOperations(int a, int b, char sign){
    switch (sign)
    {
    case '+':
        return a+b;
        break;
    
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    default:
        break;
    }
}
*/