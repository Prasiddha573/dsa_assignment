#include <stdio.h>
#include <string.h>

int main()
{
    char expr[200];
    char stack[200];
    int top = -1;
    int i;
    int balanced = 1;

    fgets(expr, 200, stdin);

    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            stack[++top] = expr[i];
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            if (top == -1)
            {
                balanced = 0;
                break;
            }
            if ((expr[i] == ')' && stack[top] == '(') ||
                (expr[i] == ']' && stack[top] == '[') ||
                (expr[i] == '}' && stack[top] == '{'))
            {
                top--;
            }
            else
            {
                balanced = 0;
                break;
            }
        }
    }

    if (top != -1)
        balanced = 0;

    if (balanced)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
