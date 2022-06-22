#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* header;

void insertAtBeginning(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = header;
    header = temp;
}

void insertAtNthPosition(int data, int n){
    // Step 1 traversal to nth position
    struct Node* temp = header;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    
    // If position of n is 1, insert at the beginning
    if(n==1){
        newNode->next=header;
        header = newNode;
        return;
    }
    
    int i;
    
    for(i=0; i<n-2; i++){
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(int data){
    struct Node* temp = header;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Traversal to the end
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->data = data;
    
}

void deleteAtBeginning(){
    struct Node* deleteNode = header;
    // Make header point to next element
    header = header->next;
    
    free(deleteNode);
}

void deleteAtNthPosition(int n){
    struct Node* temp = header;
    // Traversal at the position
    for(int i=0; i<n-2; i++){
        temp = temp->next;
    }
    
    struct Node* deleteNode = temp->next;
    
    // Make n-1 node point to n+1
    temp->next = deleteNode->next;
    
    // Free up memory
    
    free(deleteNode);
    
}

void deleteAtEnd(){
    struct Node* temp = header;
    
    // Traversal to the end
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    
    struct Node* deleteNode = temp->next;
    // Remove the link
    temp->next = NULL;
    
    free(deleteNode);
}

void display(){
    struct Node* temp = header;
    printf("List is: ");
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    header = NULL;
    
    insertAtBeginning(10);
    insertAtBeginning(43);
    insertAtBeginning(93);
    insertAtBeginning(32);
    insertAtEnd(20);
    insertAtEnd(25);
    display();
    deleteAtEnd();
    display();
    
    /*printf("How many numbers? \n");
    int n, i, x, p;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        printf("Enter the position \n");
        scanf("%d", &p);
        insertAtNthPosition(x, p);
        display();
    }*/
    
    return 0;
}