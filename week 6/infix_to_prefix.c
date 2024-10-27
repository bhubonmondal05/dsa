#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infixToPrefix(char* expression) {
    reverse(expression);

    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '(') expression[i] = ')';
        else if (expression[i] == ')') expression[i] = '(';
    }

    char output[MAX];
    int k = 0;

    for (int i = 0; expression[i]; i++) {
        if (isalnum(expression[i])) {
            output[k++] = expression[i];
        } else if (expression[i] == '(') {
            push(expression[i]);
        } else if (expression[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                output[k++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(expression[i])) {
                output[k++] = pop();
            }
            push(expression[i]);
        }
    }

    while (top != -1) {
        output[k++] = pop();
    }
    output[k] = '\0';

    reverse(output);
    printf("Prefix expression: %s\n", output);
}

int main() {
    char expression[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expression);

    infixToPrefix(expression);
    return 0;
}
