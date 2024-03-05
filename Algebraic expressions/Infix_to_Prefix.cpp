#include <iostream>  // Include input/output stream library
#include <stack>  // Include stack library
#include <string>  // Include string library
#include <cctype>  // Include character handling functions
#include <algorithm>  // Include algorithm library for reverse function

int precedence(char op) {  // Function to determine the precedence of an operator
    if (op == '+' || op == '-') {
        return 1;  // Return precedence 1 for + and -
    } else if (op == '*' || op == '/') {
        return 2;  // Return precedence 2 for * and /
    } else {
        return 0;  // Return precedence 0 for other operators
    }
}

std::string infixToPrefix(const std::string& infix) {  // Function to convert infix expression to prefix expression
    std::string prefix = "";  // Initialize an empty string for the prefix expression
    std::stack<char> opStack;  // Initialize a stack to hold operators
    std::string reversedInfix = infix;  // Create a copy of the infix expression
    std::reverse(reversedInfix.begin(), reversedInfix.end());  // Reverse the copy of the infix expression

    for (char& c : reversedInfix) {  // Iterate over each character (operand or operator) in the reversed infix expression
        if (std::isalnum(c)) {  // If the character is an alphanumeric operand
            prefix = c + prefix;  // Append it to the prefix expression
        } else if (c == '(') {  // If the character is an opening parenthesis
            while (!opStack.empty() && opStack.top() != ')') {  // While the operator stack is not empty and the top is not )
                prefix = opStack.top() + prefix;  // Append the top operator to the prefix expression
                opStack.pop();  // Pop the top operator from the stack
            }
            opStack.pop();  // Pop the remaining closing parenthesis from the operator stack
        } else if (c == ')') {  // If the character is a closing parenthesis
            opStack.push(c);  // Push it onto the operator stack
        } else {  // For any other operator
            while (!opStack.empty() && precedence(c) < precedence(opStack.top())) {  // While the operator stack is not empty and the precedence of the current operator is less than the precedence of the top operator
                prefix = opStack.top() + prefix;  // Append the top operator to the prefix expression
                opStack.pop();  // Pop the top operator from the stack
            }
            opStack.push(c);  // Push the current operator onto the operator stack
        }
    }

    while (!opStack.empty()) {  // While the operator stack is not empty
        prefix = opStack.top() + prefix;  // Append the top operator to the prefix expression
        opStack.pop();  // Pop the top operator from the stack
    }

    return prefix;  // Return the final prefix expression
}

int main() {  // Main function
    std::string infixExpression = "a+b*c-(d+e)/f";  // Define the input infix expression
    std::string prefix = infixToPrefix(infixExpression);  // Convert the infix expression to prefix
    std::cout << "Infix Expression: " << infixExpression << std::endl;  // Output the original infix expression
    std::cout << "Prefix Expression: " << prefix << std::endl;  // Output the converted prefix expression
    return 0;  // Return 0 to indicate successful execution
}
