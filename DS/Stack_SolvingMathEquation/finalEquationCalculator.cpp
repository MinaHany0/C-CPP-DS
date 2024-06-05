#include <iostream>
#include <stack>
#include <cmath>

#define INSTACK     0
#define OUTSTACK    1


using namespace std;

bool isOperand(char a){
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^' ||a == '(' ||a == ')')
        return false;
    else 
        return true;
}

int getPrecedence(char a , char stackStatus){
    if(stackStatus == OUTSTACK){
        switch(a){
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 3;
            case '^':
                return 6;
            case '(':
                return 7;
            case ')':
                return 0;
            default:
                return -1;
            /* other precedences to be added later */
        }
    }
    else{
       switch(a){
            case '+':
            case '-':
                return 2;
            case '*':
            case '/':
                return 4;
            case '^':
                return 5;
            case '(':
                return 0;
            case ')':
                return -1;
            default:
                return -1;
            /* other precedences to be added later */
        } 
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
            if(st.empty() || getPrecedence(st.top() , INSTACK) < getPrecedence(eq[i] , OUTSTACK) ){
                st.push( eq[i++] );
            }
            else if(getPrecedence(eq[i] , OUTSTACK) == 0){
                while(getPrecedence(st.top() , INSTACK) != 0){
                    result += st.top();
                    st.pop();
                }
                st.pop();
                i++;
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

int calculate(string postfix){
    stack<int> st;
    int i = 0;
    while(postfix[i] != '\0'){
        if(isOperand(postfix[i])){
            st.push(postfix[i++]-'0');
        }
        else{
            int operandTwo = st.top();
            st.pop();
            int operandOne = st.top();
            st.pop();
            int result = 0;
            switch(postfix[i++]){
                case '+': result = operandOne + operandTwo; break;
                case '-': result = operandOne - operandTwo; break;
                case '*': result = operandOne * operandTwo; break;
                case '/': result = operandOne / operandTwo; break;
                case '^': result = (int)pow(operandOne , operandTwo); break;
                default : break;
            }
            st.push(result);
        }
    }
    int result  = st.top();
    st.pop();
    return result;
}

int main(){
    stack<char> st;
    string eq {"(1+2)*3^2"};

    cout << infixToPrefix(eq) << endl;
    string infix = infixToPrefix(eq);
    cout << calculate(infix) << endl;
    return 0;
}