#include <iostream>
#include <stack>
#include <string>
#include <cctype>

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-') {  // If the operator is + or -
        return 1;  // Return precedence 1
    } else if (op == '*' || op == '/') {  // If the operator is * or /
        return 2;  // Return precedence 2
    } else {  // For any other operator
        return 0;  // Return precedence 0
    }
}

// Function to convert infix expression to postfix expression
std::string infixToPostfix(const std::string& infix) {
    std::string postfix = "";  // Initialize an empty string for the postfix expression
    std::stack<char> opStack;  // Initialize a stack to hold operators

    for (char c : infix) {  // Iterate over each character in the infix expression
        if (std::isalnum(c)) {  // If the character is an alphanumeric operand
            postfix += c;  // Append it to the postfix expression
        } else if (c == '(') {  // If the character is an opening parenthesis
            opStack.push(c);  // Push it onto the operator stack
        } else if (c == ')') {  // If the character is a closing parenthesis
            while (!opStack.empty() && opStack.top() != '(') {  // While the operator stack is not empty and the top is not (
                postfix += opStack.top();  // Append the top operator to the postfix expression
                opStack.pop();  // Pop the top operator from the stack
            }
            opStack.pop();  // Pop the remaining opening parenthesis from the operator stack
        } else {  // For any other operator
            while (!opStack.empty() && precedence(c) <= precedence(opStack.top())) {  // While the operator stack is not empty and the precedence of the current operator is less than or equal to the precedence of the top operator
                postfix += opStack.top();  // Append the top operator to the postfix expression
                opStack.pop();  // Pop the top operator from the stack
            }
            opStack.push(c);  // Push the current operator onto the operator stack
        }
    }

    while (!opStack.empty()) {  // While the operator stack is not empty
        postfix += opStack.top();  // Append the top operator to the postfix expression
        opStack.pop();  // Pop the top operator from the stack
    }

    return postfix;  // Return the final postfix expression
}

int main() {
    std::string infixExpression = "a+b*c-(d+e)/f";  // Define the input infix expression
    std::string postfix = infixToPostfix(infixExpression);  // Convert the infix expression to postfix
    std::cout << "Infix Expression: " << infixExpression << std::endl;  // Output the original infix expression
    std::cout << "Postfix Expression: " << postfix << std::endl;  // Output the converted postfix expression
    return 0;
}
