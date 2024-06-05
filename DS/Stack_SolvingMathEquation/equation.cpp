#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char a){
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return false;
    else 
        return true;
}

int getPrecedence(char a){
    switch(a){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
        /* other precedences to be added later */
    }
}

string infixToPrefix(string eq){
    stack<char> st;
    string result;

    int i = 0;
    while(eq[i] != '\0'){
        if(isOperand(eq[i]) ){
            result += eq[i++];
        }
        else{
            if(st.empty() || getPrecedence(st.top()) < getPrecedence(eq[i]) ){
                st.push( eq[i++] );
            }
            else{
                result += st.top();
                st.pop();
            }
        }

    }
    while(!(st.empty())){
        result += st.top();
        st.pop();
    }
    return result;
}

int main(){
    stack<char> st;
    string eq {"5+8/2*3-5"};

    cout << infixToPrefix(eq);
    return 0;
}