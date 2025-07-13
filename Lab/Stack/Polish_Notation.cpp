//Module 5 Topic 3
//Infix to postfix
#include<iostream>
#include<stack>
using namespace std;
void DispStack(stack <char> s){
    cout<<"Stack:"<<endl;
    while(!s.empty()) {
        cout<<s.top()<<endl;
        s.pop();
    }
}
void DispArray(char *arr){
    int i = 0;
    while(arr[i]) cout<<arr[i++];
    cout<<endl;
}
int Precedency(char op){
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0; // for ')' and '(' 
    }
}

void InfToPost(char *infix, char *postfix){
    stack <char> s;
    int j = 0;
    for(int i = 0; infix[i]; i++){
        char symbol;
        symbol = infix[i];
        if(symbol == ' ' || symbol == '\t') 
            continue;
        switch (symbol)
        {
        case '(':
            s.push(symbol);
            break;
        case ')':
            while(s.top() != '(') {
                postfix[j++] = s.top();
                s.pop();
            }
            s.pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(!s.empty() && Precedency(s.top()) >= Precedency(symbol)){
                postfix[j++] = s.top();
                s.pop();
            }
            s.push(symbol);
            break;
        default:
            postfix[j++] = symbol; // if symbol is an operand

        }
    }
    while(!s.empty()){
        postfix[j++] = s.top();
        s.pop();
    }
    postfix[j] = '\0';

}

int main(){
    char infix[100];
    char postfix[100];
    cout<<"Enter infix expression: ";
    gets(infix);
    InfToPost(infix,postfix);
    cout<<"Equivalent postfix expression: ";
    DispArray(postfix);   
}
