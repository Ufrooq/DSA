#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    char *array;
    int top;
    Stack(int size)
    {
        this->size = size;
        array = new char[size];
        top = -1;
    }

    char peek() { return (top == -1) ? '\0' : array[top]; }

    char pop() { return (top == -1) ? '\0' : array[top--]; }

    bool isEmpty() { return top == -1 ? true : false; }

    void push(char element)
    {
        if (size - top > 1)
            array[++top] = element;
        else
            cout << "\nStack is FUll ----> " << endl;
    }
    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '-' || c == '+')
            return 1;
        else
            return -1; // for paranthesis
    }

    string
    infixToPostfix(string str)
    {
        string postfixExp;
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                postfixExp += str[i];

            else if (str[i] == '(')
                push(str[i]);

            else if (str[i] == ')')
            {
                while (!isEmpty() && peek() != '(')
                {
                    postfixExp += peek();
                    pop();
                }
                // to pop the opening bracket
                if (!isEmpty())
                    pop();
            }
            else
            {
                while (!isEmpty() && precedence(peek()) >= precedence(str[i]))
                {
                    postfixExp += peek();
                    pop();
                }
                push(str[i]);
            }
        }
        while (!isEmpty())
        {
            postfixExp += peek();
            pop();
        }
        return postfixExp;
    }
};

int main()
{
    Stack st(10);
    int n;
    while (true)
    {
        cout << "\nPress 1 to push element -->" << endl;
        cout << "Press 2 to pop element -->" << endl;
        cout << "Press 3 to Peek element -->" << endl;
        cout << "Press 4 for isEmpty() -->" << endl;
        cout << "Press 5 to convert Infix to Postfix -->" << endl;
        cout << "Press 0 to exit -->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
        {
            char x;
            cout << "Enter Element : ";
            cin >> x;
            st.push(x);
        }
        else if (n == 2)
            cout << "\nPopped elemt is " << st.pop() << endl;
        else if (n == 3)
            cout << "Top element is " << st.peek() << endl;
        else if (n == 4)
        {
            if (st.isEmpty())
                cout << "\nStack is empty -->\n";
            else
                cout << "\nStack is not Empty -->\n";
        }
        else if (n == 5)
        {
            string expression = "A+B/C+D*(E-F)^G";
            cout << "\nPostfix expression of " << expression << " is " << st.infixToPostfix(expression) << endl;
        }
        else if (n == 0)
            break;
    }
    return 0;
};