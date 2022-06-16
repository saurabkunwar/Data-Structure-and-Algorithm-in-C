#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

struct stack{
    int top;
    int items[STACKSIZE];
};

int isEmpty(struct stack *s){
    return (s->top==-1);
}

void push(struct stack *s, int item){
    // Check if stack is full
    if(s->top==STACKSIZE-1){
        printf("Overflow \n");
        exit(1);
    }else{
        s->top++;
        s->items[s->top] = item;
    }
}

int pop(struct stack *s){
    // Check if stack is empty
    if(isEmpty(s)){
        printf("Stack is empty \n");
        exit(1);
    }else{
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

void display(struct stack *s){
    for (int i = 0; i < s->top+1; i++){
        int item = s->items[i];
        printf("%d \n",item);
    }
}

int main() {
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    
    int loop = 1;
    
    while(loop){
        int action;
        printf("Enter a operation \n");
        printf("0. Push \n");
        printf("1. Pop \n");
        printf("2. Display \n");
        printf("3. Exit \n");
        scanf("%d", &action);
        int item;
        
        switch(action){
            case 0:
            printf("Enter an item \n");
            scanf("%d", &item);
            push(s, item);
            break;
            
            case 1:
            printf("%d \n", pop(s));
            break;
            
            case 2:
            display(s);
            break;
            
            case 3:
            loop = 0;
            break;
        }
    }
    
    return 0;
}