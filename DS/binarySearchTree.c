#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

/*  notice that this function can be used to create a root node   */
Node *insertRecursiveBST(Node* ptr , int key){
    if(ptr == NULL){
        ptr = (Node*)malloc(sizeof(Node));
        ptr->data = key;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
    }
    else if(ptr->data == key){
        return ptr;
    }
    else if(ptr->data > key){
        ptr->left = insertRecursiveBST(ptr->left , key);
    }
    else{
        ptr->right = insertRecursiveBST(ptr->right , key);
    }
    return ptr;
}

/*  notice that this function can't be used to create a root node   */
void insertIterativeBST(Node *ptr , int key){
    Node *tmp= NULL;
    Node *trail = NULL;
    while(ptr != NULL){
        trail = ptr;
        if(ptr->data == key){
            return;
        }
        else if(key < ptr->data){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    tmp = (Node*)malloc(sizeof(Node));
    assert(tmp);
    tmp->data = key;
    tmp->left = NULL;
    tmp->right = NULL;
    if(key < trail->data){
        trail->left = tmp;
    }
    else{
        trail->right = tmp;
    }
}

void inorder(Node* pNode){
    if(pNode){
        inorder(pNode->left);
        printf("%d\t" , pNode->data);
        inorder(pNode->right);
    }
}
int heightTree(Node* pNode){
    int x = 0 , y = 0;
    if(pNode == NULL){
        return -1;
    }
    if(pNode->left == NULL && NULL == pNode->right){
        return 0;
    }
    x = heightTree(pNode->left);
    y = heightTree(pNode->right);
    return (x>y? x+1 : y+1);
}
Node* inorderPredecessor(Node* pNode){
    if(NULL == pNode->left || NULL == pNode)
        return pNode;
    pNode = pNode->left;
    while(pNode->right)
        pNode = pNode->right;
    return pNode;
}
Node* inorderSuccessor(Node* pNode){
    if(NULL == pNode->right|| NULL == pNode)
        return pNode;
    pNode = pNode->right;
    while(pNode->left)
        pNode = pNode->left;
    return pNode;
}

Node* deleteNode(Node* pNode , int key, Node** root){
    Node *tmp = NULL;

    if(pNode == NULL)   
        return NULL;
    if(key == pNode->data && pNode->left == NULL && pNode->right == NULL){
        if(key == (*root)->data){
            *root = NULL;
        }
        free(pNode);
        return NULL;
    }

    if(key < pNode->data){
        pNode->left = deleteNode(pNode->left , key , root);
    }
    else if(key > pNode->data){
        pNode->right = deleteNode(pNode->right , key , root);
    }
    else{
        if(heightTree(pNode->left) > heightTree(pNode->right)){
            tmp = inorderPredecessor(pNode);
            pNode->data = tmp->data;
            pNode->left = deleteNode(pNode->left, tmp->data , root);
        }
        else{
            tmp = inorderSuccessor(pNode);
            pNode->data = tmp->data;
            pNode->right = deleteNode(pNode->right, tmp->data , root);
        }
    }
    return pNode;
}


int main(){
    Node *root = NULL;
    root = insertRecursiveBST(root , 25);
    insertIterativeBST(root , 20);
    insertIterativeBST(root , 30);
    insertIterativeBST(root , 40);
    insertIterativeBST(root , 10);
    puts("First in order display");
    puts("===================================");
    inorder(root);

    root = deleteNode(root , 20 , &root);
    puts("\n\nIn order display");
    puts("===================================");
    inorder(root);
    root = deleteNode(root , 25 , &root);
    puts("\n\nIn order display");
    puts("===================================");
    inorder(root);
    root = deleteNode(root , 10 , &root);
    puts("\n\nIn order display");
    puts("===================================");
    inorder(root);
    root = deleteNode(root , 30 , &root);
    puts("\n\nIn order display");
    puts("===================================");
    inorder(root);
    root = deleteNode(root , 40 , &root);
    puts("\n\nIn order display");
    puts("===================================");
    inorder(root);
    return 0;
}