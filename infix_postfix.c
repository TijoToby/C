#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
    else
        printf("Stack Overflow\n");
}
char pop() {
    if (top >= 0)
        return stack[top--];
    else {
        printf("Stack Underflow\n");
        return '\0';
    }
}
char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}
int precedence(char op) {
    if (op == '+' || op == '-') 
        return 1;
    else if (op == '*' || op == '/') 
        return 2;
    else if (op == '^') 
        return 3;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, k = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isalpha(ch) || isdigit(ch)) {
            postfix[k++] = ch;
        } 
        else if (ch == '(') {
            push(ch);
        } 
        else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            if (peek() == '(')
                pop(); 
        } 
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0'; 
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

