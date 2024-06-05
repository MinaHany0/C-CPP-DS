#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    char data;
    struct Node *next;
}Node;

typedef struct Stack{
    Node *top;

}Stack;

void pushinStack(Stack *st , char _data){
    Node *ptr = (Node*)malloc(sizeof(Node));
    assert(ptr);
    ptr->data = _data;
    if(st->top == NULL){
        st->top = ptr;
        st->top->next = NULL;
    }
    else{
        ptr->next = st->top;
        st->top = ptr;
    }
    return;
}

char popfromStack(Stack *st){
    char ret = -1;
    if(!(st->top)){
        printf("empty stack\n");
    }
    else{
        Node *ptr = st->top;
        assert(ptr);
        st->top = st->top->next;
        ret = ptr->data;
        free(ptr);
    }
    return ret;
}

char topofStack(Stack *st){
    char ret = -1;
    if(!(st->top)){
        printf("empty stack\n");
    }
    else{
        ret = st->top->data;
    }
    return ret; 
}

void displayStack(Stack *st){
    Node *tmp = st->top;
    while(tmp){
        printf("%c\t",tmp->data);
        tmp = tmp->next;
    }
    return;
}

bool isStackEmpty(Stack *st){
    if(st->top){
        return false;
    }
    return true;
}



bool isOperand(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
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

char* infixToPostfix(char *str){
    int len = strlen(str);
    char *res = (char*)malloc((len+1) * sizeof(char));
    int res_index = 0;
    Stack st;
    st.top = NULL;
    int i = 0;

    memset(res , '\0' ,len+1);

    while(str[i] != '\0'){
        if(isOperand(str[i])){
            res[res_index++] = str[i++];
        }
        else if(isStackEmpty(&st) || getPrecedence(str[i]) > getPrecedence(topofStack(&st))){
            pushinStack(&st , str[i++]);
        }
        else{
            res[res_index++] = popfromStack(&st);
        }
    }
    while(!isStackEmpty(&st)){
        res[res_index++] = popfromStack(&st);
    }
    return res;
}


int main(){
    Stack mystack;
    char * eq = "5+8/2*3-5";
    
    printf("%s" , infixToPostfix(eq));
    return 0;

}