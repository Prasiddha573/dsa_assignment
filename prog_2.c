#include <stdio.h>
#include <ctype.h>

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int apply(int a, int b, char op)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int main()
{
    char infix[100], postfix[100], stack[100];
    int values[100];
    int i, j = 0, top = -1, vtop = -1;

    fgets(infix, 100, stdin);

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            values[++vtop] = postfix[i] - '0';
        }
        else
        {
            int b = values[vtop--];
            int a = values[vtop--];
            values[++vtop] = apply(a, b, postfix[i]);
        }
    }

    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", values[vtop]);

    return 0;
}
