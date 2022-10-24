//** Erika Salkeld, 16SEP2022, CS210 



#include<iostream>  // header file
using namespace std;

class Project1
{
private:
    int hours24;
    int minutes;
    int seconds; 
    int numberOfYears;
    bool am_pm;

  

    int CalcHour12(bool& am_pm)
    {
        if (hours24 <= 12)
        {
            am_pm = 0;
            return hours24;
        }
        else
        {
            am_pm = 1;
            return hours24 - 12;
        }
    };

    void AddHour(void)
    {
        hours24++;

        if (hours24 == 23)
        {
            hours24 = 0;
        }
    };

    void AddMinute(void)
    {
        minutes++;

        if (minutes == 59)
        {
            minutes = 0;
            AddHour();
        }
    };

    void AddSecond(void)
    {
        seconds++;

        if (seconds == 59)
        {
            seconds = 0;
            AddMinute();
        }
    };

    void DisplayTime(void)
    {
        //asterisks
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }

        //spacing
        cout << "    ";

        //asterisks
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }

        //spacing
        cout << endl;

        //Clock headers
        cout << "*      12-Hour Clock      *    *      24-Hour Clock      *" << endl;

        //12-hour
        cout << "*       ";
        //print hours
        if (CalcHour12(am_pm) < 10)
        {
            cout << "0" << CalcHour12(am_pm) << ":";
        }
        else
        {
            cout << CalcHour12(am_pm) << ":";
        }
        //print minutes
        if (minutes < 10)
        {
            cout << "0" << minutes << ":";
        }
        else
        {
            cout << minutes << ":";
        }
        //print seconds
        if (seconds < 10)
        {
            cout << "0" << seconds << "          *" << endl;
        }
        else
        {
            cout << seconds;
        }
        //print am/pm
        if (am_pm == 0)
        {
            cout << " AM" << "       *";
        }
        else
        {
            cout << " PM" << "       *";
        }

        //spacing
        cout << "    ";

        //24-hour
        cout << "*        ";
        //print hours
        if (hours24 < 10)
        {
            cout << "0" << hours24 << ":";
        }
        else
        {
            cout << hours24 << ":";
        }
        //print minutes
        if (minutes < 10)
        {
            cout << "0" << minutes << ":";
        }
        else
        {
            cout << minutes << ":";
        }
        //print seconds
        if (seconds < 10)
        {
            cout << "0" << seconds << "          *" << endl;
        }
        else
        {
            cout << seconds << "         *" << endl;
        }

        //asterisks
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }

        //spacing
        cout << "    ";

        //asterisks
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }
    };

    void DisplayMenu(void)
    {
        //asterisks
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }

        cout << endl;

        //option 1
        cout << "* 1 - Add One Hour        *" << endl;

        //option 2
        cout << "* 2 - Add One Minute      *" << endl;

        //option 3
        cout << "* 3 - Add One Second      *" << endl;

        //option 4
        cout << "* 4 - Exit Program        *" << endl;

        //stars
        for (int i = 0; i < 27; i++)
        {
            cout << "*";
        }
    };

public:
    void ClearScreen(void) // object_name.ClearScreen()
    {
        system("CLS");
    };

    void Display(void) // object_name.Display()
    {
        DisplayTime();
        cout << endl;
        DisplayMenu();
    };

    bool ReadUserInput(void) // object_name.ReadUserInput()
    {
        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            AddHour();
            return false;
            break;
        case 2:
            AddMinute();
            return false;
            break;
        case 3:
            AddSecond();
            return false;
            break;
        case 4:
            return true;
            break;
        }
    };

    void Init(int hour, int minute, int second)
    {
        hours24 = hour;
        minutes = minute;
        seconds = second;
    };
};

int main(void)
{
    Project1 project1; // Tell the compiler to build our object based on the class recipe.

    project1.Init(8, 3, 15); // To access a function in the object, we use the object_name.method_name

    while (1)
    {
        project1.ClearScreen(); // Call the functions in the object
        project1.Display();
        cout << endl;
        if (project1.ReadUserInput())
            break;         // Exit main()
    }
}