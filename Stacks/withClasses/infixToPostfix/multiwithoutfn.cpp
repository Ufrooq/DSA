#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    // arrays ---->
    char *postfixArray;
    char *paranthesisArray;
    int *eval_array;
    // tops ---->
    int TOP_array;
    int TOP_paranthesis;
    int TOP_eval;
    // constructor ---->
    Stack(int size)
    {
        this->size = size;
        postfixArray = new char[size];
        paranthesisArray = new char[size];
        eval_array = new int[size];
        TOP_array = -1;
        TOP_paranthesis = -1;
        TOP_eval = -1;
    }

    // Peek functions ------------>
    char peek() { return (TOP_array == -1) ? '\0' : postfixArray[TOP_array]; }
    char peekParan() { return (TOP_paranthesis == -1) ? '\0' : paranthesisArray[TOP_paranthesis]; }
    int peekInt() { return (TOP_eval == -1) ? '\0' : eval_array[TOP_eval]; }

    // Pop functions ------------>
    char pop() { return (TOP_array == -1) ? '\0' : postfixArray[(TOP_array)--]; }
    char popParan() { return (TOP_paranthesis == -1) ? '\0' : paranthesisArray[(TOP_paranthesis)--]; }
    int popInt() { return (TOP_eval == -1) ? '\0' : eval_array[(TOP_eval)--]; }

    // isEmpty functions ------------>
    bool isEmpty() { return TOP_array == -1 ? true : false; }
    bool isEmptyParan() { return TOP_paranthesis == -1 ? true : false; }
    bool isEmptyInt() { return TOP_eval == -1 ? true : false; }

    // Push functions ----------------->
    void push(char element)
    {
        if (size - TOP_array > 1)
            postfixArray[++TOP_array] = element;
        else
            cout << "\nStack is FUll ----> " << endl;
    }

    void pushParan(char element)
    {
        if (size - TOP_paranthesis > 1)
            paranthesisArray[++TOP_paranthesis] = element;
        else
            cout << "\nStack is FUll ----> " << endl;
    }
    void pushInt(int element)
    {
        if (size - TOP_eval > 1)
            eval_array[++TOP_eval] = element;
        else
            cout << "\nStack is FUll ----> " << endl;
    }

    // Precedence functions ------------------>
    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '-' || c == '+')
            return 1;
        else
            return -1;
    }
    int precedence_braces(char c)
    {
        if (c == '{')
            return 3;
        else if (c == '[')
            return 2;
        else if (c == '(')
            return 1;
        else
            return -1;
    }

    string infixTOPostfix(string str)
    {
        string postfixExp;
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                postfixExp += str[i];

            else if ((str[i] == '(' || str[i] == '{' || str[i] == '[') && TOP_paranthesis == -1)
            {
                pushParan(str[i]);
                push(str[i]);
            }

            else if ((str[i] == '(' || str[i] == '{' || str[i] == '[') && TOP_paranthesis != -1)
            {
                if (precedence_braces(str[i]) < precedence_braces(peekParan()))
                {
                    pushParan(str[i]);
                    push(str[i]);
                }
                else
                    return "\nExpression was invalid -->\n";
            }

            else if (str[i] == '}')
            {
                if (peekParan() == '{')
                {
                    popParan();
                    while (!isEmpty() && peek() != '{')
                    {
                        postfixExp += peek();
                        pop();
                    }
                    // to pop the opening bracket
                    if (!isEmpty())
                        pop();
                }
                else
                    return "\nExpression was invalid -->\n";
            }
            else if (str[i] == ']')
            {
                if (peekParan() == '[')
                {
                    popParan();
                    while (!isEmpty() && peek() != '[')
                    {
                        postfixExp += peek();
                        pop();
                    }
                    // to pop the opening bracket
                    if (!isEmpty())
                        pop();
                }
                else
                    return "\nExpression was invalid -->\n";
            }
            else if (str[i] == ')')
            {
                if (peekParan() == '(')
                {
                    popParan();
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
                    return "\nExpression was invalid -->\n";
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
        return isEmptyParan() ? postfixExp : "\nExpression was invalid -->\n";
    }

    int evaluation(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            int cv = str[i] - '0';
            if (cv >= 1 && cv <= 9)
                pushInt(cv);
            else
            {
                int a = popInt();
                int b = popInt();
                if (str[i] == '+')
                    pushInt(a + b);
                else if (str[i] == '-')
                    pushInt(a > b ? a - b : b - a);
                else if (str[i] == '*')
                    pushInt(a * b);
                else if (str[i] == '/')
                    pushInt(a > b ? a / b : b / a);
            }
        }
        return peekInt();
    }

    void
    display()
    {
        for (int i = 0; i <= TOP_array; i++)
        {
            cout << postfixArray[i] << " ";
        }
    }
};

int main()
{
    Stack st(20);
    int n;
    while (true)
    {
        // cout << "\nPress 1 to push element -->" << endl;
        // cout << "Press 2 to pop element -->" << endl;
        // cout << "Press 3 to Peek element -->" << endl;
        // cout << "Press 4 for isEmpty() -->" << endl;
        cout << "\nPress 1 to convert Infix to Postfix -->" << endl;
        cout << "Press 2 to evaluate Postfix -->" << endl;
        cout << "Press 0 to exit -->" << endl;
        cout << "Enter : ";
        cin >> n;
        // if (n == 1)
        // {
        //     char elem;
        //     cout << "Enter Element : ";
        //     cin >> elem;
        //     st.push(elem);
        // }
        // else if (n == 2)
        //     cout << "\nPopped elemt is " << st.pop() << endl;
        // else if (n == 3)
        //     cout << "TOP element is " << st.peek() << endl;
        // else if (n == 4)
        // {
        //     if (st.isEmpty())
        //         cout << "\nStack is empty -->\n";
        //     else
        //         cout << "\nStack is not Empty -->\n";
        // }
        if (n == 1)
        {
            string expression = "A+B/C+D*{([E-F])}^G";
            cout << "\nPostfix expression of " << expression << " is " << st.infixTOPostfix(expression) << endl;
        }
        else if (n == 2)
        {
            string expression = "6523+8*+3+*";
            cout << "\nPost fix after evaluation is : " << st.evaluation(expression) << endl;
        }
        else if (n == 6)
            st.display();
        else if (n == 0)
            break;
    }
    return 0;
};