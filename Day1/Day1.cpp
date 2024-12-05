// Day1.cpp : Defines the entry point for the application.
//

#include "Day1.h"

using namespace std;

vector<int> list_1;
vector<int> list_2;

int main()
{
    string line;

    ifstream file("D:\\AdventOfCode2024\\Day1\\Data.txt");

    while (getline(file, line))
    {
        bool first_number = true;
        string number = "";

        for (auto num : line)
        {
            if (isdigit(num))
            {
                number.push_back(num);
            }
            else
            {
                if (!number.empty())
                {
                    if (first_number)
                    {
                        list_1.push_back(stoi(number));
                        first_number = false;
                        number = "";
                    }
                }
            }
        }

        list_2.push_back(stoi(number));
        number = "";
    }

    file.close();

    sort(list_1.begin(), list_1.end());
    sort(list_2.begin(), list_2.end());

    int result = 0;

    for (size_t i = 0; i < list_1.size(); i++)
    {
        int num1;
        int num2;

        if (list_1[i] > list_2[i])
        {
            num1 = list_1[i];
            num2 = list_2[i];
        }
        else
        {
            num1 = list_2[i];
            num2 = list_1[i];
        }

        result += num1 - num2;
    }

    cout << result << endl;

    result = 0;

    for (auto num1: list_1)
    {
        int multiplier = 0;
        for (auto num2 : list_2)
        {
            if (num1 == num2)
            {
                multiplier++;
            }
        }
        result += num1 * multiplier;
    }

    cout << result << endl;
}

