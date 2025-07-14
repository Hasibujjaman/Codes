//Module 5 Topic 4
//Postfix evaluation
#include<iostream>
#include<stack>
using namespace std;
int Result(char *post){
    stack <int> s;
    for(int i = 0; post[i]; i++){
        char symbol = post[i];
        if(symbol == ' ' || symbol == '\t') continue;
        if(symbol > '0' && symbol < '9'){
            s.push(symbol - '0');
        }
        else{
            int x,y;
            x = s.top();
                s.pop();
            y = s.top();
                s.pop();
            switch (symbol)
            {
            case '+':
                s.push(y + x);
                break;
            case '-':
                s.push(y - x);
                break;
            case '*':
                s.push(y * x);
                break;
            case '/':
                s.push(y / x);
                break;
            default:
                break;
            }
        }
        
    }
    return s.top();
}
int main(){
    char postfix[100];
    cout<<"Enter postfix expression: ";
    gets(postfix);
    cout<<"The value of the postfix expression is : "<<Result(postfix)<<endl;
}