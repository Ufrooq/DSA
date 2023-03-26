#include <iostream>
using namespace std;

struct Data
{
    int id;
    Data *next = NULL;
};
Data *head = NULL;
Data *tail = NULL;

void swap(int x, int y)
{
    Data *px = NULL;
    Data *py = NULL;
    Data *cx = head;
    Data *cy = head;
    Data *temp_last = NULL;
    if (head == NULL)
        cout << "No Records are present for NOW !!";
    else
    {

        // Traversing through Linked list to get cx px :
        while (cx->id != x)
        {
            px = cx;
            cx = cx->next;
        }
        //--------------------------------
        // Traversing through Linked list to get cy py :
        while (cy->id != y)
        {
            py = cy;
            cy = cy->next;
        }
        temp_last = cy->next;

        cout << "px is : " << px->id << endl;
        cout << "cx is : " << cx->id << endl;
        cout << "py is : " << py->id << endl;
        cout << "cy is : " << cy->id << endl;
        // Swapping (cx with cy) if (cy is before cx) in Linked List ----->
        Data *temp_exchange = cy;
        while (temp_exchange->next != NULL)
        {
            if (temp_exchange->id == cx->id)
            {
                Data *tempC = cx;
                cx = cy;
                cy = tempC;
                Data *tempP = px;
                px = py;
                py = tempP;
                temp_last = cx->next;
            }
            temp_exchange = temp_exchange->next;
        }

        cout << "px is : " << px->id << endl;
        cout << "cx is : " << cx->id << endl;
        cout << "py is : " << py->id << endl;
        cout << "cy is : " << cy->id << endl;

        // Swaping firt and 2nd nodes -------------->
        if ((cx->id == head->id) && (cx->next->id == cy->id))
        {
            cx->next = temp_last;
            cy->next = cx;
            head = cy;
        }

        // Swaping firt and any node before last -------------->
        else if ((cx->id == head->id) && (cy->id != tail->id))
        {
            cy->next = cx->next;
            py->next = cx;
            cx->next = temp_last;
            head = cy;
        }

        // Swaping firt and last nodes -------------->
        else if ((cx->id == head->id) && (cy->id == tail->id))
        {
            cy->next = cx->next;
            py->next = cx;
            cx->next = NULL;
            head = cy;
            tail = cx;
        }

        // swappingg two consecutive nodes between first and last nodes --->
        else if (cx->next->id == cy->id)
        {
            px->next = cy;
            cy->next = cx;
            cx->next = temp_last;
        }

        // Swaping Last and any node After First -------------->
        else if ((cx->id != head->id) && (cy->id == tail->id))
        {
            cy->next = py;
            py->next = cx;
            px->next = cy;
            cx->next = NULL;
        }

        // Swaping Last and 2ndLast nodes -------------->
        else if ((cx->id == py->id) && (cy->id == tail->id))
        {
            px->next = cy;
            cy->next = cx;
            cx->next = NULL;
        }
        // Swaping two non-consecutive nodes between first and last nodes --->
        else
        {
            cout << "current --------------" << endl;
            px->next = cy;
            cy->next = cx->next;
            cx->next = temp_last;
            py->next = cx;
        }
    }
}
void reverseNodes()
{
    Data *previous = head;
    Data *temp_last = tail;
    Data *sts = NULL;
    while (head->next != NULL)
    {
        previous = head;
        while (previous->next != temp_last)
        {
            previous = previous->next;
        }
        temp_last->next = head;
        previous->next = NULL;
        if (sts == NULL)
            sts = temp_last;
        else
        {
            sts->next = temp_last;
            sts = sts->next;
        }
        temp_last = previous;
    }
    Data *swap_h_t = NULL;
    swap_h_t = tail;
    tail = head;
    head = swap_h_t;
}

void swapNodesReccursivly(Data *p)
{
    Data *sts = NULL;
    if (p == NULL)
        return;
    else
    {
        Data *pr = p;
        swapNodesReccursivly(p->next);
        // After call
        p->next = head;
        if (sts == NULL)
            sts = head;
        else
        {
            sts->next = p;
            sts->next = sts;
        }
        p = pr;
    }
}

void insertEnd()
{
    Data *current = new Data;
    cout << "Enter : ";
    cin >> current->id;
    if (tail == NULL)
        head = tail = current;
    else
    {
        tail->next = current;
        tail = current;
    }
}
void display()
{
    Data *prnt = head;
    while (prnt != NULL)
    {
        cout << prnt->id << "  ";
        prnt = prnt->next;
    }
}

void displayReverse()
{
    Data *previous = head;
    Data *ford = tail;
    while (ford != head)
    {
        previous = head;
        while (previous->next != ford)
        {
            previous = previous->next;
        }
        cout << ford->id << "  ";
        ford = previous;
    }
    cout << head->id;
}

int main()
{
    while (true)
    {
        cout << "\nPress 1 to insert End -->" << endl;
        cout << "Press 2 to display -->" << endl;
        cout << "Press 3 to swap -->" << endl;
        cout << "\nEnter : ";
        int n;
        cin >> n;
        if (n == 1)
            insertEnd();
        else if (n == 2)
            display();
        else if (n == 3)
        {
            cout << "Enter indexs to swap : " << endl;
            int a, b;
            cout << "Enter x : ";
            cin >> a;
            cout << "\nEnter y : ";
            cin >> b;
            swap(a, b);
        }
        else if (n == 4)
            displayReverse();
        else if (n == 5)
            reverseNodes();
        else if (n == 6)
        {
            swapNodesReccursivly(head);
            Data *swap_h_t = NULL;
            swap_h_t = tail;
            tail = head;
            head = swap_h_t;
        }
        else if (n == 9)
        {
            cout << "\nExit ! ";
            break;
        }
    }
    return 0;
};