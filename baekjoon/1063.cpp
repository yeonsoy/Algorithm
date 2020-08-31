#include <iostream>
#include <string>
using namespace std;

// 킹

string king, pin;

// A2~H2
// A1B1C1D1E1F1G1H1

bool isSamePos(char a, char b)
{
    return (a == b);
}

bool isCanMove(char a)
{
    return ('1' <= a && a <= '8') || ('A' <= a && a <= 'H');
}

void move(string input)
{
    if (input == "R")
    {
        if (isCanMove(king[0] + 1)) king[0]++;

        if (king == pin)
        {
            if (isCanMove(pin[0] + 1))
                pin[0]++;
            else
                king[0]--;
        }
    }

    else if (input == "L")
    {
        if (isCanMove(king[0] - 1)) king[0] --;

        if (king == pin)
        {
            if (isCanMove(pin[0] - 1))
                pin[0]--;
            else
                king[0]++;
        }
    }

    else if (input == "B")
    {
        if (isCanMove(king[1] - 1)) king[1]--;

        if (king == pin)
        {
            if (isCanMove(pin[1] - 1))
                pin[1]--;
            else
                king[1]++;
        }
    }

    else if (input == "T")
    {
        if (isCanMove(king[1] + 1)) king[1]++;

        if (king == pin)
        {
            if (isCanMove(pin[1] + 1))
                pin[1]++;
            else
                king[1]--;
        }
    }

    else if (input == "RT")
    {
        if (isCanMove(king[0] + 1) && isCanMove(king[1] + 1))
        {
            king[0]++;
            king[1]++;
        }

        if (king == pin)
        {
            if (isCanMove(pin[0] + 1) && isCanMove(pin[1] + 1))
            {
                pin[0]++;
                pin[1]++;
            }
            else
            {
                king[0]--;
                king[1]--;
            }
        }
    }

    else if (input == "LT")
    {
        if (isCanMove(king[0] - 1) && isCanMove(king[1] + 1))
        {
            king[0]--;
            king[1]++;
        }

        if (king == pin)
        {
            if (isCanMove(pin[0] - 1) && isCanMove(pin[1] + 1))
            {
                pin[0]--;
                pin[1]++;
            }
            else
            {
                king[0]++;
                king[1]--;
            }
        }
    }

    else if (input == "RB")
    {
        if (isCanMove(king[0] + 1) && isCanMove(king[1] - 1))
        {
            king[0]++;
            king[1]--;
        }

        if (king == pin)
        {
            if (isCanMove(pin[0] + 1) && isCanMove(pin[1] - 1))
            {
                pin[0]++;
                pin[1]--;
            }
            else
            {
                king[0]--;
                king[1]++;
            }
        }
    }

    else if (input == "LB")
    {
        if (isCanMove(king[0] - 1) && isCanMove(king[1] - 1))
        {
            king[0]--;
            king[1]--;
        }

        if (king == pin)
        {
            if (isCanMove(pin[0] - 1) && isCanMove(pin[1] - 1))
            {
                pin[0]--;
                pin[1]--;
            }
            else
            {
                king[0]++;
                king[1]++;
            }
        }
    }
}

int main()
{
    int num;

    cin >> king >> pin >> num;

    for (int i = 0; i < num; i++)
    {
        string input;
        cin >> input;

        move(input);
    }

    cout << king << endl;
    cout << pin << endl;


    return 0;
}
