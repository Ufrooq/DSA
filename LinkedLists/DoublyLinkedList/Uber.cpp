#include <iostream>
using namespace std;

struct Ride
{
    int time;
    string carName;
    Ride *next = NULL;
};

struct Car
{
    Car *prev = NULL;
    int reg;
    string driver;
    Car *next = NULL;
    Ride *rideNext = NULL;
};

Car *head = NULL;
Car *tail = NULL;

// -----------------------------------

// diplay Cars metod :
void displayCars()
{
    Car *prnt = head;
    if (prnt == NULL)
        cout << "No REcords Found !!  ";
    else
    {
        while (prnt != NULL)
        {
            cout << "( " << prnt->reg << " , " << prnt->driver << " )"
                 << endl;
            prnt = prnt->next;
        }
    }
}

// Display Rides  --------
void displayRides(Ride *ridehead)
{
    Ride *prnt = ridehead;
    if (prnt == NULL)
        cout << "No REcords Found !!  ";
    else
    {
        while (prnt != NULL)
        {
            cout << "( " << prnt->time << " , " << prnt->carName << " )"
                 << endl;
            prnt = prnt->next;
        }
    }
}

// insert Ride metod
void insertRide(Car *current)
{
    Ride *rideDta = new Ride;
    cout << "\nEnter Ride Time : ";
    cin >> rideDta->time;
    cout << "Enter Car Name : ";
    cin >> rideDta->carName;

    // linkin ----
    if (current->rideNext == NULL)
        current->rideNext = rideDta;
    else
    {
        rideDta->next = current->rideNext;
        current->rideNext = rideDta;
    }
}

// Insert Car metod  ----------------------------
void insertCar()
{
    Car *current = new Car;
    cout << "\nEnter reg : ";
    cin >> current->reg;
    cout << "Enter driver : ";
    cin >> current->driver;
    if (tail == NULL)
        head = tail = current;
    else
    {
        tail->next = current;
        current->prev = tail;
        tail = tail->next;
    }
    int n;
    while (true)
    {
        cout << "\nRide Menu ----------------------------------->" << endl;
        cout << "Press 1 to Add Rider Details : " << endl;
        cout << "Press 9 to display : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cout << "Enter :";
        cin >> n;
        if (n == 1)
            insertRide(current);
        else if (n == 9)
            displayRides(current->rideNext);
        else if (n == 0)
            break;
    }
}

void get_Car_Record_by_reg()
{
    cout << "Enter Reg Number of Car : ";
    bool valid = false;
    Car *ctrl = head;
    {
        while (ctrl != NULL)
        {
            if (ctrl->reg == ctrl->reg)
            {
                cout << "\nCar Found --->\nDetails are below : " << endl;
                cout << "Driver : " << ctrl->driver << endl;
                cout << "Car Reg # : " << ctrl->driver << endl;
                if (ctrl->next == NULL)
                    cout << "No Rides are present for Now -->" << endl;
                else
                    displayRides(ctrl->rideNext);
            }
            ctrl = ctrl->next;
        }
    }
    cout << valid ? "" : "\nCar not Found ---->\n";
}

int main()
{
    int n;
    while (true)
    {
        cout << "\nCar Menu ----------------------------------->" << endl;
        cout << "Press 1 to insert END : " << endl;
        cout << "Press 2 to get Card details by Reg # : " << endl;
        cout << "Press 3 to display Cars : " << endl;
        cout << "Press 0 to exit() : " << endl;
        cin >> n;
        if (n == 1)
            insertCar();
        else if (n == 2)
            get_Car_Record_by_reg();
        else if (n == 3)
            displayCars();
        else if (n == 0)
            break;
    }
    return 0;
};