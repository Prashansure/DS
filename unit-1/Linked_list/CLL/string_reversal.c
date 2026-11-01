
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push a character onto the stack
void push(char ch) {
    stack[++top] = ch;
}

// Pop a character from the stack
char pop() {
    return stack[top--];
}

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%99s", str);

    // Push each character
    for (i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop characters to reverse the string
    printf("Reversed string: ");

    while (top != -1) {
        printf("%c", pop());
    }

    printf("\n");

    return 0;
}

