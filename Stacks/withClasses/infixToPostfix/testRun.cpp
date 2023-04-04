#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    char *array;
    int size;
    stack(int x)
    {
        size = x;
        array = new char[size];
        top = -1;
    }

    void push(char x)
    {
        array[++top] = x;
    }
    char pop()
    {
        return array[top--];
    }
    bool is_empty()
    {
        return top == -1;
    }

    int precedence(char x)
    {
        if (x == '(' || x == ')')
        {
            return 3;
        }
        else if (x == '/' || x == '*')
        {
            return 2;
        }
        else if (x == '+' || x == '-')
        {
            return 1;
        }
    }
    // void display()
    // {
    //     for (int i = 0; i <= top; i++)
    //     {
    //         cout << array[i] << " ";
    //     }

    //     cout << "\n";
    // }
    string postfix(char x)
    {
        string temp = "";
        if (x == '(' || top == -1)
        {
            // cout << "first if\n";
            push(x);
        }
        else
        {
            if (x == ')')
            {
                // cout << "second if\n";
                while (array[top] != '(')
                {

                    // cout << "third if ki else ka loop ka bhosda\n";
                    string a;
                    a = pop();
                    temp = temp + a;
                }
                pop();
            }
            else
            {
                if (array[top] == '(')
                {
                    // cout << "fourth if\n";
                    push(x);
                }
                else
                {
                    if (precedence(x) > precedence(array[top]))
                    {
                        // cout << "fifth if\n";
                        push(x);
                    }
                    else if (precedence(x) <= precedence(array[top]))
                    {
                        // cout << "sixth if else \n";
                        while (precedence(x) <= precedence(array[top]))
                        {
                            if (array[top] == '(')
                            {
                                break;
                            }

                            // cout << "loop working in sixth if-else\n";
                            string a;
                            a = pop();
                            temp = temp + a;
                        }
                        push(x);
                    }
                }
            }
        }
        return temp;
    }
};
int main()
{
    string a;
    cout << "enter string to convert to prefix" << endl;
    cin >> a;
    stack s1(a.size());
    string b = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '(' || a[i] == ')' || a[i] == '/' || a[i] == '*' || a[i] == '+' || a[i] == '-')
        {
            string ans = s1.postfix(a[i]);
            b = b + ans;
        }
        else
        {
            b = b + a[i];
        }
    }
    // cout << s1.top << endl;
    if (s1.top > -1)
    {
        while (s1.top != -1)
        {
            b = b + s1.pop();
        }
    }

    cout << "INFIX STRING : " << a << endl;
    cout << "POSTFIX STRING : " << b << endl;
}