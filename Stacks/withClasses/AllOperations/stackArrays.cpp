#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    char *strArray;
    int top;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        strArray = new char[size];
        top = -1;
    }

    void push()
    {
        if (size - top > 1)
        {
            cout << "Enter element : ";
            int element;
            cin >> element;
            arr[++top] = element;
        }
        else
            cout << "Stack is already full YOU stupid :)" << endl;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "No elements are present for now :|||" << endl;
            return 0;
        }
        else
        {
            int a = arr[top];
            top--;
            return a;
        }
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "No elements are present :|||";
            return 0;
        }
        else
        {
            cout << "\nTop element is : " << arr[top] << endl;
            return arr[top];
        }
    }

    char peekChar()
    {
        if (top == -1)
            return '\0';
        else
            return strArray[top];
    }

    bool
    checkPalindrome()
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (pop() != arr[i])
            {
                return false;
            }
        }
        return true;
    }

    void pushChar(char cc)
    {
        if (size - top > 1)
            strArray[++top] = cc;
        else
            return;
    }

    char popChar()
    {
        if (top == -1)
        {
            cout << "No elements are present for now :|||" << endl;
            return '\0';
        }
        else
        {
            char a = strArray[top--];
            return a;
        }
    }

    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }

    bool checkBraces(string exp)
    {
        int priority = 0;
        int incoming_proiority = 0;
        for (int i = 0; i < exp.length(); i++)
        {
            // // checking priority
            // if (exp[i] == '{')
            //     incoming_proiority = 3;
            // else if (exp[i] == '[')
            //     incoming_proiority = 2;
            // else if (exp[i] == '(')
            //     incoming_proiority = 1;
            // //--------
            // if (top = -1)
            //     priority = incoming_proiority;

            // if (incoming_proiority <= priority)
            // {
            //     cout << "\nif runned ---\n";
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                pushChar(exp[i]);

            else if (exp[i] == ')')
            {
                if (peekChar() == '(')
                    popChar();
                else
                    return false;
            }
            else if (exp[i] == '}')
            {
                if (peekChar() == '{')
                    popChar();
                else
                    return false;
            }
            else if (exp[i] == ']')
            {
                if (peekChar() == '[')
                    popChar();
                else
                    return false;
            }
            else
                return false;

            priority = incoming_proiority;
        }
        // else
        // {
        //     cout << "\nelse runned\n";
        //     return false;
        // }
        // }
        return isEmpty();
    }
};

string reverseString()
{
    cout << "Enter a string : ";
    string word;
    cin >> word;
    Stack st(word.length());
    for (int i = 0; i < word.length(); i++)
        st.pushChar(word[i]);

    string reversedString = "";
    while (st.top != -1)
        reversedString += st.popChar();

    // here I am returning the reversed string
    return reversedString;
}

int main()
{
    Stack st(10);
    int n;
    while (true)
    {
        cout << "\nPress 1 to push element -->" << endl;
        cout << "Press 2 to pop element -->" << endl;
        cout << "Press 3 to display element -->" << endl;
        cout << "Press 4 to check for Palindrom -->" << endl;
        cout << "Press 5 to REverse a String -->" << endl;
        cout << "Press 6 to check valid Expression -->" << endl;
        cout << "Press 7 to check isEmpty() -->" << endl;
        cout << "Press 0 to exit -->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
            st.push();
        else if (n == 2)
            cout << "\nPopped elemt is " << st.pop() << endl;
        else if (n == 3)
            st.peek();
        else if (n == 4)
        {
            string x = st.checkPalindrome() ? "\nPalindrome" : "\nNot a Palindrome";
            cout << x << endl;
        }
        else if (n == 5)
            cout << "Reverse of word is " << reverseString() << endl;
        else if (n == 6)
        {
            string exp = "{a[(bc)s]}";
            string x = st.checkBraces(exp) ? "\nValid Expression" : "\nIn-Valid Expression";
            cout << x << endl;
        }
        else if (n == 7)
        {
            bool x = st.isEmpty();
            cout << x;
        }
        else if (n == 0)
            break;
    }
    return 0;
};