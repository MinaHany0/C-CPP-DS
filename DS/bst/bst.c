#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

#include "stack_int.h"

/**
 * @brief   Insert a node in a subtree with loop recursive fashion
 * @note    This function can be used to create a root node
 */
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
/**
 * @brief   Insert a node in a subtree with loop iterative fashion
 * @note    This function can't be used to create a root node
 */
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
/**
 * @brief   displays tree in in order fashion
 */
void inorder(Node* pNode){
    if(pNode){
        inorder(pNode->left);
        printf("%d\t" , pNode->data);
        inorder(pNode->right);
    }
}
/**
 * @brief   returns height of a tree
 */
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
/**
 * @brief   pinpoints the in order traverser Predecessor.
 */
Node* inorderPredecessor(Node* pNode){
    if(NULL == pNode->left || NULL == pNode)
        return pNode;
    pNode = pNode->left;
    while(pNode->right)
        pNode = pNode->right;
    return pNode;
}
/**
 * @brief   pinpoints the in order traverser successor.
 */
Node* inorderSuccessor(Node* pNode){
    if(NULL == pNode->right|| NULL == pNode)
        return pNode;
    pNode = pNode->right;
    while(pNode->left)
        pNode = pNode->left;
    return pNode;
}
/**
 * @brief   deletes a node from binary search tree and frees its node
 * 
 * @param pNode pointer to root node of certain subtree to search
 * @param key   integer to search up
 * @param root  address of root node in case it's needed to delete
 * @return      Node* pNode pointer to same certain subtree after tree changes
 */
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
/**
 * @brief Create a binary search tree from preorder traversal
 */
Node* createFromPreOrder(int arr[] , int len){
    Stack *st = createStack();
    int i = 0;
    Node *tmp = NULL;
    Node *root = NULL;
    /*  create root node    */
    Node* pNode = (Node*)malloc(sizeof(Node));
    assert(pNode);
    pNode->data = arr[i++];
    pNode->left = NULL;
    pNode->right = NULL;
    root = pNode;
    /*   create rest of binary search tree   */
    while(i < len){
        /* if element is smaller -> make as left child of current node  */
        if(arr[i] < pNode->data){
            tmp = (Node*)malloc(sizeof(Node));
            assert(tmp);
            tmp->data = arr[i++];
            tmp->left = NULL;
            tmp->right = NULL;
            pNode->left = tmp;
            /*  push current node into stack, for popping when time for right child */
            pushStack(st , pNode);
            pNode = tmp;
        }
        /*  if element is larger than pNode but still smaller than parent node -> assign as right child but no push to stack */
        else if(arr[i] > pNode->data && !isStackEmpty(st) && arr[i] < (topStack(st)->data) ){
            tmp = (Node*)malloc(sizeof(Node));
            assert(tmp);
            tmp->data = arr[i++];
            tmp->left = NULL;
            tmp->right = NULL;
            /*  assign pNode as right child but no need to push to stack because else we are going two steps back not only one */
            pNode->right = tmp;
            pNode = tmp;
        }
        /*  if element is larger than pNode and larger than element in stack and stack is not empty
        then go step back (pop) to recheck with new pNode */
        else if(arr[i] > pNode->data && (!isStackEmpty(st)) && arr[i] > (topStack(st)->data) ){
            pNode = popStack(st);
        }
        /*  else means element is larger than pNode and larger than element in stack and stack is  empty
        so this means that is the largest element yet so it is to be pushed to right most way*/
        else{
            tmp = (Node*)malloc(sizeof(Node));
            assert(tmp);
            tmp->data = arr[i++];
            tmp->left = NULL;
            tmp->right = NULL;
            /*  assign pNode as right child but no need to push to stack because we never need to back to a node
            that has its left and right child filled already */
            pNode->right = tmp;
            pNode = tmp;
        }
    }
    return root;
}
/**
 * @brief Create a binary search tree from postorder traversal
 */
Node* createFromPostOrder(int arr[] , int len){
    int i = len-1;
    Stack *st = createStack();
    Node *tmp = NULL;
    Node *root = NULL;
    /* create root node and assign its data as arr[0] */
    Node *pNode = (Node*)malloc(sizeof(Node));
    assert(pNode);
    pNode->data = arr[i--];
    pNode->left = NULL;
    pNode->right = NULL;
    root = pNode;

    while(i >= 0){
        /*  if element is larger in postorder traversal then it's right child */
        if(arr[i] > pNode->data){
            tmp = (Node*)malloc(sizeof(Node));
            assert(tmp);
            tmp->data = arr[i--];
            tmp->left = NULL;
            tmp->right = NULL;
            /* assign tmp as pNode right child as push pNode into stack (to pop and make left child) and then assign pNode as tmp */
            pNode->right = tmp;
            pushStack(st, pNode);
            pNode = tmp;
        }
        /*  if element is smaller than pNode but still larger than parent node then assign as left child 
            but no need to push into stack because left child of this node ha already been created  */
        else if(arr[i] < pNode->data && !isStackEmpty(st) && arr[i] > topStack(st)->data){
            tmp = (Node*)malloc(sizeof(Node));
            assert(tmp);
            tmp->data = arr[i--];
            tmp->left = NULL;
            tmp->right = NULL;
            /* assign tmp as pNode right child and don't push pNode into stack */
            pNode->left = tmp;
            pNode = tmp;
        }
        /*  if element is smaller than both pNode and parent node then pop */
        else if(arr[i] < pNode->data && !isStackEmpty(st) && arr[i] < topStack(st)->data ){
            pNode = popStack(st);
        }
        /*  if element is smaller than pNode and stack is empty then assign as left child */
        else if(arr[i] < pNode->data && isStackEmpty(st)){
            tmp = (Node*)malloc(sizeof(Node));
            assert(tmp);
            tmp->data = arr[i--];
            tmp->left = NULL;
            tmp->right = NULL;
            /* assign tmp as pNode right child and don't push pNode into stack */
            pNode->left = tmp;
            pNode = tmp;
        }
    }
    return root;
}
/*  Main program code   */
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
    puts("\n\nIn order display after deleting 20");
    puts("===================================");
    inorder(root);

    puts("creating a new BST from pre order traversal : ");
    int arr[] = {5,3,1,2,4,9,8,6,7};
    Node* newBST = createFromPreOrder(arr, 9);
    puts("\n\nIn order display for new pre Order generated BST");
    puts("===================================");
    inorder(newBST);
    puts("");

    puts("creating a new BST from post order traversal : ");
    int newarr[] = {1,4,3,2,6,7,9,8,5};
    Node* newNewBST = createFromPostOrder(newarr, 9);
    puts("\n\nIn order display for new post Order generated BST");
    puts("===================================");
    inorder(newNewBST);

    return 0;
}