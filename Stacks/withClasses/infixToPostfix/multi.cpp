#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    char *postfixArray;
    char *paranthesisArray;
    int TOP_array;
    int TOP_paranthesis;
    Stack(int size)
    {
        this->size = size;
        postfixArray = new char[size];
        paranthesisArray = new char[size];
        TOP_array = -1;
        TOP_paranthesis = -1;
    }

    char peek(char *array, int *top) { return (*top == -1) ? '\0' : array[*top]; }
    char pop(char *array, int *top) { return (*top == -1) ? '\0' : array[(*top)--]; }

    bool isEmpty(int *top) { return *top == -1 ? true : false; }

    void push(char *array, char element, int *top)
    {
        if (size - *top > 1)
            array[++(*top)] = element;
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
    // int precedence(char c)
    // {
    //     if (c == '{')
    //         return 3;
    //     else if (c == '[')
    //         return 2;
    //     else if (c == '(')
    //         return 1;
    //     else
    //         return -1; // for paranthesis
    // }

    string infixTOPostfix(string str)
    {
        string postfixExp;
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                postfixExp += str[i];

            else if (str[i] == '(')
            {
                push(paranthesisArray, str[i], &TOP_paranthesis);
                push(postfixArray, str[i], &TOP_array);
            }

            else if (str[i] == ')')
            {
                pop(paranthesisArray, &TOP_paranthesis);
                while (!isEmpty(&TOP_array) && peek(postfixArray, &TOP_array) != '(')
                {
                    postfixExp += peek(postfixArray, &TOP_array);
                    pop(postfixArray, &TOP_array);
                }
                // to pop the opening bracket
                if (!isEmpty(&TOP_array))
                    pop(postfixArray, &TOP_array);
            }
            else
            {
                while (!isEmpty(&TOP_array) && precedence(peek(postfixArray, &TOP_array)) >= precedence(str[i]))
                {
                    postfixExp += peek(postfixArray, &TOP_array);
                    pop(postfixArray, &TOP_array);
                }
                push(postfixArray, str[i], &TOP_array);
            }
        }

        while (!isEmpty(&TOP_array))
        {
            postfixExp += peek(postfixArray, &TOP_array);
            pop(postfixArray, &TOP_array);
        }

        return isEmpty(&TOP_paranthesis) ? postfixExp : "\nExpression was invalid -->\n";
    }

    void display()
    {
        for (int i = 0; i <= TOP_array; i++)
        {
            cout << postfixArray[i] << " ";
        }
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
        cout << "Press 6 to Display full " << endl;
        cout << "Press 0 to exit -->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
        {
            char elem;
            cout << "Enter Element : ";
            cin >> elem;
            st.push(st.postfixArray, elem, &st.TOP_array);
        }
        else if (n == 2)
            cout << "\nPopped elemt is " << st.pop(st.postfixArray, &st.TOP_array) << endl;
        else if (n == 3)
            cout << "TOP element is " << st.peek(st.postfixArray, &st.TOP_array) << endl;
        else if (n == 4)
        {
            if (st.isEmpty(&st.TOP_array))
                cout << "\nStack is empty -->\n";
            else
                cout << "\nStack is not Empty -->\n";
        }
        else if (n == 5)
        {
            string expression = "A+B/C+D*(E-F))^G";
            cout << "\nPostfix expression of " << expression << " is " << st.infixTOPostfix(expression) << endl;
        }
        else if (n == 6)
            st.display();
        else if (n == 0)
            break;
    }
    return 0;
};