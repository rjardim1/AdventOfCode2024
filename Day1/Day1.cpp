// Day1.cpp : Defines the entry point for the application.
//

#include "Day1.h"

vector<int> list_1;
vector<int> list_2;

int main()
{
    const string source_file_str = ReadFile(eDay1, eRealData);

    regex pair_regex(R"(([0-9]+)   ([0-9]+))");

    regex_matches_type matches = GetRegexMatches(source_file_str, pair_regex);

    if (matches.size() >= 3)
    {
        for (const auto& match : matches)
        {
            string num1 = match.at(1);
            string num2 = match.at(2);

            if (StringContainsOnlyNumbers(num1) && StringContainsOnlyNumbers(num2))
            {
                list_1.push_back(stoi(num1));
                list_2.push_back(stoi(num2));
            }
        }
    }

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

    cout << "Part 1: " << result << endl;

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

    cout << "Part 2: " << result << endl;
}

