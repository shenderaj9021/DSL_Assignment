#include<iostream>
using namespace std;
const int size=100;
class stack{
    int top;
    public:
    char arr[size];
    stack(){
        top =-1;
    }
    void push(char data){
        if(top>size){
            cout <<" stack is overflow"<<endl;
            return ;
        }
        top++;
        arr[top]=data;
    }
    void pop(){ 
        if(top<0){
            cout <<"stack is already empty"<<endl;
        }else{
            top--;
        }
        
    }
    char peek(){
        if(top<0){
            cout <<"stack is empty"<<endl;
        }else{
            return arr[top];
        }
    }
    bool empty(){
        if(top<0){
            return true;
        }else{
            return false;
        }
    }
};
class expression{
    string exp;
    public:
    expression(string s){
        exp = s;
    }
    expression(){
        cout <<"Enter your Expression "<<endl;
        cin >> exp;
    }
    void show(){
        cout <<exp <<endl;
    }
    bool checkp(){
        stack s;
        bool ans = true;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='[' || exp[i]=='(' ||exp[i]=='{'){
                s.push(exp[i]);
            }else if(!s.empty() && exp[i]==']'){
                if(s.peek()=='['){
                    s.pop();
                }else{
                    ans = false;
                    break;
                }
            }else if(!s.empty() && exp[i]==')'){
                if(s.peek()=='('){
                    s.pop();
                }else{
                    ans = false;
                    break;
                }
            }else if(!s.empty() && exp[i]=='}'){
                if(s.peek()=='{'){
                    s.pop();
                }else{
                    ans = false;
                    break;
                }
            }else{
                    ans = false;
                    break;
            }
        }
        return ans;
        
    }
};
int main(){
    int count =0;
    while(count==0){
        cout <<"*********welcome**********" <<endl;
        cout <<"1] Enter a new string "<<endl;
        cout <<"2] Exit"<<endl;
        int choice;
        cin >> choice;
        try{
            if(choice>2 || choice<1){
                throw choice;
            }
        if(choice=1){
            expression str;
            bool t = str.checkp();
            if(t==true){
                cout <<"Expression is well paranthesize"<<endl;
            }else{
                cout <<"Expression is not well paranthesize"<<endl;
            }

        }else if(choice==2){
            count=1;
        }
        }catch(int){
            cout <<"Please Choose correct opetion"<<endl;
        }
    }  
            

}