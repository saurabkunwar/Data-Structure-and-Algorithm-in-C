#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* header;

void push(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = header;
    header = newNode;
}

void pop(){
    // Fix link
    struct Node* node = header;
    header = node->next;
    
    // Free up memory
    free(node);
}

void display(){
    struct Node* temp = header;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    header = NULL;
    
    push(5);
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    
    return 0;
}