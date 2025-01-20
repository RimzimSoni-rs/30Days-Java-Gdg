#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert prefix expression to infix recursively
string convertPrefixToInfix(string& prefix, int& index) {
    // Base case: if the index is out of bounds, return an empty string
    if (index >= prefix.size()) return "";
    
    // Get the current character
    char ch = prefix[index];
    
    // If the character is an operand, return it as a string
    if (!isOperator(ch)) {
        index++;  // Move to the next character
        return string(1, ch);  // Return the operand
    }
    
    // Otherwise, the current character is an operator
    index++;  // Move to the next character
    
    // Recursively convert the left and right operands
    string leftOperand = convertPrefixToInfix(prefix, index);
    string rightOperand = convertPrefixToInfix(prefix, index);
    
    // Return the infix expression with proper parentheses
    return "(" + leftOperand + " " + ch + " " + rightOperand + ")";
}


int main() {
    string prefix;
    cin >> prefix;
    
    int index = 0;  // Start from the beginning of the prefix expression
    string infix = convertPrefixToInfix(prefix, index);
    
    cout << infix << endl;
    return 0;
}