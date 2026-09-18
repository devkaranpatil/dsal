#include <iostream>
#include <string>
using namespace std;

class CharStack
{
    char arr[100];
    int top;

public:
    CharStack()
    {
        top = -1;
    }

    void push(char value)
    {
        if (top < 99)
        {
            top++;

            arr[top] = value;
        }
    }

    char pop()
    {
        if (top == -1)
        {
            return '\0';
        }

        char value = arr[top];
        top--;

        return value;
    }

    char peek()
    {
        if (top == -1)

        {
            return '\0';
        }

        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class IntStack
{
    int arr[100];
    int top;

public:
    IntStack()

    {
        top = -1;
    }

    void push(int value)
    {
        if (top < 99)
        {
            top++;
            arr[top] = value;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            return 0;
        }

        int value = arr[top];
        top--;

        return value;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' ||
        ch == '*' || ch == '/' ||
        ch == '^')
    {
        return true;
    }

    return false;
}

int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }

    return 0;
}

string reverseString(string str)
{
    string result = "";

    for (int i = str.length() - 1; i >= 0; i--)
    {
        result += str[i];
    }

    return result;
}

string swapBrackets(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {

            str[i] = ')';
        }
        else if (str[i] == ')')
        {
            str[i] = '(';
        }
    }

    return str;
}

string infixToPostfix(string infix)
{
    CharStack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch >= '0' && ch <= '9')
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }

            s.pop();
        }
        else if (isOperator(ch))
        {
            while (!s.isEmpty() &&

                   s.peek() != '(' &&
                   precedence(s.peek()) >= precedence(ch))
            {
                postfix += s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    return postfix;
}

string infixToPrefix(string infix)
{

    string reversed = reverseString(infix);

    reversed = swapBrackets(reversed);

    string postfix = infixToPostfix(reversed);

    string prefix = reverseString(postfix);

    return prefix;
}

int calculate(int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a * b;
    }
    else if (op == '/')
    {
        return a / b;
    }
    else if (op == '^')
    {
        int result = 1;

        for (int i = 0; i < b; i++)
        {
            result = result * a;
        }

        return result;
    }

    return 0;
}

int evaluatePostfix(string postfix)
{
    IntStack s;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }
        else if (isOperator(ch))
        {
            int b = s.pop();
            int a = s.pop();

            int result = calculate(a, b, ch);

            s.push(result);
        }
    }

    return s.pop();
}

int evaluatePrefix(string prefix)
{
    IntStack s;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (ch >= '0' && ch <= '9')
        {

            s.push(ch - '0');
        }
        else if (isOperator(ch))
        {
            int a = s.pop();
            int b = s.pop();

            int result = calculate(a, b, ch);

            s.push(result);
        }
    }

    return s.pop();
}

int main()
{
    string infix = "";
    string postfix = "";

    string prefix = "";

    int choice;

    do
    {
        cout << "\n\n----- MENU -----";
        cout << "\n1. Enter Infix Expression";
        cout << "\n2. Convert Infix to Postfix";
        cout << "\n3. Convert Infix to Prefix";
        cout << "\n4. Evaluate Postfix";
        cout << "\n5. Evaluate Prefix";
        cout << "\n6. Display All Expressions";
        cout << "\n7. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
        {
            cout << "Enter infix expression: ";
            cin >> infix;

            postfix = "";
            prefix = "";

            break;
        }

        case 2:
        {
            if (infix == "")
            {
                cout << "Please enter an infix expression first.";
            }
            else
            {
                postfix = infixToPostfix(infix);

                cout << "Postfix Expression: " << postfix;
            }

            break;
        }

        case 3:
        {
            if (infix == "")
            {
                cout << "Please enter an infix expression first.";
            }
            else
            {
                prefix = infixToPrefix(infix);

                cout << "Prefix Expression: " << prefix;
            }

            break;
        }

        case 4:
        {
            if (postfix == "")
            {
                if (infix == "")
                {
                    cout << "Please enter an infix expression first.";
                }
                else
                {
                    postfix = infixToPostfix(infix);
                }
            }

            if (postfix != "")
            {
                int result = evaluatePostfix(postfix);

                cout << "Postfix Expression: " << postfix;
                cout << "\nPostfix Evaluation: " << result;
            }

            break;
        }

        case 5:
        {
            if (prefix == "")
            {
                if (infix == "")
                {
                    cout << "Please enter an infix expression first.";
                }
                else
                {
                    prefix = infixToPrefix(infix);
                }
            }

            if (prefix != "")
            {
                int result = evaluatePrefix(prefix);

                cout << "Prefix Expression: " << prefix;
                cout << "\nPrefix Evaluation: " << result;
            }

            break;
        }

        case 6:
        {
            if (infix == "")
            {
                cout << "Please enter an infix expression first.";
            }
            else

            {
                postfix = infixToPostfix(infix);
                prefix = infixToPrefix(infix);

                cout << "\nInfix Expression: " << infix;
                cout << "\nPostfix Expression: " << postfix;
                cout << "\nPrefix Expression: " << prefix;
                cout << "\nPostfix Evaluation: "
                     << evaluatePostfix(postfix);
                cout << "\nPrefix Evaluation: "
                     << evaluatePrefix(prefix);
            }

            break;
        }

        case 7:
        {
            cout << "Program Exited.";
            break;
        }

        default:
        {
            cout << "Invalid Choice.";

            break;
        }
        }

    } while (choice != 7);

    return 0;
}