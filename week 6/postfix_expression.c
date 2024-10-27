#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* expression) {
    for (int i = 0; expression[i]; i++) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            int b = pop();
            int a = pop();
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
    printf("Enter postfix expression: ");
    scanf("%s", expression);

    printf("Result: %d\n", evaluatePostfix(expression));
    return 0;
}
