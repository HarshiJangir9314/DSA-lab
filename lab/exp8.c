#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;    
}; 
struct node* create(int data) {
    struct node* newnode;
    newnode = (struct node*) malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Unable to allocate memory\n");
        return NULL;
    }  
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return(newnode);
}



struct node* insert(struct node*root, int data){  
    if (root == NULL)
    return(create(data));

    if (data < root->data)
     root->left = insert(root->left,data);
    else if (data > root->data)
     root->right = insert(root->right, data);
    
    
    return root;
}
int main() {
    struct Node* root = NULL; 
 
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

  
    int value = 40;
    if (search(root, value)) {
        printf("Node with value %d found in the BST.\n", value);
    } else {
        printf("Node with value %d not found in the BST.\n", value);
    }

    return 0;
}