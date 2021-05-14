/*
Name            :- Shrikrushna S Zirape
Assignment no   :-7
Problem Statement:-
                Assignment 7: The ticket booking system of Cinemax theater has to be implemented using C++ program. There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand 
                a) The list of available seats is to be displayed 
                b) The seats are to be booked 
                c) The booking can be cancelled. 

*/

#include<iostream>
using namespace std;
class seat
{   public:
        seat* next;
        seat* prev;
        int seat;
        bool available;
    friend class theater;
};

class row{
	public:
    int row_capacity = 7;
    seat* head,* tail ,* temp;
    row(){
      int i=1;
      temp = new seat;
      temp->seat = 1;
      temp->available=true;
      tail=head=temp;
      for(int i=2; i<=row_capacity; i++){
        seat *p;
        p= new seat;
        p->seat=i;
        p->available=true;
        tail->next=p;
        p->prev=tail;
        tail=p;
        tail->next=head;
        head->prev=tail;
      }
    }
    void display_row(){
      seat *col;
      col = head;
      while( col->next != head){
        if(col->available == true){
          cout<<col->seat<<" : UB |";
        }
        else{
          cout<<col->seat<<" : B  |";
        }
        col = col->next;
      }
      if(col->available == true){
        cout<<col->seat<<" : UB |";
      }
      else{
        cout<<col->seat<<" : B  |";
      }
    }
		void book_seat(int cl){
			seat *bk;
			bk=new seat;
			bk = head;
			while( bk->seat != cl){
				bk=bk->next;
			}
			if(bk->available == false){
				cout<<"\n Sorry Seat is not Available \n";
			}
			else{
				temp->available=false;
				cout<<"\n Seat booked \n"<<endl;
			}
		}
		void unbook_seat(int rc){
			seat *ro;
			ro = new seat;
			ro = head;
			while( ro->seat != rc){
				ro=ro->next;
			}
			if(ro->available == true){
				cout<<"\n Seat is not Booked yeat \n";
			}
			else{
				ro->available = true;
				cout<<"\n Booking Cancelled Successfully \n";
			}
		}
	
}theater[10];

void display_all_theater(){
	for(int i=0; i<10; i++){
		cout<<"\n Row No. :- "<<i+1<<"|";
		theater[i].display_row();
	}
}
void seat_book_in_theater(){
	int row_no, col_no;
	cout<<"\nEnter the No of Row :";
	cin>>row_no;
	if(row_no > 10 && row_no <1){
		cout<<"Wrong Row No input ";
	}
	cout<<"\n Enter the No of Seat want to Book :";
	cin>>col_no;
	if(col_no > 7 && col_no <1){
		cout<<"Wrong column No input ";
	}
	
	theater[row_no-1].book_seat(col_no);
}

void seat_unbook_in_theater(){
	int row_no, col_no;
	cout<<"\nEnter the No of Row :";
	cin>>row_no;
	if(row_no > 10 && row_no <1){
		cout<<"Wrong Row No input ";
	}
	cout<<"\n Enter the No of Seat want to Book :";
	cin>>col_no;
	
	if(col_no > 7 && col_no <1){
		cout<<"Wrong column No input ";
	
	}
	theater[row_no-1].unbook_seat(col_no);
}
int main(){
	int option;
do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. The list of all available seats" << endl;
    cout << "2. The available seat in a row" << endl;
    cout << "3. Book a Seat" << endl;
    cout << "4. Cancel Booking" << endl;
 
    cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
        cout<<"Printing all available seat"<<endl;
        display_all_theater();
      break;
 
    case 2:
    	int row_search_no;
        cout<<"Enter the no of row you want to search :"<<endl;
        cin>>row_search_no;
        cout<<"\n---------------------------------------\n";
        cout<<"Available seat in row no "<<endl;
        theater[row_search_no-1].display_row();
        cout<<"\n---------------------------------------\n";
      break;
 
    case 3:
		seat_book_in_theater();
      break;
 
    case 4:
        seat_unbook_in_theater();
    break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
    return 0;
}




/* output:- 

What operation do you want to perform? Select Option number. Enter 0 to exit.
1. The list of all available seats
2. The available seat in a row
3. Book a Seat
4. Cancel Booking
1
Printing all available seat

 Row No. :- 1|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 2|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 3|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 4|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 5|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 6|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 7|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 8|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 9|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
 Row No. :- 10|1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
What operation do you want to perform? Select Option number. Enter 0 to exit.
1. The list of all available seats
2. The available seat in a row
3. Book a Seat
4. Cancel Booking
3

Enter the No of Row :1

 Enter the No of Seat want to Book :1

 Seat booked


What operation do you want to perform? Select Option number. Enter 0 to exit.
1. The list of all available seats
2. The available seat in a row
3. Book a Seat
4. Cancel Booking
3

Enter the No of Row :1

 Enter the No of Seat want to Book :1

 Sorry Seat is not Available

What operation do you want to perform? Select Option number. Enter 0 to exit.
1. The list of all available seats
2. The available seat in a row
3. Book a Seat
4. Cancel Booking
4

Enter the No of Row :1

 Enter the No of Seat want to Book :1

 Booking Cancelled Successfully

What operation do you want to perform? Select Option number. Enter 0 to exit.
1. The list of all available seats
2. The available seat in a row
3. Book a Seat
4. Cancel Booking
2
Enter the no of row you want to search :
1

---------------------------------------
Available seat in row no
1 : UB |2 : UB |3 : UB |4 : UB |5 : UB |6 : UB |7 : UB |
---------------------------------------

What operation do you want to perform? Select Option number. Enter 0 to exit.
1. The list of all available seats
2. The available seat in a row
3. Book a Seat
4. Cancel Booking

*/
