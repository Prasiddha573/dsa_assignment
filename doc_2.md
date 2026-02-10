# Program 2: Infix to Postfix Conversion and Evaluation

## Data Structures Used
A character stack is used for operators.  
An integer stack is used for evaluating postfix expression.

## Functions Implemented
precedence() returns priority of operators.  
apply() performs arithmetic operation on two values.

## Organization of main()
The main function reads an infix expression.  
It converts the infix expression to postfix using a stack.  
Then the postfix expression is evaluated using another stack.  
Finally, postfix expression and result are displayed.

## Sample Output

Input:
(2+3)*4

Output:
Postfix: 23+4*
Result: 20
