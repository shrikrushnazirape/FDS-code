/*

Name                :- Shrikrushna S Zirape
Assigment No        :- 9
Problem Statement   :-
                        In any language program mostly syntax error occurs due to unbalancing delimiter such as { }, [ ] and ( ). Write C++ program using stack to check whether given expression is well parenthesized or not. ​

*/

#include<iostream>
#include <string.h>

using namespace std;
const int size=15;
class stack_exp{
        int top;
        char stack_array[size];
    public:
        stack_exp(){
            top = -1;
        }
        void push(char chr){
            if(!is_full()){
            top +=1;
            stack_array[top]= chr;
            }
        }

        char pop(){
            if(!is_empty()){
                char ch = stack_array[top];
                top -=1;
                return ch;
            }
            else return '\0';
        }

        bool is_empty(){
            if(top == -1){
                return true;
            }
            else{
                return false;
            }
        }

        bool is_full(){
            if(top == 15){
                return true;
            }
            else{
                return false;
            }
        }

        void check(){
            cout<<"Enter the String you want to check :"<<endl;
            string str;
            char ch;
            bool result=true;
            cin>>str;
            int i=0;
            while(str[i] != '\0'){
                if(str[i]=='(' || str[i]=='['|| str[i]=='{'){
                push(str[i]);
                }

                if(str[i]==')' || str[i]==']'|| str[i]=='}'){
                    if(is_empty()){
                        result=false;
                        break;
                    }
                    ch=pop();
                    if((str[i]==')'&& ch!='(')||(str[i]==']'&& ch!='[')||
                    (str[i]=='}' && ch!='{')
                    ){
                        result=false;
                        break;
                    }
                }
                i++;
            }
            if(is_empty()==true && result == true){
                cout<<"_________________________"<<endl;
                cout<<"Well parenthesized"<<endl;
                cout<<"_________________________"<<endl;
            }
            else{
                cout<<"_________________________"<<endl;
                cout<<"Not Parenthesized"<<endl;
                cout<<"_________________________"<<endl;

            }
        }
    
}s1;
int main(){
    int choice;
    do{
        cout<<"enter 0 to break  "<<endl;
        cout<<"Enter 1 to Test String "<<endl;
        cin>>choice;
        if(choice ==1){
           s1.check(); 
        }
    }while(choice !=0);
    return 0;
}

/*

OUTPUT:- 
enter 0 to break
Enter 1 to Test String   
1
Enter the String you want to check :
{ab}(c+d)(a(bc))
_________________________
Well parenthesized       
_________________________
enter 0 to break
Enter 1 to Test String   
1
Enter the String you want to check :
(())))
_________________________
Not Parenthesized
_________________________


*/