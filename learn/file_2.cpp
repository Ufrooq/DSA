#include <iostream>
using namespace std;

class stack
{
private:
    int stk[10];
    int top;

public:
    stack()
    {
        top = -1;
        cout << "Constructor " << endl;
        while (10 - top > 1)
        {
            stk[++top] = 0;
        }
        cout << top << endl;
    }

    void push(int a)
    {
        if (top == 9)
        {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        stk[top] = a;
        cout << "Element has been  pushed to stack." << endl;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Popped element is: " << stk[top] << endl;
        top--;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "The stack is: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << stk[i] << " ";
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (top == 9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void count()
    {

        cout << "the total elements in the stack are " << (top + 1) << endl;
    }

    void changeVal(int pos, int val)
    {
        if (pos < 0 || pos > top)
        {
            cout << "Invalid position." << endl;
            return;
        }
        stk[pos] = val;
        cout << "Item has been changed at position " << pos << endl;
    }

    int topPos(int pos)
    {
        if (pos < 0 || pos > top)
        {
            cout << "Invalid position." << endl;
            return 0;
        }
        else
        {
            cout << "Value at position " << pos << " is " << this->stk[pos] << endl;
        }
    }
};

int main()
{
    stack s;
    int x, y, pos, val;
    char choice;
    do
    {
        cout << endl;
        cout << "1. Push element to stack" << endl;
        cout << "2. Pop element from stack" << endl;
        cout << "3. Display stack" << endl;
        cout << "4. Check if stack is empty" << endl;
        cout << "5. Check if stack is full" << endl;
        cout << "6. Change value at specific position" << endl;
        cout << "7. Peek element from stack" << endl;
        cout << "8. Count number of elements in stack" << endl;
        cout << "9. Clear screen" << endl;
        cout << "10. Exit" << endl;

        cout << "Enter your choice (1-10): ";
        cin >> x;

        switch (x)
        {
        case 1:
            cout << "Enter the element you want to insert: ";
            cin >> y;
            s.push(y);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            if (s.isEmpty())
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                cout << "Stack is not empty." << endl;
            }
            break;
        case 5:
            if (s.isFull())
            {
                cout << "stack is full." << endl;
            }
            else
            {
                cout << "stack is not full" << endl;
            }
            break;
        case 6:
            cout << "change value function has been called " << endl;
            cout << "enter the position you want to change: " << endl;
            cin >> pos;
            cout << "enter the value of item you want to change: " << endl;
            cin >> val;
            s.changeVal(pos, val);
            break;
        case 7:
            cout << "enter the item you wanna peek: " << endl;
            cin >> pos;
            cout << "peek function called" << endl;
            s.topPos(pos);
            break;
        case 8:
            s.count();
            break;
        case 9:
            system("cls");
            cout << "Your screen has been cleared." << endl;
            break;

        case 10:
            exit(0);
            break;

        default:
            cout << "Invalid choice." << endl;
        }

        cout << "Do you want to continue or exit (Y/N)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
};