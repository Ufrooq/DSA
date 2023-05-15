#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    char *arr;
    int top;
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new char[size];
    }

    bool isEmpty()
    {
        return (top == -1) ? true : false;
    }

    bool isFull()
    {
        return (size - top > 1) ? false : true;
    }

    char peek()
    {
        return arr[top];
    }

    void pop()
    {
        if (isEmpty())
            cout << "Array is empty !" << endl;
        else
        {
            top--;
        }
    }

    void push(char val)
    {
        if (isFull())
            cout << "Stack is full !" << endl;
        else
        {
            arr[++top] = val;
        }
    }

    bool isPalindrome(string val)
    {
        string reversed = "";
        for (int i = 0; i < val.size(); i++)
        {
            push(val[i]);
        }

        while (!isEmpty())
        {
            reversed += peek();
            pop();
        }
        return reversed == val;
    }

    void display()
    {
        cout << "Stack : ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void reverseDisplay()
    {
        if (isEmpty())
        {
            return;
        }
        cout << peek() << " ";
        pop();
        reverseDisplay();
    }
};

int main()
{
    Stack st(5);
    int n;
    while (true)
    {
        cout << "\nPress 1 to push element -->" << endl;
        cout << "Press 2 to pop element -->" << endl;
        cout << "Press 3 to display element -->" << endl;
        cout << "Press 4 isPalandrome -->" << endl;
        cout << "Press 5 to reverse  -->" << endl;
        cout << "Press 0 to exit -->" << endl;
        cout << "Enter : ";
        cin >> n;
        if (n == 1)
        {
            cout << "\nEnter value : ";
            char val;
            cin >> val;
            st.push(val);
        }
        else if (n == 2)
            st.pop();
        else if (n == 3)
            st.display();
        else if (n == 4)
        {
            cout << "Enter a number : ";
            string str;
            cin >> str;
            string x = st.isPalindrome(str) ? "\nPalindrome" : "\nNot a Palindrome";
            cout << x << endl;
        }
        else if (n == 5)
            st.reverseDisplay();
    };
    return 0;
};