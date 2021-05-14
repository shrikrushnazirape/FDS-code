/*

Name                :-  Shrikrushna S Zirape
Assignment          :-  12
Roll No             :-  21286
Batch               :-  H2
Prb Sta             :-  

                        Write program to implement a priority queue in c++ using an inorder list to store the items in queue. Create a class that includes data items which should be template and priority (which should be int ) the inorder list should contain these objects, with operator <= overloaded so that the items with highest priority appears at the beginning of the list (which will make it relativly easy to retive the highest item)

*/

/*
#include <iostream>
using namespace std;


template <class T>
class Node
{
    public:
    T data;
	int priority;
    Node *next;
    Node *prev;

    Node()
    {
        priority = 0;
		next = NULL;
        prev = NULL;
    }

    bool operator <= (Node &obj)
	{
		return (this->priority <= obj.priority);
	}

};

template <class T>
class Queue
{
    Node<T> *front;
    Node<T> *rear;

    public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(T d, int prior)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = d;
		newNode->priority = prior;

        if (rear==NULL){
            rear = newNode;
            front = newNode;
        }
        else{
            if ((*newNode) <= (*rear)){
                newNode->prev = rear;
                newNode->next = NULL;
                rear->next = newNode;
                rear = newNode;
            }
            else{
                Node<T> *p = rear;
                Node<T> *q = NULL;
                while ((p!=NULL) && ((*p)<=(*newNode))){
                    q = p;
                    p = p->prev;
                }
                newNode->prev = p;
                newNode->next = q;
                if (p!=NULL) p->next = newNode;
                q->prev = newNode;
            }

            Node<T> *temp = rear;
            while (temp->prev!=NULL){
                temp = temp->prev;
            }
            front = temp;
        }
        display();
    }

    void dequeue()
    {
        if (front==rear){

            front = NULL;
            rear = NULL;
        }
        else{
            Node<T> *p = front;
            front = front->next;
            front->prev = NULL;
            p->next = NULL;
            delete p;
        }
   
    }

    void display()
    {
        Node<T> *temp = front;

        if (temp==NULL){
            cout<<"\nQUEUE EMPTY"<<endl;
        }
        else{
            cout<<"\nQUEUE :-"<<endl;
            cout<<"\nFront"<<endl;
            while (temp!=NULL){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            cout<<"Rear"<<endl;
        }
    }
};



int Selectchoice(){
                cout<<"\n***OPERATIONS*"<<endl;
                cout<<"1. Enqueue"<<endl;
                cout<<"2. Dequeue"<<endl;
                cout<<"3. Display"<<endl;
                cout<<"0. Back"<<endl;

                int choice;
                cout<<"\nSelect operation: ";
                cin>>choice;   
                return choice;
}




int main()
{
    int ch;
    do{
        cout<<"\n-------------------Menu---------------\n";
        cout<<"1. Int queue\n";
        cout<<"2. char Queue\n";
        cout<<"3. Float Queue\n";
        cout<<"0. Exit\n";
        cout<<"Enter the correct choice : -";
        cin>>ch;
        switch (ch)
        {
        case 0:
            cout<<"\nEnding the program";
            break;
        
        case 1:
            Queue<int> q1;
            int k1;
            do{
                k1 = Selectchoice();
                switch (k1)
                {
                case 0:
                    cout<<"\nEnding the program";
                    break;
                
                case 1:
                    int d1;
                    cout<<"\nEnter data: ";
                    cin>>d1;
					int p1;
                    cout<<"\nEnter priority: ";
                    cin>>p1;
                    q1.enqueue(d1, p1);  
                    break;

                case 2:
                    q1.dequeue();

                case 3:
                    q1.display();


                default:
                    cout<<"\nincorrect option";
                    break;
                }
            }while(k1!=0);

            break;

        case 2:
            Queue<int> q2;
            int k2;
            do{
                k2 = Selectchoice();
                switch (k2)
                {
                case 0:
                    cout<<"\nEnding the program";
                    break;
                
                case 1:
                    int d2;
                    cout<<"\nEnter data: ";
                    cin>>d2;
					int p2;
                    cout<<"\nEnter priority: ";
                    cin>>p2;
                    q2.enqueue(d2, p2);  
                    break;

                case 2:
                    q2.dequeue();

                case 3:
                    q2.display();


                default:
                    cout<<"\nincorrect option";
                    break;
                }
            }while(k2!=0);
            break;


        case 3:
            Queue<float> q3;
            int k3;
            do{
                k3 = Selectchoice();
                switch (k3)
                {
                case 0:
                    cout<<"\nEnding the program";
                    break;
                
                case 1:
                    int d3;
                    cout<<"\nEnter data: ";
                    cin>>d3;
					int p3;
                    cout<<"\nEnter priority: ";
                    cin>>p3;
                    q3.enqueue(d3, p3);  
                    break;

                case 2:
                    q3.dequeue();

                case 3:
                    q3.display();


                default:
                    cout<<"\nincorrect option";
                    break;
                }
            }while(k3!=0);
            break;


        default:
            cout<<"\nIncorrect Option";
            break;
        }


    }while(ch!=0);


    return 0;
}

*/

#include <iostream>
using namespace std;
template <class T>
class Node
{
    public:
    T data;
	int priority;
    Node *next;
    Node *prev;

    Node()
    {
        priority = 0;
		next = NULL;
        prev = NULL;
    }

    bool operator <= (Node &obj)
	{
		return (this->priority <= obj.priority);
	}
};

template <class T>
class Queue
{
    Node<T> *front;
    Node<T> *rear;

    public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(T d, int prior)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = d;
		newNode->priority = prior;

        if (rear==NULL){
            rear = newNode;
            front = newNode;
        }
        else{
            if ((*newNode) <= (*rear)){
                newNode->prev = rear;
                newNode->next = NULL;
                rear->next = newNode;
                rear = newNode;
            }
            else{
                Node<T> *p = rear;
                Node<T> *q = NULL;
                while ((p!=NULL) && ((*p)<=(*newNode))){
                    q = p;
                    p = p->prev;
                }
                newNode->prev = p;
                newNode->next = q;
                if (p!=NULL) p->next = newNode;
                q->prev = newNode;
            }

            Node<T> *temp = rear;
            while (temp->prev!=NULL){
                temp = temp->prev;
            }
            front = temp;
        }
        display();
    }

    void dequeue()
    {
        if (front==rear){
            front = NULL;
            rear = NULL;
        }
        else{
            Node<T> *p = front;
            front = front->next;
            front->prev = NULL;
            p->next = NULL;
            delete p;
        }
        display();
    }

    void display()
    {
        Node<T> *temp = front;

        if (temp==NULL){
            cout<<"\nQUEUE EMPTY"<<endl;
        }
        else{
            cout<<"\nQUEUE :-"<<endl;
            cout<<"\nFront"<<endl;
            while (temp!=NULL){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
            cout<<"Rear"<<endl;
        }
    }
};

int main()
{
    while (true){
        cout<<"\n***MENU*"<<endl;
        cout<<"1. int queue"<<endl;
        cout<<"2. char queue"<<endl;
        cout<<"3. float queue"<<endl;
        cout<<"0. Exit"<<endl;

        int c;
        cout<<"\nSelect datatype: ";
        cin>>c;


        if (c==1){
            Queue<int> q;
            while (true){
                cout<<"\n***OPERATIONS*"<<endl;
                cout<<"1. Enqueue"<<endl;
                cout<<"2. Dequeue"<<endl;
                cout<<"3. Display"<<endl;
                cout<<"0. Back"<<endl;

                int choice;
                cout<<"\nSelect operation: ";
                cin>>choice;

                if (choice==1){
                    int d;
                    cout<<"\nEnter data: ";
                    cin>>d;
					int p;
                    cout<<"\nEnter priority: ";
                    cin>>p;
                    q.enqueue(d, p);
                }
                else if (choice==2){
                    q.dequeue();
                }
                else if (choice==3){
                    q.display();
                }
                else if (choice==0){
                    break;
                }
                else{
                    cout<<"\nENTER VALID CHOICE !!!"<<endl;
                }
            }
        }

        else if (c==2){
            Queue<char> q;
            while (true){
                cout<<"\n***OPERATIONS*"<<endl;
                cout<<"1. Enqueue"<<endl;
                cout<<"2. Dequeue"<<endl;
                cout<<"3. Display"<<endl;
                cout<<"0. Back"<<endl;

                int choice;
                cout<<"\nSelect operation: ";
                cin>>choice;

                if (choice==1){
                    char d;
                    cout<<"\nEnter data: ";
                    cin>>d;
					int p;
                    cout<<"\nEnter priority: ";
                    cin>>p;
                    q.enqueue(d, p);
                }
                else if (choice==2){
                    q.dequeue();
                }
                else if (choice==3){
                    q.display();
                }
                else if (choice==0){
                    break;
                }
                else{
                    cout<<"\nENTER VALID CHOICE !!!"<<endl;
                }
            }
        }

        else if (c==3){
            Queue<float> q;
            while (true){
                cout<<"\n***OPERATIONS*"<<endl;
                cout<<"1. Enqueue"<<endl;
                cout<<"2. Dequeue"<<endl;
                cout<<"3. Display"<<endl;
                cout<<"0. Back"<<endl;

                int choice;
                cout<<"\nSelect operation: ";
                cin>>choice;

                if (choice==1){
                    float d;
                    cout<<"\nEnter data: ";
                    cin>>d;
                    int p;
                    cout<<"\nEnter priority: ";
                    cin>>p;
                    q.enqueue(d, p);
                }
                else if (choice==2){
                    q.dequeue();
                }
                else if (choice==3){
                    q.display();
                }
                else if (choice==0){
                    break;
                }
                else{
                    cout<<"\nENTER VALID CHOICE !!!"<<endl;
                }
            }
        }

        else if (c==0){
            cout<<"\nTHANK YOU !!!"<<endl;
            exit(0);
        }

        else{
            cout<<"\nENTER VALID CHOICE !!!"<<endl;
            break;
        }
    }

    return 0;
}