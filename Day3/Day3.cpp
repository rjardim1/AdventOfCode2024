
// Day3.cpp : Defines the entry point for the application.
//

#include "Day3.h"

int main()
{
    int result = 0;

    const string source_file_str = ReadFile(EDay::eDay3, EDataType::eTestData);

    regex mul_regex(R"(mul\(([0-9]+),([0-9]+)\))");

    regex_matches_type mul_regex_matches = GetRegexMatches(source_file_str, mul_regex);

    if (!mul_regex_matches.empty())
    {
        for (const auto &match : mul_regex_matches)
        {
            if (match.size() >= 3)
            {
                string num1 = match.at(1);
                string num2 = match.at(2);

                if (StringContainsOnlyNumbers(num1) && StringContainsOnlyNumbers(num2))
                {
                    result += stoi(num1) * stoi(num2);
                }
            }
        }
    }

    cout << "Part 1: " << result << endl;
    result = 0;

    regex mul_do_regex(R"(mul\((\d{1,3}),(\d{1,3})\)|(d)(o)(?:n't)?\(\))");

    regex_matches_type mul_do_regex_matches = GetRegexMatches(source_file_str, mul_do_regex);
    bool multiply = true;

    if (!mul_do_regex_matches.empty())
    {
        for (const auto& match : mul_do_regex_matches)
        {
            if (match.at(0) == "don't()")
            {
                multiply = false;
                continue;
            }

            if (match.at(0) == "do()")
            {
                multiply = true;
                continue;
            }

            if (multiply)
            {
                string num1 = match.at(1);
                string num2 = match.at(2);

                if (StringContainsOnlyNumbers(num1) && StringContainsOnlyNumbers(num2))
                {
                    result += stoi(num1) * stoi(num2);
                }
            }
        }
    }

    cout << "Part 2: " << result << endl;
}

//(?<=do\(\))mul\(([0-9]+),([0-9]+)\)