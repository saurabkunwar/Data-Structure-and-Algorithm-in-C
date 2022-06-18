#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int isOperand(char chr){
    if(chr=='+'|| chr=='-' || chr=='*' || chr=='/' || chr=='$'){
        return 1;
    }else{
        return 0;
    }
}

int operate(int op1, int op2, char chr){
    int result=1;
    switch(chr){
        case '+':
        return op1 + op2;
        break;
        
        case '-':
        return op1 - op2;
        break;
        
        case '*':
        return op1 * op2;
        break;
        
        case '/':
        return op1 / op2;
        break;
        
        case '$':
        while (op2 != 0) {
            result *= op1;
            --op2;
        }
        return result;
        break;
    }
}

int main() {
    
    char expression[] = "623+-382/+*2$3+";
    
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    
    for (int i = 0; i < strlen(expression); i++) {
       char chr = expression[i];
       
       if(isOperand(chr)){
           int op2 = pop(s);
           int op1 = pop(s);
           int value = operate(op1, op2, chr);
           printf("%d \n", value);
           push(s, value);
        }else{
            int item = chr - '0';
            push(s, item);
        }
       
    }
    
    return 0;
}