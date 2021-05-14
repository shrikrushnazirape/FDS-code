/*
Name                :- Shrikrushna S Zirape
Assignment no       :-13
Problem Statement   :-
                        A double-ended queue(deque) is a linear list in which additions and deletions may be made at
                        either end. Obtain a data representation mapping a deque into a one-dimensional array. Write C++
                        program to simulate deque with functions to add and delete elements from either end of the deque.

*/



#include <bits/stdc++.h>
#define max 10
using namespace std;

class Dequeue{
    int arr[max];
    int front, rear;
public:
    Dequeue(){
        front = 0;
        rear = 0;
    }

    void insertAtBegin(int k);
    void insertAtEnd(int k);
    int removeAtBegin();
    int removeAtEnd();
    void printQueue();
};
void Dequeue::insertAtBegin(int k){
    if (front <=1){
        cout<<"\nOverflow condition\n";
        return;
    }
    else{
        front --;
        arr[front] = k;
        cout<<"\ninserted successfully\n";
    }
}

void Dequeue::insertAtEnd(int k){
    if(rear == max -1){
        cout<<"\nOverflow!!!\n";
        return;
    }
    rear ++;
    arr[rear]=k;
    cout<<"\nInserted successfully\n";
    if(rear ==0) rear =1;
    if(front ==0) front =1;
}

int Dequeue::removeAtBegin(){
    int ans;
    if(front == 0){
        cout<<"nothing to return";
        return -1;
    }
    ans = arr[front];
    if(front == rear) front = rear = 0;
    else front ++;
    return ans;
}

int Dequeue::removeAtEnd(){
    int ans;
    if(rear == 0){
        cout<<"\nNothing to return\n";
        return -1;
    }
    else ans = arr[rear];
    if(front == rear){
        front = 0;
        rear = 0;
    }
    else rear --;
    return ans;
}

void Dequeue::printQueue(){
    if(front == 0){
        cout<<"\nNothing to show\n";
        return;
    }
    cout<<"\nPrinting The Queue \n";
    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    Dequeue d;
    int ch,k;
    do{
        cout<<"\n 0: Exit the program";
        cout<<"\n 1: Insert at end";
        cout<<"\n 2. Insert at front";
        cout<<"\n 3. Delete from front";
        cout<<"\n 4. Delete from end";
        cout<<"\n 5. Print the queue";
        cout<<"\nEnter the choice :- ";
        cin>>ch;
        switch (ch)
        {
        case 0:
            cout<<"\nEnding the program";
            break;
        
        case 1:
            cout<<"\nEnter the element you want to insert";

            cin>>k;
            d.insertAtEnd(k);
            break;

        case 2:
            cout<<"\nEnter the element you want to insert";
      
            cin>>k;
            d.insertAtBegin(k);
            break;

        case 3:
            d.removeAtBegin();
            break;

        case 4:
            d.removeAtBegin();
            break;

        case 5:
            d.printQueue();

        default:
            cout<<"\nEnter the correct choice ";
            break;
        }
    }while (ch != 0);
    return 0;
}



