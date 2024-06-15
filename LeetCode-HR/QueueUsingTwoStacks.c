

typedef struct Node {
    int data;
    struct Node *next;
}Node;
typedef struct Stack{
    Node *top;
}Stack;
Stack *createStack(void){
    Stack *st =(Stack*)malloc(sizeof(Stack));
    st->top = NULL;
    return st; 
}
bool isStackEmpty(Stack *pStack){
    return (pStack->top == NULL);
}
void pushStack(Stack *pStack , int data){
    if(isStackEmpty(pStack)){
        pStack->top = (Node *)malloc(sizeof(Node));
        pStack->top->data = data;
        pStack->top->next = NULL;
    }
    else{
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->data = data;
        tmp->next = pStack->top;
        pStack->top = tmp;
    }
}
int popStack(Stack *pStack){
    if(isStackEmpty(pStack)){
        return -1;
    }
    else{
        int data = pStack->top->data;
        Node *tmp = pStack->top;
        pStack->top = pStack->top->next;
        free(tmp);
        return data;
    }


}


typedef struct {
    Stack *first;
    Stack *second;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    assert(q);
    q->first = createStack();
    q->second = createStack();
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    pushStack( obj->first , x );
}

int myQueuePop(MyQueue* obj) {
    if(isStackEmpty(obj->second)){
        while(!isStackEmpty(obj->first)){
            pushStack(obj->second , popStack(obj->first));
        }
    }
    if(isStackEmpty(obj->second)){
        return -1;
    }
    return popStack(obj->second);
}

int myQueuePeek(MyQueue* obj) {
    int ret = myQueuePop(obj);
    pushStack(obj->second , ret);
    return ret;
}

bool myQueueEmpty(MyQueue* obj) {
    return (isStackEmpty(obj->first) && isStackEmpty(obj->second) );
}

void myQueueFree(MyQueue* obj) {
    while(!isStackEmpty(obj->first)){
        popStack(obj->first);
    }
    while(!isStackEmpty(obj->second)){
        popStack(obj->second);
    }
    free(obj->first);
    free(obj->second);
    obj->first = NULL;
    obj->second = NULL;
    return;

}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/