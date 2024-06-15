#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#ifndef STACH_H__
#define STACK_H__

typedef struct NodeStack{
    Node* data;
    struct NodeStack *next;
}NodeStack;

typedef struct Stack{
    NodeStack *top;
}Stack;

Stack* createStack(void){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    assert(st);
    st->top = NULL;
    return st;
}
bool isStackEmpty(Stack *pStack){
    return (pStack->top == NULL);
}
void pushStack(Stack *pStack , Node* data){
        NodeStack *pNode = (NodeStack*)malloc(sizeof(NodeStack));
        assert(pNode);
        pNode->data = data;
        pNode->next = NULL;
    if(isStackEmpty(pStack)){
        pStack->top = pNode;
    }
    else{
        pNode->next = pStack->top;
        pStack->top = pNode;
    }
    return;
}
Node* popStack(Stack *pStack){
    NodeStack *pNode = NULL;
    Node* ret;
    if(isStackEmpty(pStack)){
        puts("STACK UNDERFLOW !!");
        return 0;
    }
    else{
        pNode = pStack->top;
        pStack->top = pStack->top->next;
        ret = pNode->data;
        free(pNode);
        return ret;
    }

}
Node* topStack(Stack *pStack){
    Node* ret;
    if(isStackEmpty(pStack)){
        puts("STACK UNDERFLOW !!");
        return 0;
    }
    else{
        ret = pStack->top->data;
        return ret;
    }

}
int countStack(Stack *pStack){
    int ret = 0;
    NodeStack *pNode = pStack->top;
    if(isStackEmpty(pStack)){
        return ret;
    }
    else{
        while(pNode!= NULL){
            ret++;
            pNode = pNode->next;
        }
        return ret;
    }
}

#endif