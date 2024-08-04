#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int top;
    char items[MAX];
} Stack;
void push(Stack* s, char item) {
    if (s->top == (MAX - 1)) {
        printf("Stack is full\n");
        return;
    }
    s->items[++(s->top)] = item;
}
char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[(s->top)--];
}
char peek(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->items[s->top];
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack s;
    s.top = -1;
    int j = 0;
    
    for (int i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); 
        } else if (isOperator(infix[i])) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    while (s.top != -1) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

void generateAssembly(char* postfix) {
    char stack[MAX][10];
    int top = -1; 
    int regCount = 0; 
    char reg[10]; 

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            top++;
            sprintf(stack[top], "R%d", regCount);
            printf("MOV R%d, %c\n", regCount, postfix[i]);
            regCount++;
        } else {
            char operand2[10], operand1[10];
            strcpy(operand2, stack[top]);
            top--;
            strcpy(operand1, stack[top]);
            top--;

            switch (postfix[i]) {
                case '+':
                    printf("ADD %s, %s\n", operand1, operand2);
                    sprintf(stack[top], "%s", operand1); 
                    break;
                case '-':
                    printf("SUB %s, %s\n", operand1, operand2);
                    sprintf(stack[top], "%s", operand1);
                    break;
                case '*':
                    printf("MUL %s, %s\n", operand1, operand2);
                    sprintf(stack[top], "%s", operand1);
                    break;
                case '/':
                    printf("DIV %s, %s\n", operand1, operand2);
                    sprintf(stack[top], "%s", operand1); 
                    break;
            }
        }
    }
}

int main() {
        char expression[100];
        char postfix[MAX];
        printf("Enter the expression:");
        scanf("%s",expression);
        infixToPostfix(expression, postfix);
        generateAssembly(postfix);
        printf("\n");
        return 0;
    }
