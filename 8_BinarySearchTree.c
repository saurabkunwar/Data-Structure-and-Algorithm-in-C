#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* root;

void insert(int data){
    
    // Condition for first element
    if(root==NULL){
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    
    struct Node* current = root;
    
    while(1){
        if(current->data > data){
            if(current->left == NULL){
                struct Node* node = (struct Node*)malloc(sizeof(struct Node));
                node->data = data;
                node->left = NULL;
                node->right = NULL;
                current->left = node;
                break;
            }else{
                current = current->left;
            }
        }else{
            if(current->right == NULL){
                struct Node* node = (struct Node*)malloc(sizeof(struct Node));
                node->data = data;
                node->left = NULL;
                node->right = NULL;
                current->right = node;
                break;
            }else{
                current = current->right;
            }
        }
    }
}

void printNode(struct Node* node){
    if(node==NULL){
        return;
    }
    
    printf("%d ", node->data);
    
    printNode(node->left);
    printNode(node->right);
}

int main() {
    insert(5);
    insert(10);
    insert(1);
    insert(12);
    insert(7);
    insert(2);
    
    printNode(root);
    
    return 0;
}