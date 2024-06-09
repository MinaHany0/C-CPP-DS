#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define STACKSIZE 100

typedef struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}Node;

typedef struct queue{
    Node **q; //array of pointers to struct node
    int front;
    int rear;
    int size;
}queue;

void createQ(queue **q, int _size){
    *q = (queue*)malloc(sizeof(queue));
    assert(*q);
    (*q)->front = 0;
    (*q)->rear = 0;
    (*q)->size = _size;
    (*q)->q = (Node**)malloc(_size * sizeof(Node*));
}

bool isFull(queue *q){
    if((q->rear+1)%q->size == q->front%q->size)
        return true;
    return false;
}

bool isEmpty(queue *q){
    if((q->rear)%q->size == q->front%q->size)
        return true;
    return false;
}

void enqueue(queue *q, Node* data){
    if(isFull(q)){
        printf("can not enqueue cause full\n");
    }
    else{
        q->rear = q->rear + 1;
        q->q[(q->rear)] = data;
    }
}

Node *dequeue(queue *q){
    Node *ret = NULL;
    if(isEmpty(q)){
        printf("can not dequeue cause empty\n");
    }
    else{
        ret = q->q[1 + q->front++];
    }
    return ret;
}

void createTree(Node **head){
    
    queue *q;
    createQ(&q , 100);
    Node *ptr , *tmp;
    int tmpData;
    /*get value of node data from user*/
    printf("Please enter value of Node: ");
    scanf("%d" , &tmpData);    while(getchar() != '\n');
    /*create node and assign data to it and assign NULLs to the rchid and lchild*/
    *head = (Node *)malloc(sizeof(Node));
    assert(*head);
    (*head)->data = tmpData;
    (*head)->lchild = (*head)->rchild = NULL;
    /*add to queue and then start while loop of checking for children and making nodes with hep of temporary pointers*/
    enqueue(q , *head);
    while(isEmpty(q) == false)
    {
        ptr = dequeue(q);
        /*test for existance of lchild (!= -1) and if so assign and add to queue*/
        printf("Please enter value of lchild of %d: " , ptr->data);
        scanf("%d" , &tmpData);     while(getchar() != '\n');
        if(tmpData != -1){
            ptr->lchild = (Node*)malloc(sizeof(Node));
            assert(ptr->lchild);
            ptr->lchild->data = tmpData;
            ptr->lchild->lchild = ptr->lchild->rchild = NULL;
            enqueue(q, ptr->lchild);
        }
        printf("Please enter value of rchild of %d: " , ptr->data);
        scanf("%d" , &tmpData);     while(getchar() != '\n');
        if(tmpData != -1){
            ptr->rchild = (Node*)malloc(sizeof(Node));
            assert(ptr->rchild);
            ptr->rchild->data = tmpData;
            ptr->rchild->lchild = ptr->rchild->rchild = NULL;
            enqueue(q, ptr->rchild);
        }
    }
    return;
}

void preOrderTree(Node *pNode){
    if(pNode){
        printf("%d\t" , pNode->data);
        preOrderTree(pNode->lchild);
        preOrderTree(pNode->rchild);
    }
    return;
}

void inOrderTree(Node *pNode){
    if(pNode){
        inOrderTree(pNode->lchild);
        printf("%d\t" , pNode->data);
        inOrderTree(pNode->rchild);
    }
    return;
}

void postOrderTree(Node *pNode){
    if(pNode){
        postOrderTree(pNode->lchild);
        postOrderTree(pNode->rchild);
        printf("%d\t" , pNode->data);
    }
    return;
}


typedef struct Stack{
    int top;
    Node **array;
    int size;
}Stack;
Stack * createStack(int size){
    Stack *pStack = (Stack*)malloc(sizeof(Stack));
    assert(pStack);
    pStack->size = size;
    pStack->top = -1;
    pStack->array = (Node**)malloc(size * sizeof(Node*));
}
bool isStackEmpty(Stack *pStack){
    return (-1 == pStack->top);
}
bool isStackFull(Stack *pStack){
    return (pStack->top == pStack->size -1);
}
void pushStack(Stack *pStack , Node *data){
    if(isStackFull(pStack)){
        puts("OVERFLOW !!");
    }
    else{
        pStack->top++;
        pStack->array[pStack->top] = data;
    }
}
Node *popStack(Stack *pStack){
    if(isStackEmpty(pStack)){
        puts("UNDERFLOW !!");
        return NULL;
    }
    else{
        Node *pNode = pStack->array[pStack->top];
        pStack->top--;
        return pNode;
    }
}

void iterativePreOrder(Node *pNode){
    /*create stack to hold the addresses of nodes to be able to get back to them later*/
    Stack *pStack = createStack(STACKSIZE);
    /*as long as pointer is a valid node or the stack still has valid nodes */
    while(pNode || !isStackEmpty(pStack)){
        /*if pointer to node is not null , print value of node and navigate to left child*/
        if(pNode != NULL){
            printf("%d\t" , pNode->data);
            pushStack(pStack,  pNode); 
            pNode = pNode->lchild;
        }
        /*if pointer to node is null , pop stack into pointer and navigate to right child*/
        else{
            pNode = popStack(pStack);
            pNode = pNode->rchild;
        }
    }
}

void iterativeInOrder(Node *pNode){
    /*create stack to hold the addresses of nodes to be able to get back to them later*/
    Stack *pStack = createStack(STACKSIZE);
    /*as long as pointer is a valid node or the stack still has valid nodes */
    while(pNode || !isStackEmpty(pStack)){
        /*if pointer to node is not null , navigate to left child*/
        if(pNode != NULL){
            pushStack(pStack,  pNode); 
            pNode = pNode->lchild;
        }
        /*if pointer to node is null , pop stack into pointer , print value and navigate to right child*/
        else{
            pNode = popStack(pStack);
            printf("%d\t" , pNode->data);
            pNode = pNode->rchild;
        }
    }
}

/* problem with post order is how to know that the node popped from stack is resulting from push of a 
right child ???*/

/*a quick solution is adding a 1 to the address in case it was being pushed after right child call
like if it was an indication of thumb instruction */

void iterativePostOrder(Node *pNode){
    /*create stack to hold the addresses of nodes to be able to get back to them later*/
    Stack *pStack = createStack(STACKSIZE);
    /*as long as pointer is a valid node or the stack still has valid nodes */
    while(pNode || !isStackEmpty(pStack)){
        /*if pointer to node is not null , navigate to left child*/
        if(pNode != NULL){
            pushStack(pStack,  pNode); 
            pNode = pNode->lchild;
        }
        /*if pointer to node is null , pop stack into pointer , print value and navigate to right child*/
        else{
            pNode = popStack(pStack);
            if((long long int)pNode %2 == 0){
                pushStack(pStack,   (Node*)((long long int)pNode +1)); 
                pNode = pNode->rchild;
            }
            else if ( (long long int)pNode %2 == 1 ){
                pNode = (Node*)((long long int)pNode -1);
                printf("%d\t" , pNode->data);
                pNode = NULL;
            }
        }
    }
}


int main(){
    struct Node *head;
    createTree(&head);
    puts("Recursive preorder traversing:");
    preOrderTree(head);
    puts("");
    puts("Recursive inorder traversing:");
    inOrderTree(head);
    puts("");
    puts("Recursive postorder traversing:");
    postOrderTree(head);
    puts("");

    puts("=====================================");
    puts("iterative preOrder Traversing :");
    iterativePreOrder(head);
    puts("");
    puts("iterative inOrder Traversing :");
    iterativeInOrder(head);
    puts("");
    puts("iterative Order Traversing : ");
    iterativePostOrder(head);
    return 0;
}