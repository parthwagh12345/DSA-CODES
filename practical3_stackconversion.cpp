#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(char value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (!isEmpty())
        {
            char value = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            return value;
        }
        return '\0';
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    char peek()
    {
        if (!isEmpty())
        {
            return top->data;
        }
        return '\0';
    }
};

class StackExpressions
{
public:
    int getPrecedence(char c)
    {
        if (c == '^')
            return 3;
        if (c == '*' || c == '/')
            return 2;
        if (c == '+' || c == '-')
            return 1;
        return 0;
    }

    string infixToPostfix()
    {
        Stack stack;
        string postfix = "";
        string infix;
        cout << "Enter a infix expression that you want to convert to postfix: " << endl;
        cin >> infix;

        for (int i = 0; i < infix.length(); i++)
        {
            char c = infix[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                postfix = postfix + c;
            }
            else if (c == '(')
            {
                stack.push(c);
            }
            else if (c == ')')
            {
                while (!stack.isEmpty() && stack.peek() != '(')
                {
                    postfix = postfix + stack.pop();
                }
                if (!stack.isEmpty() && stack.peek() == '(')
                    stack.pop(); // Pop the opening parenthesis.
            }
            else
            {
                while (!stack.isEmpty() && getPrecedence(c) <= getPrecedence(stack.peek()))
                {
                    postfix = postfix + stack.pop();
                }
                stack.push(c);
            }
        }

        while (!stack.isEmpty())
        {
            postfix += stack.pop();
        }

        return postfix;
    }

    string reverseString(string str)
    {
        string reversed;
        for (int i = str.length() - 1; i >= 0; i--)
        {
            reversed += str[i];
        }
        return reversed;
    }

    string infixToPrefix()
    {
        Stack stack;
        string infix;
        string prefix = "";
        cout << "Enter a infix expression that you want to convert to prefix: " << endl;
        cin >> infix;
        string reversedInfix = reverseString(infix);

        for (int i = 0; i < reversedInfix.length(); i++)
        {
            char c = reversedInfix[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                prefix += c;
            }
            else if (c == ')')
            {
                stack.push(c);
            }
            else if (c == '(')
            {
                while (!stack.isEmpty() && stack.peek() != ')')
                {
                    prefix += stack.pop();
                }
                stack.pop(); // Pop the ')'
            }
            else
            {
                while (!stack.isEmpty() && getPrecedence(c) <= getPrecedence(stack.peek()))
                {
                    prefix += stack.pop();
                }
                stack.push(c);
            }
        }

        while (!stack.isEmpty())
        {
            prefix += stack.pop();
        }

        return reverseString(prefix);
    }

    int evaluatePostfix()
    {
        Stack stack;
        string postfix;
        cout << "Enter postfix expression that you want to evaluate: " << endl;
        cin >> postfix;

        for (int i = 0; i < postfix.length(); i++)
        {
            char c = postfix[i];
            if (c >= '0' && c <= '9')
            {
                stack.push(c - '0'); // Convert the character to its corresponding integer value
            }
            else
            {
                int operand1 = stack.pop();
                int operand2 = stack.pop();
                switch (c)
                {
                case '+':
                    stack.push(operand2 + operand1);
                    break;
                case '-':
                    stack.push(operand2 - operand1);
                    break;
                case '*':
                    stack.push(operand2 * operand1);
                    break;
                case '/':
                    stack.push(operand2 / operand1);
                    break;
                }
            }
        }

        return stack.pop();
    }

    int evaluatePrefix()
    {
        Stack stack;
        string prefix;
        cout << "Enter Prefix expression that you want to evaluate: " << endl;
        cin >> prefix;

        // Iterate through the expression in reverse
        for (int i = prefix.length() - 1; i >= 0; i--)
        {
            char c = prefix[i];

            if (c >= '0' && c <= '9')
            {
                stack.push(c - '0'); // Convert the character to its corresponding integer value
            }
            else
            {
                int operand1 = stack.pop();
                int operand2 = stack.pop();
                int result;
                switch (c)
                {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                }
                stack.push(result);
            }
        }

        return stack.pop();
    }
};

int main()
{
    int choice;
    string result_expression;
    char result;
    int evaluate_expression;
    StackExpressions stackExpressions;

    while (true)
    {
        cout << endl
             << endl
             << "Stack Menu" << endl;
        cout << "1. Convert Infix to Postfix" << endl;
        cout << "2. Convert Infix to Prefix" << endl;
        cout << "3. Evaluate Postfix Expression " << endl;
        cout << "4. Evaluate Prefix Expression " << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            result_expression = stackExpressions.infixToPostfix();
            cout << "Postfix Expression: " << result_expression;
            break;

        case 2:
            result_expression = stackExpressions.infixToPrefix();
            cout << "Prefix Expression: " << result_expression;
            break;

        case 3:
            evaluate_expression = stackExpressions.evaluatePostfix();
            cout << "Evaluated Postfix Expression: " << evaluate_expression;
            break;

        case 4:
            evaluate_expression = stackExpressions.evaluatePrefix();
            cout << "Evaluated Prefix Expression: " << evaluate_expression;
            break;

        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid Choice! Please try again." << endl;
        }
    }

    return 0;
}