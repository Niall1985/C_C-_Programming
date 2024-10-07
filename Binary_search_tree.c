// Q)Problem Statement
// John is learning about Binary Search Trees (BST) in his computer science class. He wants to create a program that allows users to delete a node with a given value from a BST and print the remaining nodes.
// Implement a function to help him delete a node with a given value from a BST.

// Input format :
// The first line of input consists of an integer N, representing the number of nodes in the BST.

// The second line consists of N space-separated integers, representing the values of the BST nodes.

// The third line consists of an integer V, which is the value to delete from the BST.

// Output format :
// The output prints the space-separated values in the BST in an in-order traversal, after the deletion of the specified value.

// If the specified value is not available in the tree, print the given input values in-order traversal.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// 1 ≤ node values ≤ 100

// 1 ≤ V ≤ 100

// The input values are unique integers.

// Sample test cases :
// Input 1 :
// 5
// 10 5 15 2 7
// 15
// Output 1 :
// 2 5 7 10 
// Input 2 :
// 7
// 50 30 70 20 40 60 80
// 50
// Output 2 :
// 20 30 40 60 70 80 
// Input 3 :
// 3
// 4 7 6
// 8
// Output 3 :
// 4 6 7 


#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *temp, int data){
    if(temp == NULL){
        return newNode(data);
    }
    if(data<temp->data){
        temp->left = insert(temp->left,data);
    }
    else if(data>temp->data){
        temp->right = insert(temp->right,data);
    }
    return temp;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
  
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


struct node *deleteNode(struct node *temp, int key){
    if(temp == NULL){
        return temp;
    }
    
    if(key < temp->data){
        temp->left = deleteNode(temp->left, key);
    }
    else if(key>temp->data){
        temp->right = deleteNode(temp->right, key);
    }
    else{
        if(temp->left == NULL && temp->right == NULL){
            free(temp);
            return NULL;
        }
        
        if(temp->left == NULL){
            struct node *root = temp->right;
            free(temp);
            return root;
        }
        else if(temp->right == NULL){
            struct node *root = temp->left;
            free(temp);
            return root;
        }
        
        struct node *root = minValueNode(temp->right);
            temp->data = root->data;
            temp->right = deleteNode(temp->right, root->data);
        }
    return temp;
}

void inorder(struct node *temp){
    if(temp == NULL){
        return;
    }
    inorder(temp->left);
    printf("%d ", temp->data);
    inorder(temp->right);
}
int main(){
    int n, data, key;
    struct node *root = NULL;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }
    scanf("%d", &key);
    root=deleteNode(root, key);
    inorder(root);
}


// Problem Statement
// Kamal is interested in managing a collection of integers using a Binary Search Tree (BST). 
//He wants to write a program that constructs a BST from a given set of integers and then deletes all the nodes with values greater than the average value of all nodes in the BST.
// Help him solve this problem.
// Example

// Input:

// 5

// 10 20 30 40 50

// Output:

// 10 20 30

// Explanation:

// The sum of values is 10 + 20 + 30 + 40 + 50 = 150, and there are 5 nodes. So, the average is 150 / 5 = 30. Then, delete nodes with values greater than the average (30). The final output is the values of the remaining nodes in the BST, which are 10, 20 and 30.

// Input format :
// The first line consists of an integer N, representing the number of elements in the BST.

// The second line consists of N space-separated integers, representing the BST elements.

// Output format :
// The output prints the remaining integers in the BST after deleting nodes greater than the average value, separated by a space.

// The integers should be printed in an in-order traversal.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ elements ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 10 20 30 40 50
// Output 1 :
// 10 20 30 
// Input 2 :
// 6
// 20 52 65 98 74 57
// Output 2 :
// 20 52 57 

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


struct node *insert(struct node *root, int data){
    if(root == NULL){
        return newNode(data);
    }
    
    if(data<root->data){
        root->left = insert(root->left, data);
    }
    else if(data>root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

struct node *minValueNode(struct node *node) {
    struct node *current = node;
  
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


struct node *deleteNode(struct node *temp, int key){
    if(temp == NULL){
        return temp;
    }
    
    if(key < temp->data){
        temp->left = deleteNode(temp->left, key);
    }
    else if(key>temp->data){
        temp->right = deleteNode(temp->right, key);
    }
    else{
        if(temp->left == NULL && temp->right == NULL){
            free(temp);
            return NULL;
        }
        
        if(temp->left == NULL){
            struct node *root = temp->right;
            free(temp);
            return root;
        }
        else if(temp->right == NULL){
            struct node *root = temp->left;
            free(temp);
            return root;
        }
        
        struct node *root = minValueNode(temp->right);
            temp->data = root->data;
            temp->right = deleteNode(temp->right, root->data);
        }
    return temp;
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main(){
    struct node *root = NULL;
    int n, data, sum = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &data);
        root = insert(root, data);
        arr[i] = data;
        sum += data;
    }
    
    int avg = sum/n;
    for(int i = 0 ; i < n ; i++){
        if(arr[i]>avg){
            root = deleteNode(root, arr[i]);
        }
    }
    
    inorder(root);
}
