#include <stdio.h>

void move(char f, char t){
    printf("Move disc from %c to %c \n", f, t);
}

void hanoi(int n, char f, char h, char t){
    if(n==0){
        return;
    }
    hanoi(n-1, f, t, h);
    move(f, t);
    hanoi(n-1, h, f, t);
}

int main() {
    hanoi(3, 'A', 'B', 'C');
    
    return 0;
}