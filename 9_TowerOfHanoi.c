#include <stdio.h>

void move(char f, char t){
    printf("Move disc from %c to %c \n", f, t);
}

void hanoi(int n, char from, char middle, char to){
    if(n==0){
        return;
    }
    hanoi(n-1, from, to, middle);
    move(from, to);
    hanoi(n-1, middle, from, to);
}

int main() {
    hanoi(3, 'A', 'B', 'C');
    
    return 0;
}