#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* head;

void insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void reverseUsingIteration(){
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void reverseUsingRecursion(){
    
}

void display(){
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    insert(10);
    insert(20);
    insert(30);
    display();
    reverseUsingIteration();
    display();
}