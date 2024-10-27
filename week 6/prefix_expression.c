#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char* expression) {
    int n = strlen(expression);
    for (int i = n - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            int a = pop();
            int b = pop();
            switch (expression[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char expression[MAX];
    printf("Enter prefix expression: ");
    scanf("%s", expression);

    printf("Result: %d\n", evaluatePrefix(expression));
    return 0;
}
