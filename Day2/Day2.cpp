
// Day2.cpp : Defines the entry point for the application.
//

#include "Day2.h"

bool checkNums(const int num1, const int num2, bool previous_going_up, stringstream &error)
{
    bool safe = true;
    if (num1 == num2)
    {
        error << "num1 == num2" << "(" << num1 << "," << num2 << ")" << endl;
        safe = false;
    }

    if (previous_going_up)
    {
        if ((num2 - num1) > 3)
        {
            error << "(num2 - num1) > 3" << "(" << num2 << "," << num1 << ")" << endl;
            safe = false;
        }

        if (num1 > num2)
        {
            error << "num1 > num2" << "(" << num1 << "," << num2 << ")" << endl;
            safe = false;
        }
    }
    else
    {
        if ((num1 - num2) > 3)
        {
            error << "(num1 - num2) > 3" << "(" << num1 << "," << num2 << ")" << endl;
            safe = false;
        }

        if (num2 > num1)
        {
            error << "num2 > num1" << "(" << num2 << "," << num1 << ")" << endl;
            safe = false;
        }
    }

    return safe;
}

static bool CheckList(vector<int> list)
{
    bool safe = true;
    bool previous_going_up = list[0] < list[1];
    stringstream error;

    for (size_t i = 0; i < list.size(); i++)
    {
        int num1 = list[i];
        int num2 = 0;

        if (i == (list.size() - 1) && !safe)
        {
            num2 = list[i - 1];
        }
        else
        {
            if (i <= list.size() - 2)
            {
                num2 = list[i + 1];
            }
            else
            {
                break;
            }
        }

        safe = checkNums(num1, num2, previous_going_up, error);

        if (!safe)
        {
            break;
        }
    }

    return safe;
}

static bool IsSafe(vector<int> list)
{
    bool safe = true;
    vector<int> copy_list = list;


    if (list.size() >= 2)
    {
        safe = CheckList(list);

        if (!safe)
        {
            for (size_t i = 0; i <= list.size() - 1; i++)
            {
                list.erase(list.begin() + i);
                safe = CheckList(list);

                if (safe)
                {
                    break;
                }
                else
                {
                    list = copy_list;
                }
            }
        }
    }
    else
    {
        safe = false;
    }

    return safe;
}

int main()
{
    string line;
    ifstream file(R"(E:\AdventOfCode2024\RealData\Day2.txt)");

    int result = 0;

    while (getline(file, line))
    {
        stringstream line_stream(line);
        string number;
        const char seperator = ' ';
        vector<int> list;

        while (getline(line_stream, number, seperator))
        {
            list.push_back(stoi(number));
        }

        if (IsSafe(list))
            result++;
    }

    cout << result << endl;
}