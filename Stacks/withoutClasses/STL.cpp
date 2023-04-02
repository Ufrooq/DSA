#include <iostream>
#include <stack>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string str)
{
    stack<char> st;
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] == 'a' && str[i] == 'z') || (str[i] == 'A' && str[i] == 'Z'))
            result += str[i];
        else if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == ')')
        {
            while (!st.empty() && str.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
        }
    }
}
int main(){

};