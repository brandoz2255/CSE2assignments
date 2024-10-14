#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "Stack.h"

#define STACK_SIZE 100

typedef struct {
    int items[STACK_SIZE];
    int top;
} Stack;


// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// Check if the stack is full
bool isFull(Stack* s) {
    return s->top == STACK_SIZE - 1;
}

// Push an item onto the stack
void push(Stack* s, int item) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", item);
    } else {
        s->top++;
        s->items[s->top] = item;
        printf("Pushed %d onto the stack\n", item);
    }
}

// Pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1;
    } else {
        int item = s->items[s->top];
        s->top--;
        printf("Popped %d from the stack\n", item);
        return item;
    }
}

// Peek at the top item of the stack
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

// Display the current state of the stack
void displayStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
        printf("----\n");
    }
}

// Simulate stack operations
void simulateStack() {
    Stack s;
    initStack(&s);
    
    int choice, item;
    
    do {
        printf("\nStack Simulator\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                item = peek(&s);
                if (item != -1) {
                    printf("Top item: %d\n", item);
                }
                break;
            case 4:
                displayStack(&s);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

// TUI functions for stack simulator

void clearScreen() {
    system("clear");  // Use "cls" for Windows
}

void drawBorder(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1) {
                printf("-");
            } else if (j == 0 || j == width - 1) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void drawStack(Stack *s, int width, int height) {
    int startY = height - 3;
    for (int i = 0; i < s->top && startY > 1; i++, startY--) {
        printf("\033[%d;%dH[%d]", startY, (width - 3) / 2, s->items[i]);
    }
}

void drawMenu(int height) {
    printf("\033[%d;2H1:Push 2:Pop 3:Peek 4:Display 0:Exit", height - 1);
}

void simulateStackTUI() {
    Stack s;
    initStack(&s);
    
    int choice, item;
    int width = 40, height = 20;
    
    do {
        clearScreen();
        drawBorder(width, height);
        drawStack(&s, width, height);
        drawMenu(height);
        
        printf("\033[%d;2HEnter your choice: ", height);
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\033[%d;2HEnter item to push: ", height);
                scanf("%d", &item);
                push(&s, item);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                item = peek(&s);
                if (item != -1) {
                    printf("\033[%d;2HTop item: %d", height, item);
                    getchar(); getchar(); // Wait for user input
                }
                break;
            case 4:
                clearScreen();
                displayStack(&s);
                printf("\nPress Enter to continue...");
                getchar(); getchar(); // Wait for user input
                break;
            case 0:
                printf("\033[%d;2HExiting...", height);
                break;
            default:
                printf("\033[%d;2HInvalid choice!", height);
                getchar(); getchar(); // Wait for user input
        }
    } while (choice != 0);
}


int main() {
    simulateStackTUI();
    return 0;
}

// The main function should be in a separate file, not in Stack.c
// No changes needed in this file.



