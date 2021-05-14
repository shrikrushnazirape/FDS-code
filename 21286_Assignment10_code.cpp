/*
Name                :- Shrikrushna S Zirape
Assigment No        :- 10
Roll no             :- 21286
Batch               :- H2
problem statement   :- 
                    Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given          
                    conditions:  
                        1. Operands and operator, both must be single character. 
                        2. Input Postfix expression must be in a desired format. 
                        3. Only '+', '-', '*' and '/ ' operators are expected. 
​
*/

#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class stack{
    T stack_array[30];
    int top=-1;
    int n=30;
    public:
        T top_element(){
            return stack_array[top];
        }
        bool isempty(){
            if(top == -1){
                return true;
            }
            else return false;
        }

        void pop(){
            if(top == -1){
                cout<<"Stack Underflow \n";
            }
            else{
                top --;
            }
        }
        void push(char c){
            if(top >= n-1){
                cout<<"Stack Overflow \n";
            }
            else{
                top ++;
                stack_array[top] = c;
            }
        }
    friend class Operations;
};

class Operations{
        int Precedence(char c);
        bool isOperator(char c);
        bool isNumber(char c);
        int binaryOperations(int a, int b, char sign);
    public:

        string InfixToPostfix(string infix);
        int PostfixEvaluation(string s);

};

int Operations::Precedence(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '^'){
        return 3;
    }
    else{
        return -1;
    }
}


bool Operations::isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
        return true;
    }
    else{
        return false;
    }
}

bool Operations::isNumber(char c){
    if(c >= '0' && c<='9') return true;
    return false;
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

string Operations::InfixToPostfix(string infix){
    stack<char> s;
    string postfix;
    for (int i=0; i<infix.length(); i++){
        //condition if the char is operend

        if(infix[i] == '('){
            s.push(infix[i]);
        }

        else if(infix[i] == ')'){
            while((s.top_element() != '(') && (!s.isempty())){
                char temp = s.top_element();
                postfix += temp;
                s.pop();
            }
            if(s.top_element() == '('){
                s.pop();
            }
        }
        else if(isOperator(infix[i])){
            if(s.isempty()){
                s.push(infix[i]);
            }
            else{
                if(Precedence(infix[i])> Precedence(s.top_element())){
                    s.push(infix[i]);
                }
                else{
                    while((!s.isempty()) && (Precedence(infix[i])<= Precedence(s.top_element()))){
                        postfix+=s.top_element();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
        else{
            postfix+=infix[i];
        }
    }
    while ( !s.isempty()){
        postfix+=s.top_element();
        s.pop();
    }
    return postfix;
}

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


int main(){
    string s1;
    Operations o;
    while (true){

    cout<<"Enter the string :";
    cin>>s1;
    cout<<"\n *******************************************\n";
    cout<<"Infix Exp:-        "<<s1<<endl;  
    string test = o.InfixToPostfix(s1);
    cout<<"Postfix Exp :-     "<<test<<endl;
    o.PostfixEvaluation(test);
    cout<<"\n *******************************************\n";
    }
    return 0;
}
/*
OUTPUT:-

Enter the string :a+b*(c^d-e)^(f+g*h)-i

 *******************************************
Infix Exp:-        a+b*(c^d-e)^(f+g*h)-i    
Postfix Exp :-     abcd^e-fgh*+^*+i-        

 *******************************************
Enter the string :X*Y/Z+P*Q-R           

 *******************************************
Infix Exp:-        X*Y/Z+P*Q-R
Postfix Exp :-     XY*Z/PQ*+R-

 *******************************************
*/