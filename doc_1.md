# Question 1 Documentation

## (a) Data Structure Definition
This program uses a stack to check balanced parentheses.
The stack is implemented using a character array and a top variable.

char stack[MAX];
int top = -1;

Opening brackets are pushed into the stack while scanning the expression.

## (b) Functions Description

push(char c)  
Inserts an opening bracket into the stack.

pop()  
Removes the top element from the stack.

isMatching(char open, char close)  
Checks whether two brackets match: (), {}, [].

isBalanced(char exp[])  
Reads the expression and checks whether the parentheses are balanced or not.

## (c) main() Overview
The main() function contains three given expressions.
Each expression is checked using isBalanced() and the result is displayed.

Steps:
1. Store expressions in an array.
2. Check each expression using isBalanced().
3. Print the result.

## (d) Sample Output

Expression: a + (b - c) * (d
Not Balanced

Expression: m + [a - b * (c + d * {m)]
Not Balanced

Expression: a + (b - c)
Balanced Parentheses