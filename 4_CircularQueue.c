// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define MAXQUEUE 10

struct queue{
    int items[MAXQUEUE];
    int front;
    int rear;
};

int isEmpty(struct queue *q){
    if(q->rear == q->front){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue *q, int item){
    // Check if queue is full
    if(q->rear==MAXQUEUE-1){
        printf("Queue is full \n");
        exit(1);
    }
    // Increment rear by 1
    q->rear++;
    // Insert the element
    q->items[q->rear] = item;
}

int dequeue(struct queue *q){
    // Check if queue is empty
    if(isEmpty(q)){
        printf("Queue is empty \n");
        exit(1);
    }
    
    if(q->front==MAXQUEUE-1){
        q->front = 0;
    }else{
        q->front++;
    }
    
    int item = q->items[q->front];
    return item;
}

void display(struct queue *q){
    // Loop and display
    for (int i = q->front; i < q->rear+1; i++){
        int item = q->items[i];
        printf("%d \n",item);
    }
}

int main() {
    
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = MAXQUEUE-1;
    
    int loop = 1;
    
    while(loop){
        int action;
        printf("Enter a operation \n");
        printf("0. Enqueue \n");
        printf("1. Dequeue \n");
        printf("2. Display \n");
        printf("3. Exit \n");
        scanf("%d", &action);
        int item;
        
        switch(action){
            case 0:
            printf("Enter an item \n");
            scanf("%d", &item);
            enqueue(q, item);
            break;
            
            case 1:
            printf("%d \n", dequeue(q));
            break;
            
            case 2:
            display(q);
            break;
            
            case 3:
            loop = 0;
            break;
        }
    }
    
    return 0;
}